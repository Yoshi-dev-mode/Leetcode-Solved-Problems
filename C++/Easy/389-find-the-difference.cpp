#include <iostream>
#include <string>

using namespace std;

/*
 * LeetCode 389: Find the Difference
 *
 * Problem:
 * Given two strings s and t, string t is created by randomly
 * shuffling string s and adding one extra character.
 *
 * The task is to find and return the extra character.
 *
 * Approach: Frequency Counter (Array)
 * 1. Create an array of 26 integers to count lowercase letters.
 * 2. Increment the frequency of each character in string s.
 * 3. Decrement the frequency of each character in string t.
 * 4. If a frequency becomes negative, that character is the
 *    extra character.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    char findTheDifference(string s, string t) {

        // Initialize an array to store the frequency of letters.
        // Index 0 represents 'a', index 1 represents 'b', etc.
        int frequency[26] = {0};

        // Count the occurrences of each character in string s.
        for (int ch : s) {

            // Convert the character into an index (0 to 25).
            frequency[ch - 'a']++;
        }

        // Subtract the occurrences of each character in string t.
        for (int ch : t) {

            // Decrease the frequency of the current character.
            frequency[ch - 'a']--;

            // A negative frequency means t contains an extra character.
            if (frequency[ch - 'a'] < 0) {

                // Return the character that was added to string t.
                return ch;
            }
        }

        // Fallback return (the problem guarantees an extra character).
        return ' ';
    }
};

/*
 * Main Function
 *
 * Used to test the solution locally.
 * LeetCode does not require this main() function when submitting.
 */
int main() {

    Solution solution;

    // Example input
    string s = "abcd";
    string t = "abcde";

    // Expected output: e
    cout << "Extra character: "
         << solution.findTheDifference(s, t)
         << endl;

    return 0;
}
