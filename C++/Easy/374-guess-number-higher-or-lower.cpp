
/**
 * LeetCode 374: Guess Number Higher or Lower
 * Algorithm: Binary Search
 *
 * The guess() API returns:
 * -1 = Your guess is too high
 *  1 = Your guess is too low
 *  0 = Your guess is correct
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        // Continue searching until the number is found
        while (left <= right) {

            // Find the middle number
            int mid = left + (right - left) / 2;

            // Check the result using the guess API
            int result = guess(mid);

            if (result == 0) {
                return mid;  // Correct number
            }
            else if (result == -1) {
                right = mid - 1;  // Guess is too high
            }
            else {
                left = mid + 1;   // Guess is too low
            }
        }

        return -1;
    }
};