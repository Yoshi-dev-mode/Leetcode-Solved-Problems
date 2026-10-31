
class Solution:
    def uniqueOccurrences(self, arr):
        """
        Determines whether each distinct number in the array
        has a unique frequency.

        Args:
            arr: List of integers.

        Returns:
            True if all frequencies are unique, otherwise False.
        """

        # Step 1: Count the frequency of each number.
        frequency = {}

        for num in arr:
            frequency[num] = frequency.get(num, 0) + 1

        # Step 2: Store frequencies we've already encountered.
        seen = set()

        # Step 3: Check whether each frequency is unique.
        for freq in frequency.values():

            # If this frequency already exists, return False.
            if freq in seen:
                return False

            # Record this frequency.
            seen.add(freq)

        # All frequencies are unique.
        return True


# Main function for local testing.
def main():

    solution = Solution()

    arr = [1, 2, 2, 1, 1, 3]

    result = solution.uniqueOccurrences(arr)

    print("Unique Occurrences:", result)


if __name__ == "__main__":
    main()


# Expected Output:
# Unique Occurrences: True
