#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string in = "i+i$";
    stack<char> st; st.push('$'); st.push('E');
    int i = 0;
    while (!st.empty()) {
        char t = st.top(); st.pop();
        if (t == in[i]) i++;
        else if (t == 'E' && in[i] == 'i') { st.push('R'); st.push('T'); }
        else if (t == 'T' && in[i] == 'i') { st.push('i'); }
        else if (t == 'R' && in[i] == '+') { st.push('R'); st.push('T'); st.push('+'); }
        else if (t == 'R' && in[i] == '$') continue;
        else { cout << "Parsing Failed!\n"; return 0; }
    }
    cout << "String Successfully Parsed!\n";
    cout << "\nLab No_Q.: 10 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}