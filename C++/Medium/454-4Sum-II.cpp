/*
 * Problem: 454. 4Sum II
 * Platform: LeetCode
 * Difficulty: Medium
 * Topic: Arrays, Hash Map
 *
 * Description:
 * Given four integer arrays, count the number of combinations
 * (i, j, k, l) where the sum of their elements equals zero.
 *
 * Approach: Hash Map
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 *
 * Problem Link:
 * https://leetcode.com/problems/4sum-ii/
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2,
                     vector<int>& nums3, vector<int>& nums4) {

        // Hash map: stores each pair sum and its frequency
        unordered_map<int, int> mp;

        // Total number of valid combinations
        int count = 0;

        // Step 1: Calculate all pair sums from nums1 and nums2
        for (int a : nums1) {
            for (int b : nums2) {

                // Increase the frequency of the current sum
                mp[a + b]++;
            }
        }

        // Step 2: Check all pair sums from nums3 and nums4
        for (int c : nums3) {
            for (int d : nums4) {

                // Find the opposite sum needed to make zero
                int target = -(c + d);

                // Check if the required sum exists in the map
                if (mp.count(target)) {

                    // Add the frequency of matching pairs
                    count += mp[target];
                }
            }
        }

        // Return the total number of valid combinations
        return count;
    }
};

int main() {

    // Sample input arrays
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};

    // Create an object of the Solution class
    Solution sol;

    // Call the function and store the result
    int result = sol.fourSumCount(nums1, nums2, nums3, nums4);

    // Display the result
    cout << "LeetCode 454 - 4Sum II" << endl;
    cout << "Number of valid combinations: " << result << endl;

    return 0;
}
