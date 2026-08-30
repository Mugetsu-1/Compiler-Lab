#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "LR(0) Canonical Sets:\n";
    cout << "I0: S'->.E, E->.E+T, E->.T, T->.i\n";
    cout << "I1: S'->E., E->E.+T\nI2: E->T.\nI3: T->i.\nI4: E->E+.T, T->.i\nI5: E->E+T.\n\n";

    cout << "SLR(1) Parsing Table\n";
    cout << setw(8) << "State" << setw(8) << "id" << setw(8) << "+" << setw(8) << "$" << setw(8) << "E" << setw(8) << "T" << endl;
    cout << setw(8) << "0" << setw(8) << "s3" << setw(8) << "" << setw(8) << "" << setw(8) << "1" << setw(8) << "2" << endl;
    cout << setw(8) << "1" << setw(8) << "" << setw(8) << "s4" << setw(8) << "acc" << setw(8) << "" << setw(8) << "" << endl;
    cout << setw(8) << "2" << setw(8) << "" << setw(8) << "r2" << setw(8) << "r2" << setw(8) << "" << setw(8) << "" << endl;
    cout << setw(8) << "3" << setw(8) << "" << setw(8) << "r3" << setw(8) << "r3" << setw(8) << "" << setw(8) << "" << endl;
    cout << setw(8) << "4" << setw(8) << "s3" << setw(8) << "" << setw(8) << "" << setw(8) << "" << setw(8) << "5" << endl;
    cout << setw(8) << "5" << setw(8) << "" << setw(8) << "r1" << setw(8) << "r1" << setw(8) << "" << setw(8) << "" << endl;

    cout << "\nLab No_Q.: 12 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}