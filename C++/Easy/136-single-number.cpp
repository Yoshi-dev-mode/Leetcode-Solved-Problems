
/*
 * LeetCode 136: Single Number
 *
 * Problem:
 * Given a non-empty array of integers, every element appears twice
 * except for one element that appears only once.
 *
 * Find and return the element that appears only once.
 *
 * Example:
 * Input:  nums = {4, 1, 2, 1, 2}
 * Output: 4
 *
 * Approach: Bit Manipulation (XOR)
 *
 * Explanation:
 * XOR (^) has two important properties:
 * 1. A number XORed with itself becomes 0.
 *      a ^ a = 0
 *
 * 2. A number XORed with 0 remains unchanged.
 *      a ^ 0 = a
 *
 * By XORing all elements in the array, duplicate numbers
 * cancel each other out, leaving only the unique number.
 *
 * Time Complexity:  O(n)
 * We traverse the array exactly once.
 *
 * Space Complexity: O(1)
 * We use only one extra variable, result.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // Initialize result to 0.
        // XOR with 0 does not change a number.
        int result = 0;

        // Traverse every element in the array.
        for (int num : nums) {

            // XOR the current number with result.
            // Duplicate numbers cancel each other out.
            result ^= num;
        }

        // Return the remaining value,
        // which is the number that appears only once.
        return result;
    }
};

int main() {

    // Create an instance of the Solution class.
    Solution solution;

    // Example input array.
    vector<int> nums = {4, 1, 2, 1, 2};

    // Call singleNumber() and display the result.
    cout << "Single Number: "
         << solution.singleNumber(nums)
         << endl;

    return 0;
}
