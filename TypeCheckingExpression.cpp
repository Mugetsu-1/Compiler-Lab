#include <iostream>
#include <string>
#include <unordered_map>

enum DataType { TYPE_INT, TYPE_FLOAT, TYPE_BOOL, TYPE_ARRAY, TYPE_ERROR };

struct Symbol {
    DataType type;
    int arrayBound;
};

std::unordered_map<std::string, Symbol> symbolTable;

DataType evaluate_binary_type(DataType left, DataType right, int lineNo) {
    if (left == TYPE_ERROR || right == TYPE_ERROR) return TYPE_ERROR;
    if (left == TYPE_INT && right == TYPE_INT) return TYPE_INT;
    if ((left == TYPE_INT && right == TYPE_FLOAT) || (left == TYPE_FLOAT && right == TYPE_INT)) {
        return TYPE_FLOAT;
    }
    if (left == TYPE_FLOAT && right == TYPE_FLOAT) return TYPE_FLOAT;

    std::cout << "Line " << lineNo << ": Type Error Incompatible operands.\n";
    return TYPE_ERROR;
}

DataType verify_array_access(const std::string& name, DataType indexType, int indexVal, int lineNo) {
    if (!symbolTable.count(name)) {
        std::cout << "Line " << lineNo << ": Error: Variable '" << name << "' undeclared.\n";
        return TYPE_ERROR;
    }
    if (indexType != TYPE_INT) {
        std::cout << "Line " << lineNo << ": Type Error: Array index must evaluate to TYPE_INT.\n";
        return TYPE_ERROR;
    }
    if (indexVal < 0 || indexVal >= symbolTable[name].arrayBound) {
        std::cout << "Line " << lineNo << ": Error: Index " << indexVal << " out of bounds for '" << name << "'.\n";
        return TYPE_ERROR;
    }
    return symbolTable[name].type;
}

int main() {
    symbolTable["arr"] = {TYPE_INT, 10};

    evaluate_binary_type(TYPE_INT, TYPE_FLOAT, 1);
    evaluate_binary_type(TYPE_INT, TYPE_BOOL, 2);
    verify_array_access("arr", TYPE_INT, 5, 3);
    verify_array_access("arr", TYPE_FLOAT, 2, 4);
    verify_array_access("arr", TYPE_INT, 15, 5);

    std::cout << "\nLab No. 18 Name: Saugat Bikram Thapa /Roll No.: 80117731/ Section: A\n";
    return 0;
}