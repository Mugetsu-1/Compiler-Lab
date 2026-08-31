#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<char, vector<string>> g;
vector<char> nts;
char nextNt = 'Z';

vector<string> split(string s) {
    vector<string> v;
    string t;
    for (char c : s) c == '|' ? (v.push_back(t), t = "") : t += c;
    v.push_back(t);
    return v;
}

char fresh() {
    while (g.count(nextNt)) nextNt--;
    nts.push_back(nextNt);
    return nextNt--;
}

void removeDirect(char A) {
    vector<string> alpha, beta;
    for (string p : g[A]) (p[0] == A ? alpha : beta).push_back(p[0] == A ? p.substr(1) : p);
    if (alpha.empty()) return;
    char B = fresh();
    g[A].clear();
    for (string b : beta) g[A].push_back(b + B);
    for (string a : alpha) g[B].push_back(a + B);
    g[B].push_back("#");
}

string lcp(vector<string> v) {
    string p = v[0];
    for (string s : v) {
        int i = 0;
        while (i < (int)p.size() && i < (int)s.size() && p[i] == s[i]) i++;
        p = p.substr(0, i);
    }
    return p;
}

void factor(char A) {
    map<char, vector<string>> group;
    for (string p : g[A]) group[p[0]].push_back(p);
    vector<string> keep;
    for (auto x : group) {
        if (x.second.size() == 1) keep.push_back(x.second[0]);
        else {
            string p = lcp(x.second);
            char B = fresh();
            keep.push_back(p + B);
            for (string s : x.second) g[B].push_back(s.size() == p.size() ? "#" : s.substr(p.size()));
        }
    }
    g[A] = keep;
}

void print() {
    for (char A : nts) {
        cout << A << " -> ";
        for (int i = 0; i < (int)g[A].size(); i++) cout << (i ? " | " : "") << g[A][i];
        cout << "\n";
    }
}

int main() {
    int n;
    string line;
    cout << "Enter number of productions: ";
    cin >> n;
    cout << "Use # for epsilon. Example: E->E+T|T\n";
    for (int i = 0; i < n; i++) {
        cin >> line;
        nts.push_back(line[0]);
        g[line[0]] = split(line.substr(line.find('>') + 1));
    }

    for (int i = 0; i < (int)nts.size(); i++) {
        char Ai = nts[i];
        for (int j = 0; j < i; j++) {
            char Aj = nts[j];
            vector<string> v;
            for (string p : g[Ai])
                if (p[0] == Aj) for (string q : g[Aj]) v.push_back(q + p.substr(1));
                else v.push_back(p);
            g[Ai] = v;
        }
        removeDirect(Ai);
    }
    cout << "\nAfter eliminating left recursion:\n";
    print();

    int original = nts.size();
    for (int i = 0; i < original; i++) factor(nts[i]);
    cout << "\nAfter left factoring:\n";
    print();

    cout << "\nLab No_Q.: 7 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}
