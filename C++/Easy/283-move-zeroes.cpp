#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    /**
     * Moves all zeros to the end of the array while
     * maintaining the relative order of non-zero elements.
     *
     * Approach:
     * - Use two pointers: i and j.
     * - i scans through the entire array.
     * - j keeps track of the position where the next
     *   non-zero element should be placed.
     * - When a non-zero element is found, swap it with
     *   the element at index j, then move j forward.
     *
     * This modifies the array in-place, so no extra array
     * is needed.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * Example:
     * Input:  [0, 1, 0, 3, 12]
     * Output: [1, 3, 12, 0, 0]
     */
    void moveZeroes(vector<int>& nums) {

        // j represents the position where the next
        // non-zero element should be placed.
        int j = 0;

        // i scans through every element in the array.
        for (int i = 0; i < nums.size(); i++) {

            // If the current element is not zero,
            // move it to the position indicated by j.
            if (nums[i] != 0) {

                // Swap the non-zero element with the
                // element at index j.
                swap(nums[i], nums[j]); // IMPORTANT FOR SWAPPING 

                // Move j to the next available position.
                j++;
            }
        }
    }
};