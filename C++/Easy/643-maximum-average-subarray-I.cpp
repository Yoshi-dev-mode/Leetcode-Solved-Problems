#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        /*
        Sliding Window Approach

        We need to find the maximum sum of any
        subarray containing exactly k elements.

        Instead of calculating the sum from scratch
        for every window, we keep a running sum.

        When the window moves:
        - Remove the element leaving the window
        - Add the new element entering the window
        */

        // Calculate the sum of the first k elements
        int wSum = 0;

        for (int i = 0; i < k; i++)
        {
            wSum += nums[i];
        }

        // The first window is our initial maximum sum
        int maxSum = wSum;

        /*
        Slide the window through the rest of the array.

        Example:

        nums = [1, 12, -5, -6, 50, 3]
        k = 4

        First window:
        [1, 12, -5, -6]

        Next window:
        [12, -5, -6, 50]

        We remove nums[i - k] and add nums[i].
        */

        for (int i = k; i < nums.size(); i++)
        {
            // Remove the element that is leaving the window
            wSum -= nums[i - k];

            // Add the new element entering the window
            wSum += nums[i];

            // Update the maximum sum if this window is larger
            maxSum = max(maxSum, wSum);
        }

        /*
        Average = Sum / Number of Elements

        Cast maxSum to double so that we get
        a decimal result instead of integer division.
        */

        return (double)maxSum / k;
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    cout << solution.findMaxAverage(nums, k);
}

