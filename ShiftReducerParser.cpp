#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string input = "i+i$", stack = "";
    cout << left << setw(15) << "Stack" << setw(15) << "Input" << "Action\n";

    size_t i = 0;
    while (i < input.length()) {
        cout << setw(15) << stack << setw(15) << input.substr(i) << "Shift\n";
        stack += input[i++];
        if (stack.back() == 'i') {
            cout << setw(15) << stack << setw(15) << input.substr(i) << "Reduce E->id\n";
            stack.pop_back(); stack += 'E';
        }
        if (stack == "E+E") {
            cout << setw(15) << stack << setw(15) << input.substr(i) << "Reduce E->E+E\n";
            stack = "E";
        }
    }
    if (stack == "E$") cout << setw(15) << "E$" << setw(15) << "" << "ACCEPTED\n";
    else cout << "REJECTED\n";

    cout << "\nLab No.: 11 | Name: Student | Roll No./Sec: 01/A\n";
    return 0;
}