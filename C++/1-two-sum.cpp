// 1-TWO-SUM PROBLEM USING C++

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // Hash map stores each number and its corresponding index.
        // This allows us to check for a required number in O(1) average time.
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
        {
            // Calculate the number needed to reach the target.
            // Example: target = 9, nums[i] = 7 → complement = 2.
            int complement = target - nums[i];

            // Check if the complement has already appeared in the array.
            // map.end() represents the position after the last element,
            // so if find() is not equal to end(), the complement was found.
            if (map.find(complement) != map.end())
            {
                // Return the index of the complement and the current index.
                return {map[complement], i};
            }

            // Store the current number and its index for future lookups.
            map[nums[i]] = i;
        }

        // Return an empty vector if no valid pair is found.
        return {};
    }
};
