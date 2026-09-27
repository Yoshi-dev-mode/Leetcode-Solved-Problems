
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    LeetCode 1004: Max Consecutive Ones III

    Approach: Sliding Window (Two Pointers)

    Problem:
    Given a binary array nums and an integer k, find the
    maximum number of consecutive 1s in the array if you
    can flip at most k zeros into ones.

    Idea:
    Use a sliding window to find the longest subarray
    containing at most k zeros.

    - right expands the window by moving forward.
    - left shrinks the window when it contains too many zeros.
    - zeros tracks the number of zeros in the current window.
    - maxLength stores the longest valid window found.

    Time Complexity: O(n)
        Each element is visited at most twice: once by
        right and once by left.

    Space Complexity: O(1)
        Only a fixed number of variables are used.
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        // Left boundary of the sliding window.
        int left = 0;

        // Stores the maximum valid window length.
        int maxLength = 0;

        // Counts the number of zeros in the current window.
        int zeros = 0;

        // Expand the window by moving the right pointer.
        for (int right = 0; right < nums.size(); right++) {

            // If the current element is zero,
            // increment the zero counter.
            if (nums[right] == 0) {
                zeros++;
            }

            // Shrink the window while the number of zeros
            // exceeds the maximum allowed flips (k).
            while (zeros > k) {

                // If the leftmost element is zero,
                // it is no longer part of the window.
                if (nums[left] == 0) {
                    zeros--;
                }

                // Move the left pointer to shrink the window.
                left++;
            }

            // The current window is now valid because
            // it contains at most k zeros.
            // Update the maximum window length.
            maxLength = max(maxLength, right - left + 1);
        }

        // Return the longest valid window found.
        return maxLength;
    }
};

int main() {

    // Create an instance of the Solution class.
    Solution solution;

    // Sample binary array.
    vector<int> binary = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};

    // Maximum number of zeros that can be flipped.
    int k = 2;

    // Display the maximum number of consecutive ones.
    cout << solution.longestOnes(binary, k) << endl;

    return 0;
}