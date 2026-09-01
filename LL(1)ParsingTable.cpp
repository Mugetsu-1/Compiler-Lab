#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, c1, c2;
    map<pair<char, char>, string> tbl;
    vector<char> nts, ts;
    cout << "Enter rule count: "; cin >> n;
    cout << "Enter entries (e.g., E i E->TR):\n";
    for (int i = 0; i < n; i++) { char nt, t; string p; cin >> nt >> t >> p; tbl[{nt, t}] = p; }
    cout << "Non-terminal count and list: "; cin >> c1; for(int i=0; i<c1; i++){ char x; cin >> x; nts.push_back(x); }
    cout << "Terminal count and list: "; cin >> c2; for(int i=0; i<c2; i++){ char x; cin >> x; ts.push_back(x); }

    cout << "\nLL(1) Parsing Table:\n" << left << setw(8) << "NT";
    for (char t : ts) cout << setw(15) << t;
    cout << "\n";
    for (char nt : nts) {
        cout << setw(8) << nt;
        for (char t : ts) cout << setw(15) << (tbl.count({nt, t}) ? tbl[{nt, t}] : "-");
        cout << "\n";
    }

    cout << "\nLab No_Q.: 9 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}