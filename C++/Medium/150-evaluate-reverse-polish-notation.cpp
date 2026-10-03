#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

/**
 * Evaluate Reverse Polish Notation (RPN)
 *
 * Approach:
 * - Use a stack to store numbers.
 * - If the token is a number, push it onto the stack.
 * - If the token is an operator:
 *      1. Pop the right operand.
 *      2. Pop the left operand.
 *      3. Perform the operation.
 *      4. Push the result back onto the stack.
 *
 * Important:
 * The first value popped is the RIGHT operand because
 * a stack follows LIFO (Last In, First Out).
 *
 * Example:
 *      ["4", "2", "-"]
 *
 * Stack:
 *      [4, 2]
 *
 * First pop  -> num1 = 2 (right)
 * Second pop -> num2 = 4 (left)
 *
 * Therefore:
 *      num2 - num1
 *      4 - 2 = 2
 *
 * Time Complexity: O(n)
 *      We process every token once.
 *
 * Space Complexity: O(n)
 *      The stack can contain up to n numbers.
 */
class Solution {

public:

    int evalRPN(vector<string>& tokens) {

        // Stack used to store numbers while evaluating the expression
        stack<int> st;

        // Process each token from left to right
        for (string token : tokens) {

            // Check if the token is a number
            if (token != "+" &&
                token != "-" &&
                token != "/" &&
                token != "*") {

                // Convert the string to an integer and push it
                st.push(stoi(token));

            } 
            else {

                /*
                 * The first value popped is the RIGHT operand.
                 * The second value popped is the LEFT operand.
                 *
                 * Example:
                 * Stack: [4, 2]
                 *
                 * num1 = 2 -> right
                 * num2 = 4 -> left
                 */
                int num1 = st.top();
                st.pop();

                int num2 = st.top();
                st.pop();

                // Perform the operation and push the result back
                if (token == "+")
                    st.push(num2 + num1);

                else if (token == "-")
                    st.push(num2 - num1);

                else if (token == "*")
                    st.push(num2 * num1);

                else if (token == "/")
                    st.push(num2 / num1);
            }
        }

        // The final result is the only value left in the stack
        return st.top();
    }
};


int main() {

    Solution solution;

    // Example:
    // (10 * (6 / ((9 + 3) * -11))) + 17 + 5
    vector<string> nums = {
        "10", "6", "9", "3", "+", "-11",
        "*", "/", "*", "17", "+", "5", "+"
    };

    cout << solution.evalRPN(nums);

    return 0;
}

