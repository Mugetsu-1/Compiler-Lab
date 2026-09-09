#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

enum DataType { TYPE_INT, TYPE_FLOAT, TYPE_BOOL, TYPE_ERROR };

struct SymbolState {
    bool is_initialized;
};

std::unordered_map<std::string, SymbolState> symbolTable;

class IfASTNode;
class WhileASTNode;
class ForASTNode;
class BreakASTNode;
class ContinueASTNode;
class VarASTNode;

class SemanticVisitor {
public:
    virtual DataType visitIfNode(IfASTNode* node) = 0;
    virtual DataType visitWhileNode(WhileASTNode* node) = 0;
    virtual DataType visitForNode(ForASTNode* node) = 0;
    virtual DataType visitBreakNode(BreakASTNode* node) = 0;
    virtual DataType visitContinueNode(ContinueASTNode* node) = 0;
    virtual DataType visitVarNode(VarASTNode* node) = 0;
};

class ASTNode {
public:
    int lineNo;
    virtual ~ASTNode() = default;
    virtual DataType accept(SemanticVisitor* visitor) = 0;
};

class VarASTNode : public ASTNode {
public:
    std::string name;
    VarASTNode(std::string n, int line) : name(n) { lineNo = line; }
    DataType accept(SemanticVisitor* visitor) override {
        return visitor->visitVarNode(this);
    }
};

class WhileASTNode : public ASTNode {
public:
    ASTNode* condition;
    ASTNode* body;
    WhileASTNode(ASTNode* cond, ASTNode* b, int line)
        : condition(cond), body(b) { lineNo = line; }
    DataType accept(SemanticVisitor* visitor) override {
        return visitor->visitWhileNode(this);
    }
};

class ForASTNode : public ASTNode {
public:
    ASTNode* condition;
    ASTNode* body;
    ForASTNode(ASTNode* cond, ASTNode* b, int line)
        : condition(cond), body(b) { lineNo = line; }
    DataType accept(SemanticVisitor* visitor) override {
        return visitor->visitForNode(this);
    }
};

class IfASTNode : public ASTNode {
public:
    ASTNode* condition;
    ASTNode* body;
    IfASTNode(ASTNode* cond, ASTNode* b, int line)
        : condition(cond), body(b) { lineNo = line; }
    DataType accept(SemanticVisitor* visitor) override {
        return visitor->visitIfNode(this);
    }
};

class BreakASTNode : public ASTNode {
public:
    BreakASTNode(int line) { lineNo = line; }
    DataType accept(SemanticVisitor* visitor) override {
        return visitor->visitBreakNode(this);
    }
};

class ContinueASTNode : public ASTNode {
public:
    ContinueASTNode(int line) { lineNo = line; }
    DataType accept(SemanticVisitor* visitor) override {
        return visitor->visitContinueNode(this);
    }
};

class ConcreteSemanticVisitor : public SemanticVisitor {
private:
    int loop_depth = 0;

public:
    DataType visitVarNode(VarASTNode* node) override {
        if (!symbolTable[node->name].is_initialized) {
            std::cout << "Line " << node->lineNo << ": Error Variable '" << node->name << "' used before initialization.\n";
            return TYPE_ERROR;
        }
        return TYPE_BOOL;
    }

    DataType visitWhileNode(WhileASTNode* node) override {
        DataType condType = node->condition->accept(this);
        if (condType != TYPE_BOOL && condType != TYPE_INT) {
            std::cout << "Line " << node->lineNo << ": Error Loop condition must evaluate to boolean.\n";
        }
        loop_depth++;
        if (node->body) node->body->accept(this);
        loop_depth--;
        return TYPE_BOOL;
    }

    DataType visitForNode(ForASTNode* node) override {
        DataType condType = node->condition->accept(this);
        if (condType != TYPE_BOOL && condType != TYPE_INT) {
            std::cout << "Line " << node->lineNo << ": Error Loop condition must evaluate to boolean.\n";
        }
        loop_depth++;
        if (node->body) node->body->accept(this);
        loop_depth--;
        return TYPE_BOOL;
    }

    DataType visitBreakNode(BreakASTNode* node) override {
        if (loop_depth == 0) {
            std::cout << "Line " << node->lineNo << ": Error 'break' statement outside loop context.\n";
            return TYPE_ERROR;
        }
        return TYPE_BOOL;
    }

    DataType visitContinueNode(ContinueASTNode* node) override {
        if (loop_depth == 0) {
            std::cout << "Line " << node->lineNo << ": Error 'continue' statement outside loop context.\n";
            return TYPE_ERROR;
        }
        return TYPE_BOOL;
    }

    DataType visitIfNode(IfASTNode* node) override {
        DataType condType = node->condition->accept(this);
        if (condType != TYPE_BOOL && condType != TYPE_INT) {
            std::cout << "Line " << node->lineNo << ": Error Condition must evaluate to boolean.\n";
        }
        if (node->body) node->body->accept(this);
        return TYPE_BOOL;
    }
};

int main() {
    symbolTable["a"] = {false};
    ConcreteSemanticVisitor visitor;

    VarASTNode uninitVar("a", 1);
    BreakASTNode badBreak(2);
    badBreak.accept(&visitor);

    WhileASTNode whileNode(&uninitVar, nullptr, 3);
    whileNode.accept(&visitor);

    std::cout << "\nLab No. 19 Name: Saugat Bikram Thapa /Roll No.: 80117731/ Section: A\n";
    return 0;
}