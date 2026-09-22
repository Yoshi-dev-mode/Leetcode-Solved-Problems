#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 11: Container With Most Water

    Problem:
    Given an array of heights, each value represents the height
    of a vertical line.

    Choose two lines that can form a container containing the
    maximum amount of water.

    The amount of water is calculated using:

        Area = width × height

    where:

        width  = right - left
        height = min(height[left], height[right])

    Approach:
    Use the Two Pointer technique.

    - Start with one pointer at the beginning.
    - Start another pointer at the end.
    - Calculate the area between them.
    - Move the pointer pointing to the shorter line.
    - Continue until the two pointers meet.

    Why move the shorter line?

    The shorter line limits the amount of water we can hold.
    Moving the taller line cannot increase the container's height,
    because the shorter line is still the limiting factor.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        // Start with the left pointer at the first element.
        int left = 0;

        // Start with the right pointer at the last element.
        int right = height.size() - 1;

        // Store the maximum area found so far.
        int maxA = 0;

        // Continue while the two pointers have not met.
        while (left < right)
        {
            /*
                Calculate the current container area.

                Width:
                    right - left

                Height:
                    The shorter of the two lines.
            */

            // THE MOST IMPORTANT FORMULA TO GET THE AREA
            int area = (right - left) *
                       min(height[left], height[right]); 

            // Update maxA if the current area is larger.
            maxA = max(maxA, area);

            /*
                Move the pointer pointing to the shorter line.

                The shorter line limits the water level, so moving
                the taller line would not give us a chance to increase
                the height of the container.
            */
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        // Return the largest area found.
        return maxA;
    }
};

int main()
{
    Solution solution;

    // Example input from the problem.
    vector<int> num = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Expected output: 49
    cout << solution.maxArea(num);

    return 0;
}
