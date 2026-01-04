/***************************************************************
 * Course        : Principles of Compiler Design
 * Assignment    : Syntax Analysis Individual Assignment
 * ID No.   : BDU1508377
 * Name of writer : Yonatan Ayisheshim
 *
 * Description:
 * This program checks whether a given input string contains
 * balanced square brackets '[' and ']'. It uses a stack-based
 * approach, which is commonly applied in syntax analysis
 * to validate properly nested symbols.
 ***************************************************************/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
 * Function Name : isBalanced
 * Purpose       : Checks if square brackets in the input string
 *                 are balanced.
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
        cout << "The string does NOT have balanced square brackets." << endl;
    }

    return 0;
}