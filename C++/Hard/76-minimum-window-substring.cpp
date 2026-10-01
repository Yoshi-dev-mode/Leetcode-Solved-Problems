
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

/**
 * LeetCode 76: Minimum Window Substring
 *
 * Approach:
 * Sliding Window + Two Pointers + Frequency Array
 *
 * Goal:
 * Find the smallest substring of s that contains all
 * the characters of t, including duplicate characters.
 *
 * Return an empty string if no valid substring exists.
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(1) - fixed-size frequency array
 *
 * n = length of s
 * m = length of t
 */
class Solution {
public:
    string minWindow(string s, string t) {

        // If t is longer than s, a valid window is impossible.
        if (t.size() > s.size()) {
            return "";
        }

        // Store the required frequency of each ASCII character.
        vector<int> freq(128, 0);

        // Count how many times each character appears in t.
        for (char letter : t) {
            freq[letter]++;
        }

        // Two pointers define the current sliding window.
        int left = 0;

        // Starting index of the smallest valid window found.
        int minLeft = 0;

        // Initialize the minimum length to the largest int.
        int minLength = INT_MAX;

        // Number of required character occurrences still missing.
        int requirement = t.size();

        // Expand the window by moving the right pointer.
        for (int right = 0; right < s.size(); right++) {

            // If the current character is still needed,
            // decrease the number of missing occurrences.
            if (freq[s[right]] > 0) {
                requirement--;
            }

            // Include the current character in the window.
            // A negative frequency indicates an extra character.
            freq[s[right]]--;

            // When requirement is zero, the window is valid.
            // Try shrinking it to find a smaller valid window.
            while (requirement == 0) {

                // Calculate the current window's length.
                int windowLength = right - left + 1;

                // Update the minimum window if this one is smaller.
                if (windowLength < minLength) {
                    minLength = windowLength;
                    minLeft = left;
                }

                // Remove the leftmost character from the window.
                // Restore its frequency because it is no longer
                // included in the current window.
                freq[s[left]]++;

                // If the frequency becomes positive, we now need
                // another occurrence of this character.
                if (freq[s[left]] > 0) {
                    requirement++;
                }

                // Move the left pointer to shrink the window.
                left++;
            }
        }

        // If no valid window was found, return an empty string.
        if (minLength == INT_MAX) {
            return "";
        }

        // Extract and return the smallest valid substring.
        return s.substr(minLeft, minLength);
    }
};

int main() {
    Solution solution;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    // Expected output: BANC
    cout << solution.minWindow(s, t) << endl;

    return 0;
}