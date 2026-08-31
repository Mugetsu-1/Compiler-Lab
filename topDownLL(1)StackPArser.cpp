#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Grammar: E->TX, X->+TX|e, T->i\nEnter input using i for id: ";
    cin >> input;
    if (input.back() != '$') input += '$';
    stack<char> st;
    st.push('$'); st.push('E');
    size_t ip = 0;

    while (!st.empty()) {
        char top = st.top();
        char curr = input[ip];

        if (top == curr) { st.pop(); ip++; }
        else if (top == 'E' && curr == 'i') { st.pop(); st.push('X'); st.push('T'); } // E -> T X (X = E')
        else if (top == 'T' && curr == 'i') { st.pop(); st.push('i'); }               // T -> i
        else if (top == 'X' && curr == '+') { st.pop(); st.push('X'); st.push('T'); st.push('+'); } // X -> + T X
        else if (top == 'X' && curr == '$') { st.pop(); }                             // X -> e
        else { cout << "Parsing Failed!\n"; cout << "\nLab No.: 10 | Name: Student | Roll No./Sec: 01/A\n"; return 0; }
    }
    cout << "String Successfully Parsed!\n";

    cout << "\nLab No.: 10 | Name: Student | Roll No./Sec: 01/A\n";
    return 0;
}
