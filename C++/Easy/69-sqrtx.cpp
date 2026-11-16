
#include <iostream>
using namespace std;

class Solution {
public:

    /**
     * Calculates the integer square root of x.
     *
     * Uses Binary Search to find the largest integer
     * whose square is less than or equal to x.
     *
     * @param x Non-negative integer input.
     * @return Integer square root rounded down.
     *
     * Time Complexity: O(log x)
     * Space Complexity: O(1)
     */
    int mySqrt(int x) {

        // Handle edge cases: 0 and 1
        if (x < 2) {
            return x;
        }

        // Initialize binary search boundaries
        int left = 1;
        int right = x / 2;

        // Store the largest valid answer
        int answer = 0;

        // Continue while the search range is valid
        while (left <= right) {

            // Calculate the middle value
            int mid = left + (right - left) / 2;

            // Check if mid is a valid square root
            // Division prevents integer overflow
            if (mid <= x / mid) {

                // Save the valid answer
                answer = mid;

                // Search for a larger possible answer
                left = mid + 1;

            } else {

                // Mid is too large, search the left side
                right = mid - 1;
            }
        }

        // Return the integer square root
        return answer;
    }
};

// Main function
int main() {

    // Create an object of the Solution class
    Solution sol;

    int x;

    // Ask the user for input
    cout << "Enter a non-negative integer: ";
    cin >> x;

    // Validate the input
    if (x < 0) {
        cout << "Invalid input! Please enter a non-negative integer." << endl;
        return 1;
    }

    // Call the mySqrt function
    int result = sol.mySqrt(x);

    // Display the result
    cout << "Square root: " << result << endl;

    return 0;
}
