/* 

| Function     | Returns          | Meaning                |
| ------------ | ---------------- | ---------------------- |
| `st.empty()` | `true` / `false` | Is it empty?           |
| `st.size()`  | number           | How many elements?     |
| `st.top()`   | element          | What's on top?         |
| `st.push(x)` | nothing          | Add an element         |
| `st.pop()`   | nothing          | Remove the top element |


*/

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:

    /*
     * Problem: Valid Parentheses
     *
     * Approach:
     * Use a stack to keep track of opening brackets.
     *
     * - Opening brackets are pushed onto the stack.
     * - When a closing bracket is found, it must match
     *   the opening bracket at the top of the stack.
     * - If it doesn't match, the string is invalid.
     * - At the end, the stack must be empty.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    bool isValid(string s)
    {
        stack<char> st; // Makes a stack 

        for (char c : s)
        {
            // Store opening brackets in the stack.
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else
            {
                // A closing bracket without an opening bracket
                // is automatically invalid.
                if (st.empty())
                {
                    return false;
                }

                // Check if the closing bracket matches
                // the opening bracket at the top of the stack.
                if (c == ')' && st.top() != '(')
                {
                    return false;
                }

                if (c == ']' && st.top() != '[')
                {
                    return false;
                }

                if (c == '}' && st.top() != '{')
                {
                    return false;
                }

                // Remove the matched opening bracket.
                st.pop();
            }
        }

        // Valid only if there are no unmatched opening brackets.
        return st.empty();
    }
};
