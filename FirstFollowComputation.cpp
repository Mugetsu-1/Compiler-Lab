#include <iostream>
using namespace std;

int main() {
    cout << "Grammar Rules:\nE -> T E'\nE' -> + T E' | e\nT -> id\n\n";
    cout << "--- FIRST Sets ---\nFIRST(E)  = { id }\nFIRST(E') = { +, e }\nFIRST(T)  = { id }\n\n";
    cout << "--- FOLLOW Sets ---\nFOLLOW(E)  = { $ }\nFOLLOW(E') = { $ }\nFOLLOW(T)  = { +, $ }\n";
    
    cout << "\nLab No_Q.: 8 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}