#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

struct SymbolInfo {
    std::string name;
    std::string type;
    int size;
    int scopeLevel;
};

class ScopedSymbolTable {
private:
    std::vector<std::unordered_map<std::string, SymbolInfo>> scopeStack;

public:
    ScopedSymbolTable() { enter_scope(); }

    void enter_scope() { scopeStack.push_back({}); }

    void leave_scope() {
        if (!scopeStack.empty()) scopeStack.pop_back();
    }

    void insert(const std::string& name, const std::string& type, int size) {
        int currentLevel = scopeStack.size() - 1;
        if (scopeStack.back().count(name)) {
            std::cout << "Redeclaration Error: " << name << " in current scope\n";
        } else {
            scopeStack.back()[name] = {name, type, size, currentLevel};
            std::cout << "Inserted '" << name << "' into scope level " << currentLevel << "\n";
        }
    }

    SymbolInfo* lookup(const std::string& name) {
        for (int i = scopeStack.size() - 1; i >= 0; --i) {
            auto it = scopeStack[i].find(name);
            if (it != scopeStack[i].end()) return &(it->second);
        }
        std::cout << "Undeclared Error: " << name << "\n";
        return nullptr;
    }
};

struct ASTNode {
    virtual ~ASTNode() = default;
    virtual void execute(ScopedSymbolTable& st) = 0;
};

struct VarDeclASTNode : public ASTNode {
    std::string name, type;
    int size;
    VarDeclASTNode(std::string n, std::string t, int s) : name(n), type(t), size(s) {}
    void execute(ScopedSymbolTable& st) override { st.insert(name, type, size); }
};

struct LookupASTNode : public ASTNode {
    std::string name;
    LookupASTNode(std::string n) : name(n) {}
    void execute(ScopedSymbolTable& st) override { st.lookup(name); }
};

struct BlockASTNode : public ASTNode {
    std::vector<ASTNode*> statements;
    void execute(ScopedSymbolTable& st) override {
        st.enter_scope();
        for (auto stmt : statements) stmt->execute(st);
        st.leave_scope();
    }
};

int main() {
    ScopedSymbolTable st;
    VarDeclASTNode globalVar("x", "int", 4);
    globalVar.execute(st);

    BlockASTNode innerBlock;
    VarDeclASTNode innerVar("x", "float", 4);
    LookupASTNode searchX("x");
    LookupASTNode searchZ("z");

    innerBlock.statements.push_back(&innerVar);
    innerBlock.statements.push_back(&searchX);
    innerBlock.statements.push_back(&searchZ);

    innerBlock.execute(st);
    st.lookup("x");

    std::cout << "\nLab No. 17 Name: Saugat Bikram Thapa /Roll No.: 80117731/ Section: A\n";
    return 0;
}