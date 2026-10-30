/*
 * LeetCode 1207: Unique Number of Occurrences
 *
 * Problem:
 * Given an array of integers, determine whether the number of
 * occurrences of each distinct value is unique.
 *
 * Approach:
 * 1. Use an unordered_map to count the frequency of each number.
 * 2. Use an unordered_set to track frequencies that have already
 *    been encountered.
 * 3. If a frequency appears more than once, return false.
 * 4. If all frequencies are unique, return true.
 *
 * Data Structures:
 * - unordered_map<int, int>: Stores each number and its frequency.
 * - unordered_set<int>: Stores frequencies that have been checked.
 *
 * Time Complexity: O(n) average
 *   - Count the occurrences of all n elements.
 *   - Check the frequency of each distinct number.
 *
 * Space Complexity: O(n)
 *   - The hash map and hash set may store up to n elements each.
 *
 * Author: Yoshi-dev-mode
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * Determines whether every distinct number has a unique frequency.
     *
     * @param arr A vector of integers.
     * @return true if all frequencies are unique; otherwise, false.
     */
    bool uniqueOccurrences(vector<int>& arr) {

        // Step 1: Count the occurrences of each number.
        // The key represents the number, and the value represents
        // how many times that number appears in the array.
        unordered_map<int, int> frequency;

        for (int num : arr) {
            frequency[num]++;
        }

        // Step 2: Create a set to track previously encountered frequencies.
        // A set allows us to check whether a frequency already exists.
        unordered_set<int> seen;

        // Step 3: Examine the frequency of each distinct number.
        for (auto pair : frequency) {

            // pair.first represents the number.
            // pair.second represents its frequency.

            // If this frequency already exists in the set,
            // two different numbers share the same frequency.
            if (seen.count(pair.second)) {
                return false;
            }

            // Record the frequency so we can detect duplicates later.
            seen.insert(pair.second);
        }

        // Step 4: No duplicate frequencies were found.
        return true;
    }
};

/**
 * Main function for local testing.
 *
 * Note:
 * LeetCode provides its own test runner, so this main() function
 * is only needed when compiling and running the program locally.
 */
int main() {

    Solution solution;

    // Example input: 1 appears 3 times, 2 appears 2 times,
    // and 3 appears 1 time.
    vector<int> arr = {1, 2, 2, 1, 1, 3};

    // Check whether all occurrence counts are unique.
    bool result = solution.uniqueOccurrences(arr);

    // Display the boolean result as "true" or "false".
    cout << boolalpha;
    cout << "Unique Occurrences: " << result << endl;

    return 0;
}

/*
 * Expected Output:
 *
 * Unique Occurrences: true
 */