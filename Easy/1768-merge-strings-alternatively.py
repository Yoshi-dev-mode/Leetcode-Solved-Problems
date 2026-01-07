# TIME AND SPACE COMPLEXITY = O(M+N)

class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        Merges two strings by alternating their characters.
        If one string is longer, the remaining characters
        are appended at the end.
        """
        
        s = []          # List to store merged characters
        i = 0           # Index for both strings

        # Continue while there are still characters in either string
        while i < len(word1) or i < len(word2):
            
            # Add character from word1 if index is valid
            if i < len(word1):
                s.append(word1[i])
            
            # Add character from word2 if index is valid
            if i < len(word2):
                s.append(word2[i])
            
            i += 1       # Move to the next index

        # Join list into a single string and return
        return ''.join(s)
