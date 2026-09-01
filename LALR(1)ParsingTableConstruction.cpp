#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "LALR(1) Merged Core States:\n";
    cout << "Merge I3 & I6 -> I36,  Merge I4 & I7 -> I47,  Merge I8 & I9 -> I89\n\n";
    cout << "--- LALR(1) ACTION and GOTO Table ---\n";
    cout << left << setw(6) << "State" << setw(6) << "c" << setw(6) << "d" << setw(6) << "$" << setw(6) << "S" << setw(6) << "C\n";
    cout << setw(6) << "0"  << setw(6) << "s36" << setw(6) << "s47" << setw(6) << ""    << setw(6) << "1" << setw(6) << "2\n";
    cout << setw(6) << "1"  << setw(6) << ""    << setw(6) << ""    << setw(6) << "acc" << setw(6) << ""  << setw(6) << "\n";
    cout << setw(6) << "36" << setw(6) << "s36" << setw(6) << "s47" << setw(6) << ""    << setw(6) << ""  << setw(6) << "89\n";
    
    cout << "\nLab No_Q.: 14 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}