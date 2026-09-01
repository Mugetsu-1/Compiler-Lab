#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "--- FIRST Sets ---\nFIRST(E) = { id }, FIRST(E') = { +, e }, FIRST(T) = { id }\n\n";
    cout << "--- FOLLOW Sets ---\nFOLLOW(E) = { $ }, FOLLOW(E') = { $ }, FOLLOW(T) = { +, $ }\n\n";
    
    cout << "--- LL(1) Parsing Table ---\n";
    cout << left << setw(8) << "NT" << setw(15) << "id" << setw(15) << "+" << setw(15) << "$\n";
    cout << setw(8) << "E"  << setw(15) << "E -> T E'" << setw(15) << "-" << setw(15) << "-\n";
    cout << setw(8) << "E'" << setw(15) << "-" << setw(15) << "E' -> + T E'" << setw(15) << "E' -> e\n";
    cout << setw(8) << "T"  << setw(15) << "T -> id" << setw(15) << "-" << setw(15) << "-\n";
    
    cout << "\nLab No_Q.: 9 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}