#include <iostream>
#include <string>
using namespace std;

int main() {
    // Left Recursion Elimination for E -> E+T | T
    cout << "Left Recursion Elimination (E -> E+T | T)\n";
    cout << "E -> T E'\n";
    cout << "E' -> +T E' | e\n\n";

    // Left Factoring Elimination for S -> iEtS | iEtSe
    cout << "Left Factoring Elimination (S -> iEtS | iEtSe)\n";
    cout << "S -> iEtS S'\n";
    cout << "S' -> e | e'\n";

    cout << "\nLab No.: 7 | Name: Student | Roll No./Sec: 01/A\n";
    return 0;
}