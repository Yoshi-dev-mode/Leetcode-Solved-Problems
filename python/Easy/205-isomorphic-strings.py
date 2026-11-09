
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        LeetCode 205: Isomorphic Strings
        Difficulty: Easy
        Topic: Hash Map, String

        Description:
            Determine whether two strings are isomorphic.

            Two strings are isomorphic if each character in
            the first string can be consistently mapped to
            exactly one character in the second string.

            Different characters cannot map to the same
            character, and the character order must remain
            unchanged.

        Args:
            s (str): The original string.
            t (str): The target string.

        Returns:
            bool: True if the strings are isomorphic,
                  False otherwise.

        Examples:
            Input:  s = "egg", t = "add"
            Output: True

            Input:  s = "foo", t = "bar"
            Output: False

            Input:  s = "paper", t = "title"
            Output: True

        Algorithm:
            1. Create two dictionaries for bidirectional
               character mapping.
            2. Iterate through both strings simultaneously.
            3. Check whether existing mappings conflict.
            4. Return False if an inconsistency is found.
            5. Otherwise, store the character mappings.
            6. Return True if all mappings are valid.

        Complexity:
            Time:  O(n) - Each character is visited once.
            Space: O(n) - Stores character mappings.
        """

        # Ensure both strings have the same length.
        if len(s) != len(t):
            return False

        # Initialize dictionaries for bidirectional mapping.
        map_s = {}  # Maps characters from s to t.
        map_t = {}  # Maps characters from t to s.

        # Iterate through corresponding character pairs.
        for a, b in zip(s, t):

            # Check if a maps to a different character.
            if a in map_s and map_s[a] != b:
                return False

            # Prevent two characters from mapping to
            # the same character in the target string.
            if b in map_t and map_t[b] != a:
                return False

            # Store valid character mappings.
            map_s[a] = b
            map_t[b] = a

        # All mappings are consistent.
        return True


# --------------------------------------------------
# Main Program - Test Cases
# --------------------------------------------------
if __name__ == "__main__":
    solution = Solution()

    test_cases = [
        ("egg", "add"),
        ("foo", "bar"),
        ("paper", "title"),
        ("badc", "baba"),
        ("a", "a")
    ]

    for s, t in test_cases:
        result = solution.isIsomorphic(s, t)

        print("Input: s = '{}', t = '{}'".format(s, t))
        print("Output:", result)
        print("-" * 40)
