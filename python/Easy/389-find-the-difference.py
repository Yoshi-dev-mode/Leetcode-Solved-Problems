
class Solution(object):
    def findTheDifference(self, s, t):
        """
        Finds the extra character added to string t.

        Args:
            s (str): The original string.
            t (str): The modified string with one extra character.

        Returns:
            str: The additional character found in t.
        """

        # Calculate the sum of Unicode values of characters in s
        sum_s = sum(ord(char) for char in s)

        # Calculate the sum of Unicode values of characters in t
        sum_t = sum(ord(char) for char in t)

        # Get the difference between the two sums
        difference = sum_t - sum_s

        # Convert the Unicode value back into a character
        return chr(difference)


# Main function to test the solution
def main():

    # Create an instance of the Solution class
    solution = Solution()

    # Example input
    s = "abcd"
    t = "abcde"

    # Call the function and store the result
    result = solution.findTheDifference(s, t)

    # Display the inputs and output
    print("Original String:", s)
    print("Modified String:", t)
    print("Extra Character:", result)


# Execute the main function
if __name__ == "__main__":
    main()
