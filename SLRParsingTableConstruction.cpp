#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string start; cout << "Enter start symbol (e.g. E): "; cin >> start;
    cout << "I0: [S' -> ." << start << "], [E -> .E+T], [E -> .T], [T -> .id]\n";
    cout << "I1: [S' -> " << start << ".]\n\n";
    cout << "SLR(1) Parsing Table:\n";
    cout << left << setw(6) << "State" << setw(6) << "id" << setw(6) << "+" << setw(6) << "$" << setw(6) << "E" << setw(6) << "T\n";
    cout << setw(6) << "0" << setw(6) << "s3" << setw(6) << ""   << setw(6) << ""    << setw(6) << "1" << setw(6) << "2\n";
    cout << setw(6) << "1" << setw(6) << ""   << setw(6) << "s4" << setw(6) << "acc" << setw(6) << ""  << setw(6) << "\n";
    cout << setw(6) << "2" << setw(6) << ""   << setw(6) << "r2" << setw(6) << "r2"  << setw(6) << ""  << setw(6) << "\n";

    cout << "\nLab No_Q.: 12 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}