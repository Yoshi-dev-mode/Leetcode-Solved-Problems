# TIME COMPLEXITY = O(n)
# SPACE COMPLIEXITY = O(k)

class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]   # Input array of integers
        :type k: int            # Maximum allowed index distance
        :rtype: bool            # True if nearby duplicate exists
        """

        m = {}  # Dictionary to store numbers currently inside the sliding window
                # Format: {number: index}

        # Loop through the array with index and value
        for i, v in enumerate(nums):

            # If window size exceeds k, remove the element
            # that is k+1 positions behind the current index
            if i > k:
                del m[nums[i - k - 1]]

            # If current value already exists in the window,
            # we found a duplicate within distance k
            if nums[i] in m:
                return True

            # Add the current value and its index to the window
            m[v] = i

        # If no nearby duplicate was found
        return False
