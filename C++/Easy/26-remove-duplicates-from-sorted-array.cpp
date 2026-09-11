#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    /**
     * Removes duplicates from a sorted array in-place.
     *
     * Since the array is sorted, duplicate values are
     * always next to each other.
     *
     * Approach:
     * - Use two pointers, i and j.
     * - i scans through the array to find unique elements.
     * - j keeps track of the position where the next unique
     *   element should be placed.
     * - When nums[i] is different from the previous element,
     *   it is a new unique value, so place it at nums[j].
     *
     * The first element is always unique, so j starts at 1.
     *
     * The function returns j, which represents the number
     * of unique elements in the array.
     *
     * Example:
     * Input:  [1,1,2]
     * Output: 2
     * Array:  [1,2,_]
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    int removeDuplicates(vector<int>& nums) {

        // An empty array contains no unique elements.
        if (nums.empty()) {
            return 0;
        }

        // j represents the position where the next
        // unique element should be placed.
        int j = 1;

        // Start from the second element and compare
        // each element with the previous element.
        for (int i = 1; i < nums.size(); i++) {

            // If the current element is different from
            // the previous element, we found a unique value.
            if (nums[i] != nums[i - 1]) {

                // Place the unique value at position j.
                nums[j] = nums[i];

                // Move j to the next available position.
                j++;
            }
        }

        // j is the number of unique elements.
        return j;
    }
};