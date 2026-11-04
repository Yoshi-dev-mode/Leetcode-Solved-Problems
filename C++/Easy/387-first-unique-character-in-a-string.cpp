#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/*
    LeetCode 387: First Unique Character in a String

    Problem:
    Given a string, find the first character that appears only once.
    Return its index. If no unique character exists, return -1.

    Approach: Hash Map (unordered_map)

    Step 1: Count the frequency of every character.
    Step 2: Traverse the string from left to right.
    Step 3: Return the index of the first character
            whose frequency is exactly 1.
    Step 4: If no unique character is found, return -1.

    Time Complexity:  O(n)
    Space Complexity: O(1) for lowercase English letters
*/

class Solution {
public:
    int firstUniqChar(string s) {

        // Stores each character and its frequency (occurrence count).
        unordered_map<char, int> freq;

        // Step 1: Count the occurrences of each character.
        for (char letter : s) {
            freq[letter]++;
        }

        // Step 2: Traverse the string in its original order.
        for (int i = 0; i < s.length(); i++) {

            // Check if the current character appears only once.
            if (freq[s[i]] == 1) {

                // Return the index of the first unique character.
                return i;
            }
        }

        // Step 3: No unique character was found.
        return -1;
    }
};

// Main function for testing the solution locally.
int main() {

    Solution solution;

    // Test Case 1
    string s1 = "leetcode";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << solution.firstUniqChar(s1) << endl;
    cout << endl;

    // Test Case 2
    string s2 = "loveleetcode";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << solution.firstUniqChar(s2) << endl;
    cout << endl;

    // Test Case 3
    string s3 = "aabb";
    cout << "Input: " << s3 << endl;
    cout << "Output: " << solution.firstUniqChar(s3) << endl;

    return 0;
}
