
class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # Stores the first index where each count appears
        count_map = {0: -1}

        count = 0
        max_length = 0

        for i, num in enumerate(nums):

            # Treat 0 as -1 and 1 as +1
            if num == 0:
                count -= 1
            else:
                count += 1

            # If we've seen this count before,
            # the elements between have equal 0s and 1s
            if count in count_map:
                length = i - count_map[count]
                max_length = max(max_length, length)

            else:
                # Save only the first occurrence
                count_map[count] = i

        return max_length


# Main program for testing
if __name__ == "__main__":
    solution = Solution()

    nums = [0, 1, 0, 1, 1, 1, 0]

    print("Input:", nums)
    print("Maximum Length:", solution.findMaxLength(nums))
