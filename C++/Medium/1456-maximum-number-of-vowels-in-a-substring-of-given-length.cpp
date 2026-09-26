/*
    LeetCode 1456 - Maximum Number of Vowels in a Substring of Given Length

    Problem:
    Given a string s and an integer k, find the maximum number of vowels
    ('a', 'e', 'i', 'o', 'u') in any substring of length k.


    Example:

    Input:
    s = "abciiidef"
    k = 3

    Substrings of length 3:

        "abc" -> 1 vowel
        "bci" -> 1 vowel
        "cii" -> 2 vowels
        "iii" -> 3 vowels
        "iid" -> 2 vowels
        "ide" -> 1 vowel
        "def" -> 1 vowel

    Output:
    3


    Approach:
    Use a Sliding Window.

    Instead of counting the vowels from scratch for every substring,
    maintain the number of vowels inside the current window.

    First:
        1. Count the vowels in the first window of size k.

    Then slide the window:
        2. Add the new character entering the window.
        3. Remove the character leaving the window.
        4. Update the maximum vowel count.

    Example:

        s = "abciiidef"
        k = 3

        First window:
        [a b c] i i i d e f
         ↑-----↑

        count = 1

        Slide:

        a [b c i] i i d e f

        We:
            - Remove 'a'
            - Add 'i'

        Since 'a' is a vowel:
            count--

        Since 'i' is a vowel:
            count++

        This allows us to update the window in O(1) time.


    Why Sliding Window?

    A brute-force solution would count all k characters for every substring.

    That can repeatedly check the same characters.

    Sliding Window avoids this by only checking:
        - The character entering the window
        - The character leaving the window


    Algorithm:

        1. Create a helper function isVowel() to check whether a character
           is a vowel.

        2. Count the vowels in the first k characters.

        3. Set maxVowel to the number of vowels in the first window.

        4. Starting from index k:
               - Check the new character.
               - If it is a vowel, increment count.
               - Check the character at i - k.
               - If it is a vowel, decrement count.
               - Update maxVowel.

        5. Return maxVowel.


    Time Complexity:
        O(n)

        Each character is processed a constant number of times.


    Space Complexity:
        O(1)

        Only a few integer and character variables are used.
*/


#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:

    // Check if the given character is a vowel
    bool isVowel(char c)
    {
        return 'a' == c || 'e' == c || 'i' == c ||
               'o' == c || 'u' == c;
    }

    int maxVowels(string s, int k)
    {
        int count = 0;     // Number of vowels in the current window
        int maxVowel = 0;  // Maximum number of vowels found

        // Build the first window of size k
        for (int i = 0; i < k; i++)
        {
            // If the current character is a vowel, increase the count
            if (isVowel(s[i]))
                count++;

            maxVowel = max(maxVowel, count);
        }

        // Slide the window through the rest of the string
        for (int i = k; i < s.size(); i++)
        {
            // Add the new character entering the window
            if (isVowel(s[i]))
                count++;

            // Remove the character leaving the window
            if (isVowel(s[i - k]))
                count--;

            // Update the maximum vowel count
            maxVowel = max(maxVowel, count);
        }

        return maxVowel;
    }
};


int main()
{
    Solution solution;

    string letters = "abicdefeeeeee";
    int k = 3;

    cout << solution.maxVowels(letters, k);

    return 0;
}

