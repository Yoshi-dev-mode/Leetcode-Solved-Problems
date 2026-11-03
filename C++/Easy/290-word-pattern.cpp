
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

/*
 * LeetCode 290: Word Pattern
 *
 * Problem:
 * Determine whether a string of words follows a given character pattern.
 *
 * Approach:
 * Use two unordered_maps to maintain a one-to-one mapping between
 * pattern characters and words.
 *
 * 1. charToWord: Maps each character to a word.
 * 2. wordToChar: Maps each word back to a character.
 *
 * Both mappings are necessary to ensure that no two characters
 * map to the same word and no character maps to different words.
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(n + m)
 *
 * n = length of the pattern
 * m = length of the string s
 */

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        // Stores the mapping of characters to words.
        unordered_map<char, string> charToWord;

        // Stores the mapping of words to characters.
        unordered_map<string, char> wordToChar;

        // Use stringstream to extract words separated by spaces.
        stringstream ss(s);
        string word;

        // Tracks the current position in the pattern.
        int i = 0;

        // Read each word from the string.
        while (ss >> word) {

            // If there are more words than pattern characters,
            // the pattern cannot match the string.
            if (i >= pattern.length()) {
                return false;
            }

            // Get the current character from the pattern.
            char ch = pattern[i];

            // Check if the character already maps to a
            // different word.
            if (charToWord.count(ch) && charToWord[ch] != word) {
                return false;
            }

            // Check if the word already maps to a
            // different character.
            if (wordToChar.count(word) && wordToChar[word] != ch) {
                return false;
            }

            // Store the character-to-word mapping.
            charToWord[ch] = word;

            // Store the word-to-character mapping.
            wordToChar[word] = ch;

            // Move to the next character in the pattern.
            i++;
        }

        // Ensure the number of words matches the pattern length.
        return i == pattern.length();
    }
};

/*
 * Main Function
 *
 * Creates a Solution object and tests the wordPattern function
 * using a sample input.
 */

int main() {

    Solution solution;

    // Example input.
    string pattern = "abba";
    string s = "dog cat cat dog";

    // Display the result as true or false.
    cout << boolalpha << solution.wordPattern(pattern, s) << endl;

    return 0;
}
