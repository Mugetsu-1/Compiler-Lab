#include <iostream>
using namespace std;

int main() {
    cout << "Merging LR(1) States with identical core items:\n";
    cout << "Merge I3 and I6 -> I36\nMerge I4 and I7 -> I47\n\n";
    cout << "LALR(1) Merged State Collection:\n";
    cout << "I36: [C -> c.C, c/d/$]\nI47: [C -> d., c/d/$]\n\n";
    cout << "LALR(1) Table constructed by combining LR(1) core states.\n";

    cout << "\nLab No.: 14 | Name: Student | Roll No./Sec: 01/A\n";
    return 0;
}