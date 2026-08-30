#include <iostream>
#include <string>
using namespace std;

void classify(string op, int line) {
    string cat;
    if (op=="+"||op=="-"||op=="*"||op=="/"||op=="%") cat = "Arithmetic";
    else if (op=="<"||op==">"||op=="<="||op==">="||op=="=="||op=="!=") cat = "Relational";
    else if (op=="&&"||op=="||"||op=="!") cat = "Logical";
    else if (op=="="||op=="+="||op=="-="||op=="*="||op=="/=") cat = "Assignment";
    if (!cat.empty()) cout << "<" << op << ", " << cat << ", " << line << ">\n";
}

int main() {
    string s;
    cout << "Enter expression: ";
    getline(cin, s);
    int line = 1;

    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '\n') line++;
        string two = s.substr(i, 2);
        if (two=="<="||two==">="||two=="=="||two=="!="||two=="&&"||two=="||"||two=="+="||two=="-="||two=="*="||two=="/=") {
            classify(two, line);
            i++;
        } else if (string("+-*/%=<>!").find(s[i]) != string::npos) {
            classify(s.substr(i, 1), line);
        } else if (s[i] == '&' || s[i] == '|') {
            cout << "Invalid Operator: " << s[i] << " at line " << line << endl;
        }
    }

    cout << "\nLab No_Q.: 5 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}