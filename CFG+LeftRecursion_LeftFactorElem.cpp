#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<char, vector<string>> g;   // grammar: A -> RHS list
vector<char> nt;               // non-terminals in input order
char nx = 'Z';                 // next fresh non-terminal

vector<string> sp(string s) {  // split RHS on '|'
    vector<string> v; string t;
    for (char c : s) c == '|' ? (v.push_back(t), t = "") : t += c;
    v.push_back(t);
    return v;
}
char fresh() { while (g.count(nx)) nx--; nt.push_back(nx); return nx--; }

void remLR(char A) {           // A -> Aa|b  =>  A -> bA', A' -> aA'|#
    vector<string> a, b;
    for (string p : g[A]) (p[0] == A ? a : b).push_back(p[0] == A ? p.substr(1) : p);
    if (a.empty()) return;
    char B = fresh();
    g[A].clear();
    for (string x : b) g[A].push_back(x + B);
    for (string x : a) g[B].push_back(x + B);
    g[B].push_back("#");
}

void factor(char A) {          // A -> ab|ac  =>  A -> aA', A' -> b|c
    map<char, vector<string>> gr;
    for (string p : g[A]) gr[p[0]].push_back(p);
    vector<string> k;
    for (auto& x : gr) {
        if (x.second.size() == 1) { k.push_back(x.second[0]); continue; }
        string p = x.second[0];              // longest common prefix
        for (string s : x.second)
            while (p.size() && (p.size() > s.size() || p[p.size()-1] != s[p.size()-1]))
                p = p.substr(0, p.size() - 1);
        char B = fresh();
        k.push_back(p + B);
        for (string s : x.second) g[B].push_back(s.size() == p.size() ? "#" : s.substr(p.size()));
    }
    g[A] = k;
}

void pr() {
    for (char A : nt) {
        cout << A << " -> ";
        for (int i = 0; i < (int)g[A].size(); i++) cout << (i ? " | " : "") << g[A][i];
        cout << "\n";
    }
}

int main() {
    int n; string s;
    cout << "Enter number of productions (use # for epsilon, e.g. E->E+T|T): ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        nt.push_back(s[0]);
        g[s[0]] = sp(s.substr(s.find('>') + 1));
    }
    for (int i = 0; i < (int)nt.size(); i++) {  // indirect then direct LR removal
        char A = nt[i];
        for (int j = 0; j < i; j++) {
            char B = nt[j]; vector<string> v;
            for (string p : g[A])
                if (p[0] == B) { for (string q : g[B]) v.push_back(q + p.substr(1)); }
                else v.push_back(p);
            g[A] = v;
        }
        remLR(A);
    }
    cout << "\nAfter eliminating left recursion:\n"; pr();
    int m = nt.size();
    for (int i = 0; i < m; i++) factor(nt[i]);  // left factoring
    cout << "\nAfter left factoring:\n"; pr();
    cout << "\nLab No.: 7 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}