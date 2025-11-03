# Problem: Running Sum of 1d Array
# Description: Return the running sum of an array of integers.
# My Solution: O(n) in-place update.

class Solution:
    def runningSum(self, nums):
        container = 0
        for i in range(len(nums)):
            container += nums[i]
            nums[i] = container
        return nums
