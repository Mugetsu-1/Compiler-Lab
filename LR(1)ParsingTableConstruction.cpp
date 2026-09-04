#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

struct Production { char lhs; string rhs; };
vector<Production> gram;

struct Item {
    int r, dot;
    char la;
    bool operator<(const Item& o) const {
        if (r != o.r) return r < o.r;
        if (dot != o.dot) return dot < o.dot;
        return la < o.la;
    }
};
typedef set<Item> State;

set<char> getFirst(char c, char la) {
    set<char> res;
    if (c == '\0') { res.insert(la); return res; }
    if (!isupper(c)) { res.insert(c); return res; }
    for (auto &p : gram) if (p.lhs == c) {
        if (!isupper(p.rhs[0])) res.insert(p.rhs[0]);
        else for (char x : getFirst(p.rhs[0], la)) res.insert(x);
    }
    return res;
}

State CLOSURE(State I) {
    State cl = I; bool add = true;
    while (add) {
        add = false; State tmp = cl;
        for (auto it : tmp) {
            string r = gram[it.r].rhs;
            if (it.dot < (int)r.size()) {
                char B = r[it.dot];
                char nxt = (it.dot + 1 < (int)r.size()) ? r[it.dot + 1] : '\0';
                set<char> las = getFirst(nxt, it.la);
                for (size_t i = 0; i < gram.size(); i++) if (gram[i].lhs == B) {
                    for (char b : las) if (cl.insert({(int)i, 0, b}).second) add = true;
                }
            }
        }
    }
    return cl;
}

State GOTO(State I, char X) {
    State J;
    for (auto it : I) if (it.dot < (int)gram[it.r].rhs.size() && gram[it.r].rhs[it.dot] == X)
        J.insert({it.r, it.dot + 1, it.la});
    return CLOSURE(J);
}

int main() {
    int n; cout << "Enter number of rules: "; cin >> n;
    cout << "Enter rules (e.g., S CC or C cC or C d):\n";
    gram.push_back({'Z', ""}); // Augmented rule Z -> Start
    set<char> term, nonterm;
    for (int i = 0; i < n; i++) {
        char h; string b; cin >> h >> b;
        if (i == 0) gram[0].rhs = string(1, h);
        gram.push_back({h, b});
        nonterm.insert(h);
        for (char c : b) if (!isupper(c)) term.insert(c); else nonterm.insert(c);
    }
    term.insert('$');

    vector<State> C = { CLOSURE({{(int)0, 0, '$'}}) };
    map<pair<int, char>, int> gotoTbl;
    map<pair<int, char>, string> actTbl;

    string syms = "";
    for (char c : nonterm) syms += c;
    for (char c : term) if (c != '$') syms += c;

    for (size_t i = 0; i < C.size(); i++) {
        for (char X : syms) {
            State nxt = GOTO(C[i], X);
            if (!nxt.empty()) {
                int id = -1;
                for (size_t j = 0; j < C.size(); j++) if (C[j] == nxt) id = j;
                if (id == -1) { C.push_back(nxt); id = C.size() - 1; }
                gotoTbl[{i, X}] = id;
            }
        }
    }

    cout << "\nLR(1) Items (" << C.size() << " States):\n";
    for (size_t i = 0; i < C.size(); i++) {
        cout << "I" << i << ":\n";
        for (auto it : C[i]) {
            string r = gram[it.r].rhs;
            cout << "  [" << gram[it.r].lhs << " -> " << r.substr(0, it.dot) << "." << r.substr(it.dot) << ", " << it.la << "]\n";
        }
    }

    for (size_t i = 0; i < C.size(); i++) {
        for (auto it : C[i]) {
            string r = gram[it.r].rhs;
            if (it.dot == (int)r.size()) actTbl[{i, it.la}] = (it.r == 0) ? "acc" : "r" + to_string(it.r);
            else if (!isupper(r[it.dot]) && gotoTbl.count({i, r[it.dot]}))
                actTbl[{i, r[it.dot]}] = "s" + to_string(gotoTbl[{i, r[it.dot]}]);
        }
    }

    cout << "\nLR(1) ACTION & GOTO Table:\n" << left << setw(8) << "State";
    for (char t : term) cout << setw(8) << t;
    for (char nt : nonterm) cout << setw(8) << nt;
    cout << "\n";

    for (size_t i = 0; i < C.size(); i++) {
        cout << setw(8) << i;
        for (char t : term) cout << setw(8) << (actTbl.count({i, t}) ? actTbl[{i, t}] : "");
        for (char nt : nonterm) cout << setw(8) << (gotoTbl.count({i, nt}) ? to_string(gotoTbl[{i, nt}]) : "");
        cout << "\n";
    }

    cout << "\nLab No_Q.: 13 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}