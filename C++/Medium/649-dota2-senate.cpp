
#include <iostream>
#include <queue>
#include <string>

using namespace std;

/**
 * LeetCode 649: Dota2 Senate
 *
 * Approach: Two Queues
 *
 * Store the indices of Radiant and Dire senators in separate queues.
 * The senator with the smaller index gets to act first.
 *
 * The senator who acts first bans the opposing senator.
 * The surviving senator is added back to their queue with their
 * index increased by n, representing their turn in the next round.
 *
 * The game continues until one party has no senators remaining.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution {
public:
    /**
     * Determines which party wins the Dota2 Senate game.
     *
     * @param senate A string containing 'R' (Radiant) and 'D' (Dire).
     * @return "Radiant" if Radiant wins, otherwise "Dire".
     */
    string predictPartyVictory(string senate) {
        // Store the indices of Radiant and Dire senators.
        queue<int> radiant;
        queue<int> dire;

        // Length of the original senate string.
        int n = senate.size();

        // Place each senator's index into the appropriate queue.
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        // Continue while both parties still have active senators.
        while (!radiant.empty() && !dire.empty()) {

            // Get the indices of the next Radiant and Dire senators.
            int r = radiant.front();
            int d = dire.front();

            // Remove both senators from the front temporarily.
            radiant.pop();
            dire.pop();

            // The senator with the smaller index acts first.
            if (r < d) {
                // Radiant bans Dire and survives to the next round.
                radiant.push(r + n);
            } else {
                // Dire bans Radiant and survives to the next round.
                dire.push(d + n);
            }
        }

        // The party with remaining senators wins.
        if (dire.empty()) {
            return "Radiant";
        } else {
            return "Dire";
        }
    }
};

int main() {
    Solution solution;

    // Example input.
    string senate = "RDD";

    // Determine the winning party.
    string result = solution.predictPartyVictory(senate);

    // Display the result.
    cout << "Senate: " << senate << endl;
    cout << "Winner: " << result << endl;

    return 0;
}
