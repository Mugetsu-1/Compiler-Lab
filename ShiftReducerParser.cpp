#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string H[] = {"i", "E+E", "E*E", "(E)"};            // handles (RHS)
string R[] = {"E->id", "E->E+E", "E->E*E", "E->(E)"};

int main() {
    string in, st = "";
    cout << "Grammar: E->E+E | E*E | (E) | i\nEnter input using i for id: ";
    cin >> in;
    if (in.back() != '$') in += '$';
    cout << left << setw(15) << "Stack" << setw(15) << "Input" << "Action\n";
    size_t i = 0;
    int steps = 0;
    while (steps++ < 5000) {
        if (st == "E" && in[i] == '$') {            // start symbol reached
            cout << setw(15) << st << setw(15) << in.substr(i) << "ACCEPTED\n";
            break;
        }
        bool red = false;                           // reduce topmost handle if any
        for (int k = 0; k < 4; k++)
            if (st.size() >= H[k].size() && st.substr(st.size() - H[k].size()) == H[k]) {
                cout << setw(15) << st << setw(15) << in.substr(i) << "Reduce " << R[k] << "\n";
                st.replace(st.size() - H[k].size(), H[k].size(), "E");
                red = true;
                break;
            }
        if (red) continue;
        if (i == in.size()) { cout << "REJECTED\n"; break; }
        cout << setw(15) << st << setw(15) << in.substr(i) << "Shift\n";
        st += in[i++];
    }
    cout << "\nLab No.: 11 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}