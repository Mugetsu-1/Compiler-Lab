#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Canonical LR(1) Items with Lookaheads:\n";
    cout << "I0: [S'->.S, $], [S->.CC, $], [C->.cC, c/d], [C->.d, c/d]\n";
    cout << "I1: [S'->S., $]\nI2: [S->C.C, $], [C->.cC, $], [C->.d, $]\n";
    cout << "I3: [C->c.C, c/d], [C->.cC, c/d], [C->.d, c/d]\nI4: [C->d., c/d]\n\n";

    cout << "LR(1) ACTION and GOTO Table\n";
    cout << setw(8) << "State" << setw(8) << "c" << setw(8) << "d" << setw(8) << "$" << setw(8) << "S" << setw(8) << "C" << endl;
    cout << setw(8) << "0" << setw(8) << "s3" << setw(8) << "s4" << setw(8) << "" << setw(8) << "1" << setw(8) << "2" << endl;
    cout << setw(8) << "1" << setw(8) << "" << setw(8) << "" << setw(8) << "acc" << setw(8) << "" << setw(8) << "" << endl;

    cout << "\nLab No_Q.: 13 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}