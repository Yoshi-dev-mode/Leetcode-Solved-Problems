
class Solution(object):
    def searchInsert(self, nums, target):
        """
        Finds the index of the target in a sorted array.
        If the target does not exist, returns the index
        where it should be inserted to maintain sorted order.

        Args:
            nums (List[int]): A sorted list of distinct integers.
            target (int): The value to search for.

        Returns:
            int: The index of the target or its insertion position.

        Time Complexity: O(log n)
        Space Complexity: O(1)
        """

        # Initialize the left and right pointers
        left = 0
        right = len(nums) - 1

        # Continue searching while the search range is valid
        while left <= right:

            # Find the middle index
            mid = (left + right) // 2

            # If the middle element matches the target, return its index
            if nums[mid] == target:
                return mid

            # If the middle element is smaller than the target,
            # search the right half
            elif nums[mid] < target:
                left = mid + 1

            # If the middle element is greater than the target,
            # search the left half
            else:
                right = mid - 1

        # If target is not found, left represents its insertion position
        return left


# Main function for local testing
def main():
    solution = Solution()

    # Test cases
    nums = [1, 3, 5, 6]

    print("LeetCode 35 - Search Insert Position")
    print("------------------------------------")

    print("Input:", nums)

    target = 5
    print("Target:", target)
    print("Output:", solution.searchInsert(nums, target))

    print()

    target = 2
    print("Target:", target)
    print("Output:", solution.searchInsert(nums, target))

    print()

    target = 7
    print("Target:", target)
    print("Output:", solution.searchInsert(nums, target))


# Execute the main function
if __name__ == "__main__":
    main()
