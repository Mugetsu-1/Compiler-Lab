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

set<char> firstOf(string s) {   // FIRST of a symbol string
    set<char> ans;
    for (char c : s) {
        set<char> f = nt(c) ? first[c] : set<char>{c};
        ans.insert(f.begin(), f.end());
        if (!f.count('#')) { ans.erase('#'); return ans; }
    }
    ans.insert('#');
    return ans;
}

int main() {
    int n; string line;
    cout << "Enter number of productions (use # for epsilon, e.g. E->TR): ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> line;
        nts.push_back(line[0]);
        string rhs = line.substr(line.find('>') + 1), p = "";
        for (char c : rhs) {
            if (c == '|') g[line[0]].push_back(p), p = "";
            else {
                p += c;
                if (!nt(c) && c != '#') terms.insert(c);
            }
        }
        g[line[0]].push_back(p);
    }
    terms.insert('$');

    bool ch = true;             // FIRST fixpoint
    while (ch) {
        ch = false;
        for (auto& x : g) for (string p : x.second) {
            int b = first[x.first].size();
            set<char> f = firstOf(p);
            first[x.first].insert(f.begin(), f.end());
            ch |= b != (int)first[x.first].size();
        }
    }

    follow[nts[0]].insert('$'); // FOLLOW fixpoint
    ch = true;
    while (ch) {
        ch = false;
        for (auto& x : g) for (string p : x.second)
            for (int i = 0; i < (int)p.size(); i++) if (nt(p[i])) {
                set<char> f = firstOf(p.substr(i + 1));
                int b = follow[p[i]].size();
                for (char c : f) if (c != '#') follow[p[i]].insert(c);
                if (f.count('#')) follow[p[i]].insert(follow[x.first].begin(), follow[x.first].end());
                ch |= b != (int)follow[p[i]].size();
            }
    }

    for (auto& x : g) for (string p : x.second) {   // fill table
        set<char> f = firstOf(p);
        for (char a : f) if (a != '#') table[x.first][a] = string(1, x.first) + "->" + p;
        if (f.count('#'))
            for (char b : follow[x.first]) table[x.first][b] = string(1, x.first) + "->#";
    }

    cout << "\nFIRST Sets\n";
    for (char A : nts) {
        cout << "FIRST(" << A << ") = { ";
        for (char c : first[A]) cout << c << " ";
        cout << "}\n";
    }
    cout << "\nFOLLOW Sets\n";
    for (char A : nts) {
        cout << "FOLLOW(" << A << ") = { ";
        for (char c : follow[A]) cout << c << " ";
        cout << "}\n";
    }

    cout << "\nLL(1) Parsing Table\n" << left << setw(8) << "NT";
    for (char t : terms) cout << setw(12) << t;
    cout << "\n";
    for (char A : nts) {
        cout << setw(8) << A;
        for (char t : terms) cout << setw(12) << (table[A].count(t) ? table[A][t] : "-");
        cout << "\n";
    }

    cout << "\nLab No.: 9 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}