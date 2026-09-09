#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>

struct Quadruple { std::string op, arg1, arg2, result; };
std::vector<Quadruple> quadList;
int tempCount = 1;

std::string newTemp() { return "t" + std::to_string(tempCount++); }

bool isoperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/" || token == "==" || token == ">" || token == "<";
}

void generateTACFromPostfix(const std::vector<std::string>& tokens) {
    std::stack<std::string> st;
    for (const auto& token : tokens) {
        if (isoperator(token)) {
            std::string arg2 = st.top(); st.pop();
            std::string arg1 = st.top(); st.pop();
            std::string t = newTemp();
            quadList.push_back({token, arg1, arg2, t});
            st.push(t);
        } else {
            st.push(token);
        }
    }
}

int main() {
    std::vector<std::string> postfix = {"a", "b", "c", "*", "+"};
    generateTACFromPostfix(postfix);

    std::cout << "Op\tArg1\tArg2\tResult\n";
    for (const auto& q : quadList) {
        std::cout << q.op << "\t" << q.arg1 << "\t" << q.arg2 << "\t" << q.result << "\n";
    }

    std::cout << "\nLab No. 20 Name: Saugat Bikram Thapa /Roll No.: 80117731/ Section: A\n";
    return 0;
}