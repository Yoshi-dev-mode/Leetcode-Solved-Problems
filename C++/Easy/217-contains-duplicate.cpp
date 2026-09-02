#include <iostream>
#include <vector>
#include <unordered_set>

// #include <unordered_map>

using namespace std;

/*
    ============================================================
    Contains Duplicate - Using unordered_set
    ============================================================

    Problem:
    Given an integer array, determine whether any value appears
    at least twice.

    Approach:
    1. Create an unordered_set to store numbers we have already seen.
    2. Loop through every number in the array.
    3. Check if the current number already exists in the set.
       - If it exists, a duplicate was found -> return true.
       - If it does not exist, insert it into the set.
    4. If the loop finishes without finding a duplicate,
       return false.

    Why unordered_set?
    We only need to know whether a number has appeared before.
    We do NOT need to store additional information such as
    the number's index.

    Average Time Complexity: O(n)
    Worst-Case Time Complexity: O(n^2)
    Space Complexity: O(n)

    where n = number of elements in nums.
*/

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        // Stores numbers that we have already encountered.
        unordered_set<int> s;

        // Go through every element in the array.
        for (int i = 0; i < nums.size(); i++)
        {
            // Check whether nums[i] already exists in the set.
            if (s.find(nums[i]) != s.end())
            {
                // Number already exists -> duplicate found.
                return true;
            }

            // Number hasn't been seen before, so store it.
            s.insert(nums[i]);
        }

        // No duplicate was found.
        return false;
    }
};