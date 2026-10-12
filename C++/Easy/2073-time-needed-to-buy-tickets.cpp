#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    /**
     * Calculates the time needed for the target person to finish
     * buying all their tickets.
     *
     * @param tickets Vector containing the number of tickets
     *                each person needs to buy.
     * @param k       Index of the target person.
     * @return        Total time in seconds until person k finishes.
     */
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;

        // Add each person's index to the queue.
        for (int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }

        int seconds = 0;

        // Simulate the ticket-buying process.
        while (!q.empty()) {
            // Get the person at the front of the queue.
            int person = q.front();
            q.pop();

            // The person buys one ticket, taking one second.
            tickets[person]--;
            seconds++;

            // Stop when the target person has bought all their tickets.
            if (person == k && tickets[person] == 0) {
                break;
            }

            // If the person still needs tickets, return them
            // to the back of the queue.
            if (tickets[person] > 0) {
                q.push(person);
            }
            // Otherwise, the person leaves the queue permanently.
        }

        // Return the total time elapsed.
        return seconds;
    }
};

int main() {
    Solution solution;

    // Example input: person 2 needs 2 tickets.
    vector<int> tickets = {2, 3, 2};
    int k = 2;

    // Calculate the time needed for the target person.
    int result = solution.timeRequiredToBuy(tickets, k);

    // Expected output: 6
    cout << result << endl;

    return 0;
}