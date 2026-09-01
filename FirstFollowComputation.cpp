#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

map<char, vector<string>> g;
map<char, set<char>> first, follow;
vector<char> nts;

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
        for (char c : rhs) c == '|' ? (g[line[0]].push_back(p), p = "") : p += c;
        g[line[0]].push_back(p);
    }

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
    cout << "\nLab No.: 8 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}