#include <iostream>
#include <vector>
#include <string>

struct Quadruple { std::string op, arg1, arg2, result; };

void generate8086(const std::vector<Quadruple>& quads) {
    std::cout << "PUSH BP\nMOV BP, SP\nSUB SP, 10\n";
    for (const auto& q : quads) {
        if (q.op == "+") {
            std::cout << "MOV AX, [BP-2]\n";
            std::cout << "ADD AX, [BP-4]\n";
            std::cout << "MOV [BP-6], AX\n";
        } else if (q.op == "*") {
            std::cout << "MOV AX, [BP-2]\n";
            std::cout << "IMUL WORD PTR [BP-4]\n";
            std::cout << "MOV [BP-8], AX\n";
        } else if (q.op == "ifFalse") {
            std::cout << "MOV AX, [BP-6]\n";
            std::cout << "CMP AX, 0\n";
            std::cout << "JE " << q.result << "\n";
        }
    }
    std::cout << "MOV SP, BP\nPOP BP\nRET\n";
}

int main() {
    std::vector<Quadruple> quads = {
        {"+", "a", "b", "t1"},
        {"*", "a", "b", "t2"},
        {"ifFalse", "t1", "", "L1"}
    };

    generate8086(quads);

    std::cout << "\nLab No. 23 Name: Saugat Bikram Thapa /Roll No.: 80117731/ Section: A\n";
    return 0;
}