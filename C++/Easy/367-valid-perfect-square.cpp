
#include <iostream>
using namespace std;

/*
 * LEETCODE #367: VALID PERFECT SQUARE
 *
 * Description:
 * Given a positive integer num, determine whether
 * it is a perfect square without using sqrt().
 *
 * Algorithm: Binary Search
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 *
 * Examples:
 * Input: 16  -> Output: true
 * Input: 14  -> Output: false
 * Input: 25  -> Output: true
 */

class Solution {
public:
    bool isPerfectSquare(int num) {

        // Step 1: Handle the smallest perfect square.
        // 1 * 1 = 1, so return true.
        if (num == 1) {
            return true;
        }

        // Step 2: Set the binary search boundaries.
        int left = 1;
        int right = num / 2;

        // Step 3: Continue searching while the range is valid.
        while (left <= right) {

            // Find the middle number without overflow.
            int mid = left + (right - left) / 2;

            // Use long long to prevent integer overflow.
            // Casting mid before multiplication ensures
            // the result can store very large numbers.
            long long square = (long long)mid * mid;

            // Step 4: Check if mid is the square root.
            if (square == num) {
                return true;
            }

            // If the square is smaller than num,
            // search the right half.
            else if (square < num) {
                left = mid + 1;
            }

            // If the square is larger than num,
            // search the left half.
            else {
                right = mid - 1;
            }
        }

        // Step 5: No integer square root was found.
        return false;
    }
};

// Main function for testing the program.
int main() {
    Solution sol;
    int num;

    // Ask the user to enter a number.
    cout << "Enter a positive integer: ";
    cin >> num;

    // Call the function and display the result.
    if (sol.isPerfectSquare(num)) {
        cout << "Output: true" << endl;
    }
    else {
        cout << "Output: false" << endl;
    }

    return 0;
}
