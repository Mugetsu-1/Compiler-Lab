#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

struct P { char l; string r; };
struct Item {
    int p, dot;
    bool operator<(const Item &o) const { return p != o.p ? p < o.p : dot < o.dot; }
};

vector<P> prods = {{'Z',"S"}, {'S',"E"}, {'E',"E+T"}, {'E',"T"}, {'T',"T*F"}, {'T',"F"}, {'F',"(E)"}, {'F',"i"}};
vector<char> nts = {'S','E','T','F'}, terms = {'i','+','*','(',')','$'};
map<char, set<char>> first, follow;

bool nt(char c) { return c >= 'A' && c <= 'Z'; }

set<Item> closure(set<Item> I) {
    bool add = true;
    while (add) {
        add = false;
        for (auto it : I) {
            string r = prods[it.p].r;
            if (it.dot < (int)r.size() && nt(r[it.dot]))
                for (int i = 0; i < (int)prods.size(); i++)
                    if (prods[i].l == r[it.dot]) add |= I.insert({i, 0}).second;
        }
    }
    return I;
}

set<Item> goTo(set<Item> I, char X) {
    set<Item> J;
    for (auto it : I)
        if (it.dot < (int)prods[it.p].r.size() && prods[it.p].r[it.dot] == X) J.insert({it.p, it.dot + 1});
    return closure(J);
}

void makeFollow() {
    for (char t : terms) first[t].insert(t);
    bool changed = true;
    while (changed) {
        changed = false;
        for (auto p : prods) {
            int before = first[p.l].size();
            first[p.l].insert(first[p.r[0]].begin(), first[p.r[0]].end());
            changed |= before != (int)first[p.l].size();
        }
    }
    follow['S'].insert('$');
    changed = true;
    while (changed) {
        changed = false;
        for (auto p : prods)
            for (int i = 0; i < (int)p.r.size(); i++)
                if (nt(p.r[i])) {
                    int before = follow[p.r[i]].size();
                    if (i + 1 < (int)p.r.size()) follow[p.r[i]].insert(first[p.r[i + 1]].begin(), first[p.r[i + 1]].end());
                    else follow[p.r[i]].insert(follow[p.l].begin(), follow[p.l].end());
                    follow[p.r[i]].erase('#');
                    changed |= before != (int)follow[p.r[i]].size();
                }
    }
}

int stateOf(vector<set<Item>> C, set<Item> I) {
    for (int i = 0; i < (int)C.size(); i++) if (C[i] == I) return i;
    return -1;
}

int main() {
    vector<set<Item>> C;
    map<pair<int, char>, int> trans;
    queue<int> q;
    C.push_back(closure({{0, 0}}));
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
    makeFollow();

    cout << "LR(0) Canonical Item Sets\n";
    for (int i = 0; i < (int)C.size(); i++) {
        cout << "I" << i << ":\n";
        for (auto it : C[i]) cout << "  " << prods[it.p].l << "->" << prods[it.p].r.substr(0, it.dot) << "." << prods[it.p].r.substr(it.dot) << "\n";
    }

    cout << "\nSLR(1) ACTION and GOTO Table\n";
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
                if (it.dot == (int)prods[it.p].r.size())
                    a = it.p == 0 ? "acc" : (follow[prods[it.p].l].count(t) ? "r" + to_string(it.p) : a);
            cout << setw(8) << a;
        }
        for (char A : nts) cout << setw(8) << (trans.count({i, A}) ? to_string(trans[{i, A}]) : "");
        cout << "\n";
    }

    cout << "\nLab No_Q.: 12 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}
