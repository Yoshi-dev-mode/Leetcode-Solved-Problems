
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * LeetCode 567: Permutation in String
 *
 * Approach: Sliding Window + Frequency Array
 *
 * Description:
 * Given two strings, s1 and s2, determine whether s2
 * contains a permutation of s1.
 *
 * A permutation is a rearrangement of characters.
 * The order may differ, but the character frequencies
 * must remain the same.
 *
 * Example:
 * s1 = "ab"
 * s2 = "eidbaooo"
 *
 * Output: true
 *
 * Explanation:
 * The substring "ba" is a permutation of "ab".
 *
 * Time Complexity: O(n2)
 * Space Complexity: O(1)
 *
 * n2 = length of s2
 * The frequency arrays have a fixed size of 26,
 * assuming lowercase English letters.
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // Get the lengths of both strings.
        int n1 = s1.size();
        int n2 = s2.size();

        // A permutation of s1 cannot be longer than s2.
        if (n1 > n2) {
            return false;
        }

        /*
         * Create frequency arrays for lowercase letters.
         *
         * answer: Stores the frequency of each character
         *          in s1.
         *
         * windowS2: Stores the frequency of each character
         *            in the current window of s2.
         *
         * Each array has 26 elements, one for each
         * lowercase English letter (a-z).
         */
        vector<int> answer(26, 0);
        vector<int> windowS2(26, 0);

        /*
         * Initialize the frequency arrays.
         *
         * The initial window size is equal to the length
         * of s1. Count the characters in s1 and the first
         * window of s2.
         *
         * s[i] - 'a' converts a lowercase letter into
         * an array index from 0 to 25.
         */
        for (int i = 0; i < n1; i++) {
            answer[s1[i] - 'a']++;
            windowS2[s2[i] - 'a']++;
        }

        // Check whether the first window is a permutation.
        if (answer == windowS2) {
            return true;
        }

        /*
         * Slide the fixed-size window across s2.
         *
         * right: Index of the character entering the window.
         *
         * right - n1: Index of the character leaving
         *             the window.
         *
         * Instead of recounting every character, update
         * the frequencies as the window moves.
         */
        for (int right = n1; right < n2; right++) {

            // Add the new character entering the window.
            windowS2[s2[right] - 'a']++;

            // Remove the character leaving the window.
            windowS2[s2[right - n1] - 'a']--;

            /*
             * Compare the character frequencies.
             *
             * If both arrays are equal, the current window
             * is a permutation of s1.
             */
            if (answer == windowS2) {
                return true;
            }
        }

        // No window matched the character frequencies.
        return false;
    }
};

int main() {
    Solution solution;

    string s1 = "bac";
    string s2 = "eibabc";

    // Expected output: 1 (true)
    cout << solution.checkInclusion(s1, s2) << endl;

    return 0;
}