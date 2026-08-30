#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    vector<string> kw = {"int","float","char","if","else","while","for","return","void","double"};

    for (auto k : kw) {
        if (s == k) {
            cout << "Reserved Keyword\n";
            cout << "\nLab No_Q.: 4 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
            return 0;
        }
    }

    if (!(isalpha(s[0]) || s[0] == '_')) {
        cout << "Invalid Identifier: Must start with letter or underscore.\n";
    } else {
        bool valid = true;
        for (size_t i = 1; i < s.length(); i++) {
            if (!(isalnum(s[i]) || s[i] == '_')) {
                cout << "Invalid Identifier: Contains invalid character '" << s[i] << "'\n";
                valid = false;
                break;
            }
        }
        if (valid) cout << "Valid Identifier\n";
    }

    cout << "\nLab No_Q.: 4 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n";
    return 0;
}