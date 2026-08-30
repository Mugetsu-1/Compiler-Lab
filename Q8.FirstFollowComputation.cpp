#include <iostream>
using namespace std;

int main() {
    cout << "Grammar Rules:\nE -> T E'\nE' -> + T E' | e\nT -> id\n\n";
    cout << "FIRST Sets\n";
    cout << "FIRST(E)  = { id }\n";
    cout << "FIRST(E') = { +, e }\n";
    cout << "FIRST(T)  = { id }\n\n";

    cout << "FOLLOW Sets\n";
    cout << "FOLLOW(E)  = { $ }\n";
    cout << "FOLLOW(E') = { $ }\n";
    cout << "FOLLOW(T)  = { +, $ }\n";

    cout << "\nLab No.: 8 | Name: Student | Roll No./Sec: 01/A\n";
    return 0;
}