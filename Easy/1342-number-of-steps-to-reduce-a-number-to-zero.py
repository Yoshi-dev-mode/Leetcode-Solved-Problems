class Solution(object):
    def numberOfSteps(self, num):
        # LeetCode Problem: 1342. Number of Steps to Reduce a Number to Zero
        # ---------------------------------------------------------------------
        # Given an integer 'num', repeatedly perform the following steps until it becomes zero:
        #   - If 'num' is even, divide it by 2
        #   - If 'num' is odd, subtract 1
        # The function returns the total number of steps required to reach zero.
        #
        # Approach:
        # - Use a while loop to repeatedly modify 'num'
        # - Increment a counter 'c' for each operation performed
        #
        # Time Complexity: O(log n)
        # Space Complexity: O(1)
        #
        # Example:
        # Input: num = 14
        # Output: 6
        # Explanation: 14 → 7 → 6 → 3 → 2 → 1 → 0  (6 steps)
        
        c = 0
        while num > 0:
            if num % 2 == 0:
                num //= 2    # use integer division
            else:
                num -= 1
            c += 1
        return c

            
            