
"""

INTUITION:

    The brute-force idea is to check every pair of numbers and see if their sum equals the target, but this would be slow.
    Instead, while scanning the array, we can remember the numbers we have already seen.

    For each number, we ask:

    “What number do I need to add to this to reach the target?”

    If that needed number has already appeared before, then we have found the answer.

"""

"""

APPROACH

    We use a hash map (dictionary) to store each number along with its index as we iterate through the list.

    1. Initialize an empty dictionary to store previously seen numbers.

    2. Loop through the array using enumerate to get both index and value.

    3. For each value, compute the required number (target - value).

    4. Check if this required number exists in the dictionary.

    5. If it exists, return the index stored in the dictionary and the current index.

    6. If it does not exist, store the current value and its index in the dictionary.

    7. Since the problem guarantees exactly one solution, we can return immediately once found.
    
"""

# TIME COMPLEXITY AND SPACE COMPLEXITY: O(n)

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]      # List of integers
        :type target: int          # Target sum
        :rtype: List[int]          # Indices of the two numbers
        """

        map = {}  # Dictionary to store numbers we have seen so far
                  # Format: {number : index}

        # Loop through the list with both index and value
        for index, value in enumerate(nums):

            # Compute the number needed to reach the target
            desire = target - value

            # Check if the needed number already exists in the dictionary
            if desire in map:
                # If found, return the index of the desired number
                # and the current index
                return [map[desire], index]

            # Store the current number and its index for future checks
            map[value] = index
