
# LeetCode 290: Word Pattern
# Difficulty: Easy
# Topics: Hash Table, String
# Time Complexity: O(n + m)
# Space Complexity: O(n + m)

class Solution(object):
    def wordPattern(self, pattern, s):
        """
        Checks if a string follows the given pattern.

        Each character must map to exactly one unique word,
        and each word must map to exactly one character.

        Args:
            pattern (str): The pattern to match.
            s (str): A string containing space-separated words.

        Returns:
            bool: True if the words follow the pattern,
                  otherwise False.
        """

        # Split the input string into individual words
        words = s.split()

        # The number of words must match the pattern length
        if len(pattern) != len(words):
            return False

        # Dictionaries for two-way mapping
        cTw = {}  # Character to word
        wTc = {}  # Word to character

        # Pair each pattern character with its word
        for char, word in zip(pattern, words):

            # Check if the character maps to a different word
            if char in cTw:
                if cTw[char] != word:
                    return False

            # Check if the word maps to a different character
            if word in wTc:
                if wTc[word] != char:
                    return False

            # Store the character-word mappings
            cTw[char] = word
            wTc[word] = char

        # Return True if all mappings are consistent
        return True
