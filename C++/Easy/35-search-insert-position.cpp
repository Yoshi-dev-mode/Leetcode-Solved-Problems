
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        // Perform binary search
        while (left <= right) {

            // Find the middle index
            int mid = left + (right - left) / 2;

            // Target is found
            if (nums[mid] == target) {
                return mid;
            }

            // Target is greater than middle value
            // Search the right half
            else if (nums[mid] < target) {
                left = mid + 1;
            }

            // Target is smaller than middle value
            // Search the left half
            else {
                right = mid - 1;
            }
        }

        // Left represents the correct insertion position
        return left;
    }
};

int main() {

    Solution solution;

    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    int result = solution.searchInsert(nums, target);

    cout << "Insert Position: " << result << endl;

    return 0;
}
