#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

/*
    LeetCode: 496 - Next Greater Element I

    Problem:
    For each element in nums1, find the first greater element
    to its right in nums2.

    If there is no greater element, return -1.

    Example:

    nums1 = [4, 1, 2]
    nums2 = [1, 3, 4, 2]

    Result:
    [-1, 3, -1]

    Explanation:
    - 4 -> No greater element to its right -> -1
    - 1 -> Next greater element is 3
    - 2 -> No greater element to its right -> -1


    Approach:
    We use a Monotonic Stack.

    The stack stores numbers that are still waiting
    to find their next greater element.

    While processing nums2:
    - If the current number is greater than the top of
      the stack, then the current number is the next
      greater element of the stack's top.
    - Store this relationship in an unordered_map.
    - Pop the smaller number because its answer is found.
    - Push the current number into the stack.

    After processing nums2:
    Any numbers still inside the stack do not have
    a greater element to their right, so their answer
    is -1.

    Time Complexity:
    O(n + m)

    Space Complexity:
    O(n)

    Where:
    n = nums2.size()
    m = nums1.size()
*/

class Solution {

public:

    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {

        // Stores the relationship:
        // number -> next greater element
        //
        // Example:
        // 1 -> 3
        // 3 -> 4
        // 4 -> -1
        unordered_map<int, int> mp;

        // Monotonic decreasing stack.
        //
        // Numbers remain in the stack until
        // we find a greater number for them.
        stack<int> st;

        // Process nums2 from left to right.
        for (int num : nums2) {

            /*
                If the current number is greater than
                the number at the top of the stack,
                we found the next greater element.

                Example:

                Stack:
                [1]

                Current number:
                3

                Since:
                3 > 1

                We know:
                1 -> 3
            */
            while (!st.empty() && num > st.top()) {

                // The current number is the next
                // greater element of the stack top.
                mp[st.top()] = num;

                // Remove the number because
                // its next greater element is found.
                st.pop();
            }

            // The current number is now waiting
            // for its next greater element.
            st.push(num);
        }

        /*
            Any numbers remaining in the stack
            do not have a greater element to their right.

            Therefore, their answer is -1.
        */
        while (!st.empty()) {

            mp[st.top()] = -1;

            st.pop();
        }

        // Store the final answers for nums1.
        vector<int> res;

        // Look up each number from nums1
        // in our next-greater-element map.
        for (int num : nums1) {

            res.push_back(mp[num]);
        }

        return res;
    }
};


int main() {

    // Create a Solution object.
    Solution solution;

    // First array: elements we need answers for.
    vector<int> nums1 = {4, 1, 2};

    // Second array: used to find the
    // next greater elements.
    vector<int> nums2 = {1, 3, 4, 2};

    // Call the solution.
    vector<int> res = solution.nextGreaterElement(nums1, nums2);

    // Print the result.
    for (int r : res) {
        cout << r << " ";
    }

    return 0;
}

