#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "LL(1) Parsing Table\n";
    cout << left << setw(10) << "NT" << setw(15) << "id" << setw(15) << "+" << setw(15) << "$" << endl;
    cout << left << setw(10) << "E" << setw(15) << "E -> T E'" << setw(15) << "-" << setw(15) << "-" << endl;
    cout << left << setw(10) << "E'" << setw(15) << "-" << setw(15) << "E' -> + T E'" << setw(15) << "E' -> e" << endl;
    cout << left << setw(10) << "T" << setw(15) << "T -> id" << setw(15) << "-" << setw(15) << "-" << endl;

    cout << "\nLab No.: 9 | Name: Student | Roll No./Sec: 01/A\n";
    return 0;
}