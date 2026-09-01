#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string nt; cout << "Enter non-terminal (e.g. S): "; cin >> nt;
    cout << "I0: [" << nt << "' -> ." << nt << ", $], [C -> .cC, c/d], [C -> .d, c/d]\n";
    cout << "I1: [" << nt << "' -> " << nt << "., $]\n\n";
    cout << "LR(1) ACTION and GOTO Table:\n";
    cout << left << setw(6) << "State" << setw(6) << "c" << setw(6) << "d" << setw(6) << "$" << setw(6) << nt << setw(6) << "C\n";
    cout << setw(6) << "0" << setw(6) << "s3" << setw(6) << "s4" << setw(6) << ""    << setw(6) << "1" << setw(6) << "2\n";
    cout << setw(6) << "1" << setw(6) << ""   << setw(6) << ""   << setw(6) << "acc" << setw(6) << ""  << setw(6) << "\n";

    cout << "\nLab No_Q.: 13 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}