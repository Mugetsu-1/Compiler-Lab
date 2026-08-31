#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

map<char, vector<string>> g;
map<char, set<char>> first, follow;
map<char, map<char, string>> table;
vector<char> nts;
set<char> terms;

bool nt(char c) { return c >= 'A' && c <= 'Z'; }

set<char> firstOf(string s) {
    set<char> ans;
    if (s == "#") return {'#'};
    for (char c : s) {
        set<char> f = nt(c) ? first[c] : set<char>{c};
        ans.insert(f.begin(), f.end());
        if (!f.count('#')) {
            ans.erase('#');
            return ans;
        }
    }
    ans.insert('#');
    return ans;
}

void addProduction(char A, string rhs) {
    string p;
    for (char c : rhs) {
        if (c == '|') g[A].push_back(p), p = "";
        else {
            p += c;
            if (!nt(c) && c != '#') terms.insert(c);
        }
    }
    g[A].push_back(p);
}

void printSet(string name, map<char, set<char>> m) {
    cout << "\n" << name << " Sets\n";
    for (char A : nts) {
        cout << name << "(" << A << ") = { ";
        for (char c : m[A]) cout << c << " ";
        cout << "}\n";
    }
}

int main() {
    int n;
    string line;
    cout << "Enter number of productions: ";
    cin >> n;
    cout << "Use # for epsilon. Example: E->TR\n";
    for (int i = 0; i < n; i++) {
        cin >> line;
        nts.push_back(line[0]);
        addProduction(line[0], line.substr(line.find('>') + 1));
    }
    terms.insert('$');

    bool changed = true;
    while (changed) {
        changed = false;
        for (auto x : g)
            for (string p : x.second) {
                int before = first[x.first].size();
                set<char> f = firstOf(p);
                first[x.first].insert(f.begin(), f.end());
                changed |= before != (int)first[x.first].size();
            }
    }

    follow[nts[0]].insert('$');
    changed = true;
    while (changed) {
        changed = false;
        for (auto x : g)
            for (string p : x.second)
                for (int i = 0; i < (int)p.size(); i++)
                    if (nt(p[i])) {
                        set<char> f = firstOf(i + 1 < (int)p.size() ? p.substr(i + 1) : "#");
                        int before = follow[p[i]].size();
                        for (char c : f) if (c != '#') follow[p[i]].insert(c);
                        if (f.count('#')) follow[p[i]].insert(follow[x.first].begin(), follow[x.first].end());
                        changed |= before != (int)follow[p[i]].size();
                    }
    }

    for (auto x : g)
        for (string p : x.second) {
            set<char> f = firstOf(p);
            for (char a : f) if (a != '#') table[x.first][a] = string(1, x.first) + "->" + p;
            if (f.count('#')) for (char b : follow[x.first]) table[x.first][b] = string(1, x.first) + "->#";
        }

    printSet("FIRST", first);
    printSet("FOLLOW", follow);
    cout << "\nLL(1) Parsing Table\n" << left << setw(8) << "NT";
    for (char t : terms) cout << setw(12) << t;
    cout << "\n";
    for (char A : nts) {
        cout << setw(8) << A;
        for (char t : terms) cout << setw(12) << (table[A].count(t) ? table[A][t] : "-");
        cout << "\n";
    }

    cout << "\nLab No_Q.: 9 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}
