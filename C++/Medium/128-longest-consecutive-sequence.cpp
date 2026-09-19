#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * LeetCode 128 - Longest Consecutive Sequence
 *
 * Approach:
 * 1. Store all numbers in an unordered_set for O(1) average lookup.
 * 2. For each number, check if it is the START of a sequence.
 *    - If num - 1 does not exist, then num is the beginning.
 * 3. Starting from that number, keep checking num + 1.
 * 4. Track the length of the current sequence.
 * 5. Keep the maximum length found.
 *
 * Example:
 * nums = {300, 4, 200, 1, 2, 3, 5}
 *
 * Consecutive sequence:
 * 1 -> 2 -> 3 -> 4 -> 5
 *
 * Answer: 5
 *
 * Time Complexity: O(n) average
 * Space Complexity: O(n)
 */
class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        // Store all numbers in an unordered_set.
        // This allows us to quickly check if a number exists.
        unordered_set<int> set(nums.begin(), nums.end());

        // Stores the longest consecutive sequence found so far.
        int longest = 0;

        // Check every number in the original vector.
        for (int num : set)
        {
            // If num - 1 does NOT exist, then num is the
            // beginning of a consecutive sequence.
            if (set.find(num - 1) == set.end())
            {
                // Start counting from the current number.
                int currLength = 1;
                int currNum = num;

                // Keep checking if the next consecutive number exists.
                while (set.find(currNum + 1) != set.end())
                {
                    // Move to the next number.
                    currNum++;

                    // Increase the length of the sequence.
                    currLength++;
                }

                // Update the longest sequence if the current
                // sequence is longer.
                longest = max(longest, currLength);
            }
        }

        // Return the length of the longest consecutive sequence.
        return longest;
    }
};

int main()
{
    Solution solution;

    vector<int> storage = {300,4,4,4,4,4, 200, 1, 2, 3, 5};

    // Expected output: 5
    cout << solution.longestConsecutive(storage);
}