
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    LeetCode 438: Find All Anagrams in a String

    Approach:
    - Sliding Window
    - Frequency Array

    Goal:
    Find all starting indices of p's anagrams in s.

    An anagram is a word or string formed by rearranging
    the characters of another string.

    Example:
    Input:
        s = "abab"
        p = "ab"

    Output:
        [0, 1, 2]

    Explanation:
        "ab" at index 0 is an anagram of "ab".
        "ba" at index 1 is an anagram of "ab".
        "ab" at index 2 is an anagram of "ab".

    Time Complexity: O(n)
        n = length of s.
        Each character is added to and removed from
        the sliding window at most once.
        Comparing frequency arrays takes O(26), which
        is constant.

    Space Complexity: O(1)
        The two frequency arrays each have a fixed
        size of 26, excluding the result vector.
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        // If p is longer than s, no anagram can exist.
        if (n2 > n1) {
            return {};
        }

        // Stores the frequency of each character in p.
        vector<int> anagram(26, 0);

        // Stores the frequency of characters in the
        // current sliding window of s.
        vector<int> window(26, 0);

        // Stores the starting indices of all anagrams.
        vector<int> result;

        // Initialize the frequency arrays using the
        // first window of s, whose size is equal to p.
        for (int i = 0; i < n2; i++) {
            anagram[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }

        // Check if the first window is an anagram of p.
        if (anagram == window) {
            result.push_back(0);
        }

        // Slide the window one character at a time.
        for (int right = n2; right < n1; right++) {

            // Add the new character entering the window.
            window[s[right] - 'a']++;

            // Remove the character leaving the window.
            window[s[right - n2] - 'a']--;

            // If the frequency arrays match, the current
            // window is an anagram of p.
            if (anagram == window) {
                // Calculate the starting index of the window.
                result.push_back(right - n2 + 1);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    string s = "abab";
    string p = "ab";

    vector<int> result = solution.findAnagrams(s, p);

    // Print the result in array-like format: [0, 1, 2]
    cout << "[";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        // Print a comma and space between elements,
        // but not after the last element.
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}