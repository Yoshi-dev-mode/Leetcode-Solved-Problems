
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * @class Solution
 * @brief Finds the unique elements that appear in both arrays.
 *
 * This solution uses an unordered_set to efficiently check whether
 * elements from the second array exist in the first array.
 */
class Solution {
public:
    /**
     * @brief Computes the intersection of two integer arrays.
     *
     * An element is included in the result only once, even if it
     * appears multiple times in either input array.
     *
     * @param nums1 The first integer array.
     * @param nums2 The second integer array.
     * @return A vector containing the unique common elements.
     *
     * Time Complexity: O(n + m) average case
     * Space Complexity: O(n + k), where k is the number of
     *                  unique elements in the result.
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Create a hash set to store unique elements from nums1.
        unordered_set<int> s;

        // Insert every element of nums1 into the hash set.
        // Duplicate values are automatically ignored.
        for (int i = 0; i < nums1.size(); i++) {
            s.insert(nums1[i]);
        }

        // Store the unique common elements.
        vector<int> res;

        // Traverse nums2 and check whether each element exists in s.
        for (int i = 0; i < nums2.size(); i++) {

            // count() returns 1 if the element exists, otherwise 0.
            if (s.count(nums2[i])) {

                // Add the common element to the result.
                res.push_back(nums2[i]);

                // Remove the element to prevent duplicate results.
                s.erase(nums2[i]);
            }
        }

        return res;
    }
};

/**
 * @brief Program entry point.
 *
 * Demonstrates how to call the intersection function
 * and print the resulting vector.
 */
int main() {

    Solution solution;

    // Example input arrays.
    vector<int> num1 = {1, 2, 2, 3, 4};
    vector<int> num2 = {2, 2, 3, 5};

    // Compute the intersection of the two arrays.
    vector<int> result = solution.intersection(num1, num2);

    // Print the resulting vector.
    cout << "Intersection: ";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}