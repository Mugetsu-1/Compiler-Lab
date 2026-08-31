#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
using namespace std;

struct P { char l; string r; };
struct Item {
    int p, dot;
    char la;
    bool operator<(const Item &o) const {
        if (p != o.p) return p < o.p;
        if (dot != o.dot) return dot < o.dot;
        return la < o.la;
    }
};

vector<P> prods = {{'Z',"S"}, {'S',"E"}, {'E',"E+T"}, {'E',"T"}, {'T',"T*F"}, {'T',"F"}, {'F',"(E)"}, {'F',"i"}};
vector<char> nts = {'S','E','T','F'}, terms = {'i','+','*','(',')','$'};
map<char, set<char>> first;

bool nt(char c) { return c >= 'A' && c <= 'Z'; }

set<char> firstSeq(string s) {
    set<char> ans;
    for (char c : s) {
        set<char> f = nt(c) ? first[c] : set<char>{c};
        ans.insert(f.begin(), f.end());
        if (!f.count('#')) return ans;
        ans.erase('#');
    }
    ans.insert('#');
    return ans;
}

void makeFirst() {
    for (char t : terms) first[t].insert(t);
    bool changed = true;
    while (changed) {
        changed = false;
        for (auto p : prods) {
            int before = first[p.l].size();
            set<char> f = firstSeq(p.r);
            first[p.l].insert(f.begin(), f.end());
            changed |= before != (int)first[p.l].size();
        }
    }
}

set<Item> closure(set<Item> I) {
    bool add = true;
    while (add) {
        add = false;
        for (auto it : I) {
            string r = prods[it.p].r;
            if (it.dot < (int)r.size() && nt(r[it.dot])) {
                set<char> las = firstSeq(r.substr(it.dot + 1) + it.la);
                for (int i = 0; i < (int)prods.size(); i++)
                    if (prods[i].l == r[it.dot])
                        for (char a : las) add |= I.insert({i, 0, a}).second;
            }
        }
    }
    return I;
}

set<Item> goTo(set<Item> I, char X) {
    set<Item> J;
    for (auto it : I)
        if (it.dot < (int)prods[it.p].r.size() && prods[it.p].r[it.dot] == X) J.insert({it.p, it.dot + 1, it.la});
    return closure(J);
}

int stateOf(vector<set<Item>> C, set<Item> I) {
    for (int i = 0; i < (int)C.size(); i++) if (C[i] == I) return i;
    return -1;
}

int main() {
    makeFirst();
    vector<set<Item>> C;
    map<pair<int, char>, int> trans;
    queue<int> q;
    C.push_back(closure({{0, 0, '$'}}));
    q.push(0);
    while (!q.empty()) {
        int i = q.front(); q.pop();
        for (char X : string("SETF+*()i")) {
            set<Item> J = goTo(C[i], X);
            if (J.empty()) continue;
            int j = stateOf(C, J);
            if (j == -1) C.push_back(J), j = C.size() - 1, q.push(j);
            trans[{i, X}] = j;
        }
    }

    cout << "Canonical LR(1) Item Sets with Lookaheads\n";
    for (int i = 0; i < (int)C.size(); i++) {
        cout << "I" << i << ":\n";
        for (auto it : C[i]) cout << "  [" << prods[it.p].l << "->" << prods[it.p].r.substr(0, it.dot) << "." << prods[it.p].r.substr(it.dot) << ", " << it.la << "]\n";
    }

    cout << "\nLR(1) ACTION and GOTO Table\n";
    cout << setw(6) << "State";
    for (char t : terms) cout << setw(8) << t;
    for (char A : nts) cout << setw(8) << A;
    cout << "\n";
    for (int i = 0; i < (int)C.size(); i++) {
        cout << setw(6) << i;
        for (char t : terms) {
            string a = "";
            if (trans.count({i, t})) a = "s" + to_string(trans[{i, t}]);
            for (auto it : C[i])
                if (it.dot == (int)prods[it.p].r.size() && it.la == t)
                    a = it.p == 0 ? "acc" : "r" + to_string(it.p);
            cout << setw(8) << a;
        }
        for (char A : nts) cout << setw(8) << (trans.count({i, A}) ? to_string(trans[{i, A}]) : "");
        cout << "\n";
    }

    cout << "\nLab No_Q.: 13 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}
