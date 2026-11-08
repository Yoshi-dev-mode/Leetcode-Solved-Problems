
"""
LeetCode 136 - Single Number
Difficulty: Easy
Topic: Arrays, Bit Manipulation
Approach: XOR (Exclusive OR)

Problem:
Given a non-empty array of integers, every element
appears twice except for one. Find that single number.

Time Complexity: O(n)
Space Complexity: O(1)
"""


class Solution(object):
    def singleNumber(self, nums):
        """
        Finds the number that appears only once.

        Args:
            nums (List[int]): Array of integers containing
                              pairs and one unique number.

        Returns:
            int: The number that appears only once.
        """

        # Initialize the result variable to zero.
        result = 0

        # Iterate through each number in the array.
        for num in nums:

            # XOR cancels duplicate numbers:
            # a ^ a = 0 and a ^ 0 = a.
            result ^= num

        # Return the remaining unique number.
        return result


def main():
    """Runs sample test cases and displays their results."""

    # Create an instance of the Solution class.
    solution = Solution()

    # Sample test cases.
    test_cases = [
        [2, 2, 1],
        [4, 1, 2, 1, 2],
        [1],
        [7, 3, 5, 3, 7]
    ]

    # Execute each test case.
    for nums in test_cases:
        result = solution.singleNumber(nums)

        # Display the input array and its unique number.
        print("Input:", nums)
        print("Output:", result)
        print("-" * 30)


# Entry point of the Python program.
if __name__ == "__main__":
    main()
