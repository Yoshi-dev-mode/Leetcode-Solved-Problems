
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
    LeetCode 205: Isomorphic Strings

    Problem:
    Given two strings s and t, determine whether they are isomorphic.

    Two strings are isomorphic if characters in s can be replaced
    to obtain t while preserving the order of characters.

    Rules:
    1. Each character must map to exactly one character.
    2. Two different characters cannot map to the same character.
    3. Repeated characters must maintain consistent mappings.

    Approach:
    Use two unordered_maps to store character mappings:
    - charST: Maps characters from s to t.
    - charTS: Maps characters from t to s.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Stores mappings from string s to string t.
        unordered_map<char, char> charST;

        // Stores mappings from string t to string s.
        // This prevents two different characters from
        // mapping to the same character.
        unordered_map<char, char> charTS;

        // Traverse both strings simultaneously.
        for (int i = 0; i < s.length(); i++) {

            // Get the current characters from both strings.
            char charS = s[i];
            char charT = t[i];

            // Check if charS already has a mapping.
            // If its existing mapping is different from charT,
            // the strings are not isomorphic.
            if (charST.count(charS) && charST[charS] != charT) {
                return false;
            }

            // Check if charT is already mapped from another character.
            // If its existing mapping is different from charS,
            // the strings are not isomorphic.
            if (charTS.count(charT) && charTS[charT] != charS) {
                return false;
            }

            // Store the character mappings in both directions.
            charST[charS] = charT;
            charTS[charT] = charS;
        }

        // If no mapping conflicts were found, the strings are isomorphic.
        return true;
    }
};

// Driver code to test the solution.
int main() {
    Solution solution;

    // Example 1
    string s1 = "egg";
    string t1 = "add";

    cout << boolalpha;
    cout << "Example 1: " << solution.isIsomorphic(s1, t1) << endl;

    // Example 2
    string s2 = "foo";
    string t2 = "bar";

    cout << "Example 2: " << solution.isIsomorphic(s2, t2) << endl;

    // Example 3
    string s3 = "paper";
    string t3 = "title";

    cout << "Example 3: " << solution.isIsomorphic(s3, t3) << endl;

    // Example 4
    string s4 = "ab";
    string t4 = "aa";

    cout << "Example 4: " << solution.isIsomorphic(s4, t4) << endl;

    return 0;
}
