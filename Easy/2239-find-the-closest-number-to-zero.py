# TIME COMPLEXITY = O(n)
# SPACE COMPLEXITY = O(1)

class Solution(object):
    def findClosestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Initialize 'closest' with the first element of the list.
        # This will store the number that is currently closest to zero.
        closest = nums[0]

        # Loop through each number in the list
        for i in nums:
            # Compare absolute values to check which number is closer to zero
            # If the current number is closer than the stored 'closest',
            # update 'closest'
            if abs(i) < abs(closest):
                closest = i

        # After the loop, 'closest' holds the number with the smallest absolute value
        # However, if 'closest' is negative and its positive counterpart exists in nums,
        # return the positive value (tie-breaking rule)
        if closest < 0 and abs(closest) in nums:
            return abs(closest)

        # Otherwise, return the closest number found
        return closest
