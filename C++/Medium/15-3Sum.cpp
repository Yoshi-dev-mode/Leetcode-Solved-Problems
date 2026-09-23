#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;

        // Sort the array first.
        // This allows us to use the two-pointer technique
        // and easily skip duplicate values.
        sort(nums.begin(), nums.end());

        // Fix one number at a time using i.
        for (int i = 0; i < nums.size(); i++)
        {
            // Since the array is sorted, if nums[i] is positive,
            // all numbers after it will also be positive.
            // Therefore, their sum can never be 0.
            if (nums[i] > 0)
            {
                break;
            }

            // Skip duplicate values for the first number.
            // This prevents duplicate triplets.
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // Two pointers:
            // left starts immediately after i.
            // right starts at the end of the array.
            int left = i + 1;
            int right = nums.size() - 1;

            // Continue searching while the two pointers
            // have not crossed each other.
            while (left < right)
            {
                // Calculate the sum of the three numbers.
                int sum = nums[i] + nums[left] + nums[right];

                // We found a valid triplet.
                if (sum == 0)
                {
                    res.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    // Move both pointers after finding a triplet.
                    left++;
                    right--;

                    // Skip duplicate values on the right.
                    // The boundary check prevents accessing
                    // outside the vector.
                    while (left < right &&
                           nums[right] == nums[right + 1])
                    {
                        right--;
                    }

                    // Skip duplicate values on the left.
                    // The boundary check prevents accessing
                    // outside the vector.
                    while (left < right &&
                           nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }
                // The sum is too large.
                // Move right to a smaller number.
                else if (sum > 0)
                {
                    right--;
                }
                // The sum is too small.
                // Move left to a larger number.
                else
                {
                    left++;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = solution.threeSum(nums);

    // Print the result.
    cout << "[";

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";

        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];

            // Print a comma only if this is NOT
            // the last element of the current triplet.
            if (j < result[i].size() - 1)
            {
                cout << ",";
            }
        }

        cout << "]";

        // Print a comma only if this is NOT
        // the last triplet.
        if (i < result.size() - 1)
        {
            cout << ",";
        }
    }

    cout << "]";

    return 0;
}