#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string input, stack = "";
    cout << "Grammar: E->E+E | E*E | (E) | i\nEnter input using i for id: ";
    cin >> input;
    if (input.back() != '$') input += '$';
    cout << left << setw(15) << "Stack" << setw(15) << "Input" << "Action\n";

    size_t i = 0;
    while (i < input.length()) {
        cout << setw(15) << stack << setw(15) << input.substr(i) << "Shift\n";
        stack += input[i++];
        if (stack.back() == 'i') {
            cout << setw(15) << stack << setw(15) << input.substr(i) << "Reduce E->id\n";
            stack.pop_back(); stack += 'E';
        }
        if (stack.size() >= 3 && stack.substr(stack.size() - 3) == "E+E") {
            cout << setw(15) << stack << setw(15) << input.substr(i) << "Reduce E->E+E\n";
            stack.replace(stack.size() - 3, 3, "E");
        }
        if (stack.size() >= 3 && stack.substr(stack.size() - 3) == "E*E") {
            cout << setw(15) << stack << setw(15) << input.substr(i) << "Reduce E->E*E\n";
            stack.replace(stack.size() - 3, 3, "E");
        }
        if (stack.size() >= 3 && stack.substr(stack.size() - 3) == "(E)") {
            cout << setw(15) << stack << setw(15) << input.substr(i) << "Reduce E->(E)\n";
            stack.replace(stack.size() - 3, 3, "E");
        }
        if (stack == "E$") {
            cout << setw(15) << "E$" << setw(15) << "" << "ACCEPTED\n";
            cout << "\nLab No_Q.: 11 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
            return 0;
        }
        if (stack == "E+E") {
            stack = "E";
        }
    }
    cout << "REJECTED\n";

    cout << "\nLab No_Q.: 11 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}
