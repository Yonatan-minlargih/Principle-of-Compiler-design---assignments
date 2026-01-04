// Yonatan Ayisheshim [BDU1508377]
// Principle of Compiler Design - Assignment 3
// Question 56: Implement Semantic Checks for Return Type Consistency
//
//   Description:
//   This program demonstrates how a compiler performs semantic
//   checks to ensure that return statements in a function match
//   the declared return type of that function.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum DataType {
    INT,
    FLOAT,
    VOID,
    INVALID
};

string typeToString(DataType type) {
    switch (type) {
        case INT: return "int";
        case FLOAT: return "float";
        case VOID: return "void";
        default: return "invalid";
    }
}

struct ReturnStatement {
    bool hasExpression;
    DataType exprType;
};

struct FunctionNode {
    string name;
    DataType returnType;
    vector<ReturnStatement> returnStatements;
};

void checkReturnTypeConsistency(const FunctionNode& func) {
    bool hasReturn = false;

    for (const auto& ret : func.returnStatements) {
        hasReturn = true;

        // Rule 1: Void function should not return a value
        if (func.returnType == VOID && ret.hasExpression) {
            cout << "Semantic Error: Function '" << func.name
                 << "' is void but returns a value.\n";
        }

        // Rule 2: Non-void function must return a value
        if (func.returnType != VOID && !ret.hasExpression) {
            cout << "Semantic Error: Function '" << func.name
                 << "' must return a value of type "
                 << typeToString(func.returnType) << ".\n";
        }

        // Rule 3: Return type must match declared type
        if (ret.hasExpression &&
            func.returnType != VOID &&
            ret.exprType != func.returnType) {

            cout << "Semantic Error: Return type mismatch in function '"
                 << func.name << "'. Expected "
                 << typeToString(func.returnType)
                 << " but found "
                 << typeToString(ret.exprType) << ".\n";
        }
    }

    // Rule 4: Missing return in non-void function
    if (func.returnType != VOID && !hasReturn) {
        cout << "Semantic Error: Function '" << func.name
             << "' must return a value.\n";
    }
}

int main() {

    FunctionNode func;
    func.name = "intfunction";
    func.returnType = INT;

    ReturnStatement r1;
    r1.hasExpression = true;
    r1.exprType = FLOAT;

    func.returnStatements.push_back(r1);

    checkReturnTypeConsistency(func);

    return 0;
}