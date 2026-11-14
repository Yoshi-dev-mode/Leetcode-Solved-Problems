
class Solution(object):
    def fourSumCount(self, nums1, nums2, nums3, nums4):
        """
        Counts the number of tuples (i, j, k, l) such that:
        nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0.

        Args:
            nums1, nums2, nums3, nums4 (List[int]): Four integer arrays.

        Returns:
            int: Total number of valid combinations.
        """

        # Dictionary to store the frequency of pair sums
        pair_sums = {}

        # Calculate all possible sums from nums1 and nums2
        for a in nums1:
            for b in nums2:

                # Get the sum of the current pair
                total = a + b

                # Count how many times this sum appears
                pair_sums[total] = pair_sums.get(total, 0) + 1

        # Initialize the counter for valid combinations
        count = 0

        # Calculate all possible sums from nums3 and nums4
        for c in nums3:
            for d in nums4:

                # Find the sum needed to make the total equal to zero
                target = -(c + d)

                # Check if the required sum exists in the dictionary
                if target in pair_sums:

                    # Add its frequency to the total count
                    count += pair_sums[target]

        # Return the total number of valid combinations
        return count


# Main function to test the solution
def main():

    # Create an instance of the Solution class
    solution = Solution()

    # Example input
    nums1 = [1, 2]
    nums2 = [-2, -1]
    nums3 = [-1, 2]
    nums4 = [0, 2]

    # Call the function and store the result
    result = solution.fourSumCount(nums1, nums2, nums3, nums4)

    # Display the input and output
    print("nums1:", nums1)
    print("nums2:", nums2)
    print("nums3:", nums3)
    print("nums4:", nums4)
    print("Number of Valid Combinations:", result)


# Execute the main function
if __name__ == "__main__":
    main()
