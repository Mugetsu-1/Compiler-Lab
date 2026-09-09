#include <iostream>
#include <vector>
#include <string>

struct Instruction {
    int id;
    std::string code;
    bool isLeader;
    bool isLive;
};

int main() {
    std::vector<Instruction> tac = {
        {1, "i = 1", false, true},
        {2, "L1: t1 = i * 4", false, true},
        {3, "if t1 > 100 goto L2", false, true},
        {4, "i = i + 1", false, true},
        {5, "goto L1", false, true},
        {6, "L2: return i", false, true}
    };

    tac[0].isLeader = true;
    for (size_t i = 0; i < tac.size(); ++i) {
        if (tac[i].code.find("goto") != std::string::npos && i + 1 < tac.size()) {
            tac[i + 1].isLeader = true;
        }
        if (tac[i].code.find("L1:") != std::string::npos || tac[i].code.find("L2:") != std::string::npos) {
            tac[i].isLeader = true;
        }
    }

    std::cout << "ID\tLeader\tLive\tInstruction\n";
    for (const auto& inst : tac) {
        if (inst.isLive) {
            std::cout << inst.id << "\t" << (inst.isLeader ? "YES" : "NO") << "\t"
                      << (inst.isLive ? "LIVE" : "DEAD") << "\t" << inst.code << "\n";
        }
    }

    std::cout << "\nLab No. 25 Name: Saugat Bikram Thapa /Roll No.: 80117731/ Section: A\n";
    return 0;
}