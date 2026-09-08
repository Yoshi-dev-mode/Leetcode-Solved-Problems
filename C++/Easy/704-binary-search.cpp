#include <iostream>
#include <vector>

using namespace std;

/*
 * Binary Search
 *
 * Searches for a target value in a sorted array using the
 * binary search algorithm.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 *
 * Note:
 * The input array must be sorted in ascending order.
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {

        // Define the search range.
        // 'left' starts at the first index.
        // 'right' starts at the last index.
        int left = 0;
        int right = nums.size() - 1;

        // Continue searching while there is a valid range.
        while (left <= right) {

            // Find the middle index.
            // This formula avoids potential integer overflow
            // compared to (left + right) / 2.
            int mid = left + (right - left) / 2;

            // Target found at the middle index.
            if (nums[mid] == target) {
                return mid;
            }

            // The middle value is smaller than the target.
            // Therefore, the target can only be in the right half.
            else if (nums[mid] < target) {
                left = mid + 1;
            }

            // The middle value is greater than the target.
            // Therefore, the target can only be in the left half.
            else {
                right = mid - 1;
            }
        }

        // Target was not found in the array.
        return -1;
    }
};

