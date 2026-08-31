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
    for (char c : rhs) c == '|' ? (g[A].push_back(p), p = "") : p += c;
    g[A].push_back(p);
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

    cout << "\nLab No_Q.: 8 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}
