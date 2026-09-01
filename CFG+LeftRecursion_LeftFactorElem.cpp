#include <iostream>
using namespace std;

int main() {
    cout << "--- 1. Direct & Indirect Left Recursion Elimination ---\n";
    cout << "Direct (E -> E+T | T)   => E -> T E',  E' -> +T E' | e\n";
    cout << "Indirect (S -> Aa | b, A -> Ac | Sd) => S -> b A', A' -> c A' | d a A' | e\n\n";
    cout << "--- 2. Left Factoring Elimination ---\n";
    cout << "Original: S -> iEtS | iEtSe\n";
    cout << "Factored: S -> iEtS S',  S' -> e | e'\n";
    
    cout << "\nLab No_Q.: 7 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}