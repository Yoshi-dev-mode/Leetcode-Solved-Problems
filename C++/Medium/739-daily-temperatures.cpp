#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
    LeetCode: 739. Daily Temperatures

    Problem:
    Given an array of daily temperatures, return an array where
    answer[i] tells us how many days we have to wait until a
    warmer temperature.

    If there is no future day with a warmer temperature,
    answer[i] should be 0.

    Example:
    Input:
        [73, 74, 75, 71, 69, 72, 76, 73]

    Output:
        [1, 1, 4, 2, 1, 1, 0, 0]


    Approach:
    We use a Monotonic Stack.

    The stack stores the INDEXES of temperatures that are
    still waiting for a warmer day.

    We store indexes instead of temperatures because we need
    the indexes to calculate how many days we waited:

        right - left


    Example:

        Index:         0   1   2   3
        Temperature:  75  71  69  72

    When we reach 72:

        72 > 69
        72 > 71

    Therefore:

        answer[2] = 3 - 2 = 1
        answer[1] = 3 - 1 = 2


    Why does the stack work?

    The stack keeps temperatures in decreasing order.

    When the current temperature is warmer than the
    temperature at the top of the stack, we have found
    the answer for that previous day.

    We keep popping while the current temperature is warmer
    because one temperature can be the answer for multiple
    previous days.


    Time Complexity:
        O(n)

    Each index is pushed into the stack once and popped
    from the stack at most once.

    Space Complexity:
        O(n)

    In the worst case, all indexes can be stored in the stack.
*/

class Solution {

public:

    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // Create the answer array.
        // Initialize every value to 0 because if we never
        // find a warmer temperature, the answer remains 0.
        vector<int> answer(temperatures.size(), 0);

        // The stack stores indexes of temperatures
        // that are still waiting for a warmer temperature.
        stack<int> st;

        // Traverse the temperatures from left to right.
        for (int right = 0; right < temperatures.size(); right++) {

            /*
                Check the temperature at the top of the stack.

                If today's temperature is warmer than the
                temperature represented by the top index,
                today's temperature is the answer for that day.
            */
            while (!st.empty() &&
                   temperatures[right] > temperatures[st.top()]) {

                // Get the index of the previous temperature
                // that has now found a warmer day.
                int left = st.top();

                // Remove it because its answer has been found.
                st.pop();

                // Calculate how many days we waited.
                //
                // Example:
                // left  = 2
                // right = 5
                //
                // 5 - 2 = 3 days
                answer[left] = right - left;
            }

            /*
                Add today's index to the stack.

                It may need to wait for a warmer temperature
                in the future.
            */
            st.push(right);
        }

        // Return the completed answer array.
        return answer;
    }
};


int main() {

    // Create a Solution object.
    Solution solution;

    // Test input.
    vector<int> temp = {
        73, 74, 75, 71, 69, 72, 76, 73
    };

    // Call the solution.
    vector<int> result = solution.dailyTemperatures(temp);

    // Print the result in array format.
    cout << "[";

    for (int i = 0; i < result.size(); i++) {

        // Print a comma after every element except the last.
        if (i == result.size() - 1) {
            cout << result[i];
        }
        else {
            cout << result[i] << ",";
        }
    }

    cout << "]";

    return 0;
}

