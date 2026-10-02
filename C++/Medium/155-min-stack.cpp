
#include <iostream>
#include <stack>
using namespace std;

/**
 * LeetCode 155: Min Stack
 *
 * Design a stack that supports push, pop, top, and
 * retrieving the minimum element in constant time O(1).
 *
 * Approach:
 * Use two stacks:
 * 1. st       - Stores all elements.
 * 2. minStack - Keeps track of the minimum elements.
 *
 * When pushing a value, add it to minStack if it is
 * less than or equal to the current minimum.
 *
 * When popping a value, remove it from minStack too
 * if it is equal to the current minimum.
 *
 * Time Complexity:
 * - push():   O(1)
 * - pop():    O(1)
 * - top():    O(1)
 * - getMin(): O(1)
 *
 * Space Complexity: O(n)
 * Both stacks may store up to n elements.
 */
class MinStack {
private:
    // Stores all the elements in the stack.
    stack<int> st;

    // Stores the minimum values encountered so far.
    stack<int> minStack;

public:
    /**
     * Initializes an empty MinStack.
     */
    MinStack() {
    }

    /**
     * Pushes a value onto the stack.
     *
     * @param value The integer to be added.
     *
     * Always push the value into the main stack.
     * If minStack is empty or the value is less than
     * or equal to the current minimum, also push it
     * into minStack.
     *
     * Time Complexity: O(1)
     */
    void push(int value) {
        st.push(value);

        // Update the minimum stack if necessary.
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    /**
     * Removes the top element from the stack.
     *
     * If the top element is also the current minimum,
     * remove it from minStack as well.
     *
     * This allows the previous minimum to become
     * the current minimum when necessary.
     *
     * Time Complexity: O(1)
     *
     * Note: Assumes the stack is not empty.
     */
    void pop() {
        // Check whether the top is also the minimum.
        if (minStack.top() == st.top()) {
            minStack.pop();
        }

        // Remove the top element from the main stack.
        st.pop();
    }

    /**
     * Returns the top element of the stack.
     *
     * Time Complexity: O(1)
     *
     * Note: Assumes the stack is not empty.
     *
     * @return The top element.
     */
    int top() {
        return st.top();
    }

    /**
     * Retrieves the minimum element in the stack.
     *
     * The minimum is always at the top of minStack,
     * so there is no need to traverse the main stack.
     *
     * Time Complexity: O(1)
     *
     * Note: Assumes the stack is not empty.
     *
     * @return The minimum element.
     */
    int getMin() {
        return minStack.top();
    }
};

/**
 * Usage:
 *
 * MinStack* obj = new MinStack();
 * obj->push(-2);
 * obj->push(0);
 * obj->push(-3);
 * obj->getMin(); // Returns -3
 * obj->pop();
 * obj->top();    // Returns 0
 * obj->getMin(); // Returns -2
 */