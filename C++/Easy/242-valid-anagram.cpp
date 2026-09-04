#include <iostream>

using namespace std;

class Solution
{
public:

    /*
     * Determines whether two strings are anagrams.
     *
     * An anagram is a word or string formed by rearranging
     * the characters of another string while using the same
     * characters with the same frequency.
     *
     * Example:
     * s = "anagram"
     * t = "nagaram"
     * Output: true
     *
     * Approach:
     * 1. If the strings have different lengths, they cannot
     *    be anagrams.
     * 2. Use an array of size 26 to store the frequency of
     *    each lowercase English letter.
     * 3. Increment the count for characters in `s`.
     * 4. Decrement the count for characters in `t`.
     * 5. If all counts return to zero, the strings are anagrams.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     * Since the array always contains only 26 elements.
     */
    bool isAnagram(string s, string t)
    {
        // Step 1: Strings with different lengths cannot be anagrams.
        if (s.length() != t.length())
        {
            return false;
        }

        // Step 2: Create a frequency array for 26 lowercase letters.
        // Index 0 represents 'a', index 1 represents 'b', ..., 25 represents 'z'.
        int count[26] = {0};

        // Step 3 & 4:
        // Increment the count for characters in `s`
        // and decrement the count for characters in `t`.
        for (int i = 0; i < s.length(); i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        // Step 5: Every character's count should be zero.
        // A non-zero count means the strings have different
        // character frequencies.
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                return false;
            }
        }

        // All character frequencies match.
        return true;
    }
};