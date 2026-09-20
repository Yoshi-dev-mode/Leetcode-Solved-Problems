#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        // Two pointers:
        // left starts from the beginning
        // right starts from the end
        int left = 0;
        int right = s.size() - 1;

        // Continue until the two pointers meet or cross
        while (left < right)
        {
            // Skip non-alphanumeric characters from the left
            // Example: spaces, commas, periods, etc.
            if (!isalnum(s[left]))
            {
                left++;

                // Skip the rest of this iteration
                // and start the loop again
                continue;
            }

            // Skip non-alphanumeric characters from the right
            if (!isalnum(s[right]))
            {
                right--;

                // Skip the rest of this iteration
                // and start the loop again
                continue;
            }

            // Compare both characters while ignoring capitalization
            // Example: 'A' and 'a' are considered equal
            if (tolower(s[left]) != tolower(s[right]))
            {
                // Characters don't match, so it is not a palindrome
                return false;
            }

            // Characters matched, so move both pointers inward
            left++;
            right--;
        }

        // All valid characters matched
        // Therefore, the string is a palindrome
        return true;
    }
};

int main()
{
    Solution solution;

    string palindrome = "A man, a plan, a canal: Panama";

    cout << solution.isPalindrome(palindrome);
}

