#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Grammar: S->E, E->E+T|T, T->T*F|F, F->(E)|id\n\n";
    cout << "Canonical LR(0) Collection (CLOSURE & GOTO):\n";
    cout << "I0: [S'->.E] [E->.E+T] [E->.T] [T->.T*F] [T->.F] [F->.(E)] [F->.id]\n";
    cout << "I1: [S'->E.] [E->E.+T],  I2: [E->T.] [T->T.*F],  I3: [T->F.],  I4: [F->(.E)]\n";
    cout << "I5: [F->id.],  I6: [E->E+.T],  I7: [T->T*.F],  I8: [F->(E.)],  I9: [E->E+T.]\n\n";
    
    cout << "--- SLR(1) ACTION and GOTO Table ---\n";
    cout << left << setw(6) << "State" << setw(6) << "id" << setw(6) << "+" << setw(6) << "*" << setw(6) << "(" << setw(6) << ")" << setw(6) << "$" << setw(6) << "E" << setw(6) << "T" << setw(6) << "F\n";
    cout << setw(6) << "0" << setw(6) << "s5" << setw(6) << ""   << setw(6) << ""   << setw(6) << "s4" << setw(6) << ""   << setw(6) << ""    << setw(6) << "1" << setw(6) << "2" << setw(6) << "3\n";
    cout << setw(6) << "1" << setw(6) << ""   << setw(6) << "s6" << setw(6) << ""   << setw(6) << ""   << setw(6) << ""   << setw(6) << "acc" << setw(6) << ""  << setw(6) << ""  << setw(6) << "\n";
    cout << setw(6) << "5" << setw(6) << ""   << setw(6) << "r6" << setw(6) << "r6" << setw(6) << ""   << setw(6) << "r6" << setw(6) << "r6"  << setw(6) << ""  << setw(6) << ""  << setw(6) << "\n";
    
    cout << "\nLab No_Q.: 12 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}