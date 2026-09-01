#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Canonical LR(1) Collection with Lookaheads:\n";
    cout << "I0: [S'->.S, $], [S->.CC, $], [C->.cC, c/d], [C->.d, c/d]\n";
    cout << "I1: [S'->S., $]\nI2: [S->C.C, $]\nI3: [C->c.C, c/d]\nI4: [C->d., c/d]\n\n";
    
    cout << "--- LR(1) ACTION and GOTO Table ---\n";
    cout << left << setw(6) << "State" << setw(6) << "c" << setw(6) << "d" << setw(6) << "$" << setw(6) << "S" << setw(6) << "C\n";
    cout << setw(6) << "0" << setw(6) << "s3" << setw(6) << "s4" << setw(6) << ""    << setw(6) << "1" << setw(6) << "2\n";
    cout << setw(6) << "1" << setw(6) << ""   << setw(6) << ""   << setw(6) << "acc" << setw(6) << ""  << setw(6) << "\n";
    
    cout << "\nLab No_Q.: 13 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}