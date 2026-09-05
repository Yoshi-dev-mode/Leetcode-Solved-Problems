#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * LeetCode 121: Best Time to Buy and Sell Stock
 *
 * Problem:
 * Given an array of stock prices where prices[i] represents the
 * price of a stock on the ith day, find the maximum profit that
 * can be achieved by buying on one day and selling on a later day.
 *
 * You can only make one transaction:
 *     - Buy once
 *     - Sell once
 *
 * Example:
 *     Input:  [7, 1, 5, 3, 6, 4]
 *     Output: 5
 *
 * Explanation:
 *     Buy at price 1
 *     Sell at price 6
 *     Profit = 6 - 1 = 5
 *
 * Approach:
 * We use a single-pass (one-pass) approach.
 *
 * While traversing the array, we keep track of:
 *
 *     1. minPrice  -> The lowest stock price seen so far.
 *     2. maxProfit -> The highest profit found so far.
 *
 * For every price:
 *
 *     profit = current price - minimum price seen so far
 *
 * Then we update maxProfit if the current profit is larger.
 *
 * Time Complexity: O(n)
 *     We traverse the array only once.
 *
 * Space Complexity: O(1)
 *     We only use a few variables regardless of the input size.
 */

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        // Store the lowest stock price seen so far.
        int minPrice = prices[0];

        // Store the maximum profit found so far.
        int maxProfit = 0;

        // Start from index 1 because prices[0] is already
        // used to initialize minPrice.
        for (int i = 1; i < prices.size(); i++)
        {
            // Calculate the profit if we sell the stock today.
            int profit = prices[i] - minPrice;

            // Keep the best profit found so far.
            maxProfit = max(maxProfit, profit);

            // Update minPrice if today's price is lower.
            minPrice = min(minPrice, prices[i]);
        }

        // Return the maximum possible profit.
        return maxProfit;
    }
};

