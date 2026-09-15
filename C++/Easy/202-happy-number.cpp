#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * LeetCode #202 - Happy Number
 *
 * A happy number is a number that eventually reaches 1
 * when repeatedly replaced by the sum of the squares
 * of its digits.
 *
 * Example:
 * 19 -> 1² + 9² = 82
 * 82 -> 8² + 2² = 68
 * 68 -> 6² + 8² = 100
 * 100 -> 1² + 0² + 0² = 1
 *
 * If the process enters a cycle and never reaches 1,
 * the number is not a happy number.
 *
 * Approach:
 * - Extract each digit using % 10.
 * - Remove each digit using / 10.
 * - Calculate the sum of squared digits.
 * - Use an unordered_set to detect cycles.
 */
class Solution
{
public:

    /**
     * Determines whether a number is a happy number.
     *
     * @param n The number to check.
     * @return true if n is a happy number, otherwise false.
     */
    bool isHappy(int n)
    {
        // Stores numbers that have already appeared.
        // This is used to detect a repeating cycle.
        unordered_set<int> s;

        // Continue calculating until n becomes 1.
        while (n != 1)
        {
            // Stores the sum of the squares of the digits.
            int sum = 0;

            // Process every digit in n.
            while (n > 0)
            {
                // Get the last digit of n.
                // Example: 112 % 10 = 2
                int digit = n % 10;

                // Square the digit and add it to sum.
                // Example: 2 * 2 = 4
                sum = sum + (digit * digit);

                // Remove the last digit from n.
                // Example: 112 / 10 = 11
                n = n / 10;
            }

            // If this sum has already been seen,
            // the sequence is repeating and we have a cycle.
            if (s.find(sum) != s.end())
            {
                return false;
            }

            // Store the current sum for future cycle detection.
            s.insert(sum);

            // Use the calculated sum as the new number.
            n = sum;
        }

        // If n reaches 1, it is a happy number.
        return true;
    }
};

int main()
{
    Solution solution;

    // Test the solution with 112.
    cout << boolalpha << solution.isHappy(112);

    return 0;
}

