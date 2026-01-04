//  Yonatan Ayisheshim [BDU1508377]
//  Principle of Compiler Design - Assignment 1
//  ID No.   : BDU1508377
//  Question 1: Check for Balanced Square Brackets
//
//  Description:
//  This program checks whether a given input string contains
//  balanced square brackets '[' and ']'. It uses a stack-based
//  approach, which is commonly applied in syntax analysis
//  to validate properly nested symbols.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
 * Input         : A string containing characters and brackets
 * Output        : true  -> if brackets are balanced
 *                 false -> otherwise
 */
bool isBalanced(const string& input) {
    stack<char> st;

    for (char ch : input) {
        if (ch == '[') {
            st.push(ch);
        } else if (ch == ']') {
            if (st.empty()) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string input;

    cout << "Enter a string: ";
    cin >> input;

    if (isBalanced(input)) {
        cout << "The string has balanced square brackets." << endl;
    } else {
        cout << "The string does not have balanced square brackets." << endl;
    }

    return 0;
}