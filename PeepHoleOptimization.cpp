#include <iostream>
#include <vector>
#include <string>

bool parseMov(const std::string& line, std::string& dest, std::string& src) {
    if (line.rfind("MOV ", 0) == 0) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            dest = line.substr(4, commaPos - 4);
            src = line.substr(commaPos + 2);
            return true;
        }
    }
    return false;
}

void applyPeephole(std::vector<std::string>& instrs) {
    bool changed = true;
    while (changed) {
        changed = false;
        for (size_t i = 0; i < instrs.size() - 1; ++i) {
            std::string src1, dest1, src2, dest2;
            if (parseMov(instrs[i], dest1, src1) && parseMov(instrs[i + 1], dest2, src2)) {
                if (dest1 == src2 && src1 == dest2) {
                    instrs.erase(instrs.begin() + i + 1);
                    changed = true;
                }
            }
        }
    }
}

int main() {
    std::vector<std::string> instrs = {
        "MOV AX, [BP-2]",
        "MOV [BP-2], AX"
    };

    applyPeephole(instrs);

    for (const auto& line : instrs) {
        std::cout << line << "\n";
    }

    std::cout << "\nLab No. 26 Name: Saugat Bikram Thapa /Roll No.: 80117731/ Section: A\n";
    return 0;
}