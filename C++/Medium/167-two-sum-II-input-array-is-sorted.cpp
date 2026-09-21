#include <iostream>
#include <vector>

using namespace std;

/**
 * LeetCode 167 - Two Sum II: Input Array Is Sorted
 *
 * Given a 1-indexed array of integers `numbers` that is already sorted
 * in non-decreasing order, find two numbers such that they add up to
 * a specific target.
 *
 * Return the indices of the two numbers.
 *
 * The array is guaranteed to have exactly one solution.
 *
 * Example:
 * numbers = [2, 3, 4]
 * target = 6
 *
 * 2 + 4 = 6
 *
 * Answer:
 * [1, 3]
 *
 * Approach:
 * Use the two-pointer technique.
 *
 * - `left` starts at the beginning of the array.
 * - `right` starts at the end of the array.
 *
 * Since the array is sorted:
 *
 * - If the sum is too small, move `left` forward.
 * - If the sum is too large, move `right` backward.
 * - If the sum equals the target, we found the answer.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        // Start one pointer at the beginning.
        int left = 0;

        // Start the other pointer at the end.
        int right = numbers.size() - 1;

        // Continue until the two pointers meet.
        while (left < right)
        {
            // Calculate the sum of the two values.
            int sum = numbers[left] + numbers[right];

            // If the sum equals the target, return the 1-based indices.
            if (sum == target)
            {
                return {left + 1, right + 1};
            }

            // If the sum is too small, we need a larger value.
            // Since the array is sorted, move the left pointer forward.
            else if (sum < target)
            {
                left++;
            }

            // If the sum is too large, we need a smaller value.
            // Move the right pointer backward.
            else
            {
                right--;
            }
        }

        // Return an empty vector if no solution is found.
        return {};
    }
};

int main()
{
    Solution solution;

    vector<int> numbers = {2, 3, 4};
    int target = 6;

    // Call the twoSum function and store the result.
    vector<int> result = solution.twoSum(numbers, target);

    // Print the result in array format.
    cout << "[";

    for (int i = 0; i < result.size(); i++)
    {
        // Don't print a comma after the last element.
        if (i == result.size() - 1)
        {
            cout << result[i];
        }
        else
        {
            cout << result[i] << ",";
        }
    }

    cout << "]";
}