class Solution(object):
    def maximumWealth(self, accounts):
        # LeetCode Problem: 1672. Richest Customer Wealth
        # --------------------------------------------------
        # Given a 2D list 'accounts' where each sublist represents the money in each bank account 
        # of a customer, this function computes the maximum total wealth among all customers.
        #
        # Approach:
        # - Iterate through each customer (row in 'accounts')
        # - Replace each row with the sum of that customer's accounts
        # - Sort the list and return the largest total wealth
        #
        # Time Complexity: O(n log n) due to sorting
        # Space Complexity: O(1) (in-place modification)
        #
        # Example:
        # Input: accounts = [[1,2,3],[3,2,1]]
        # Output: 6
        # Explanation: Both customers have wealth = 6, so the maximum is 6.

        for i in range(len(accounts)):
            accounts[i] = sum(accounts[i])  # fixed inner sum

        accounts.sort()
        return accounts[-1]

