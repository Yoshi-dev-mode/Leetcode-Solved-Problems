
/*
 * Problem: 933. Number of Recent Calls
 * Platform: LeetCode
 * Language: C++
 *
 * Description:
 * Implement a RecentCounter class that counts the number of
 * requests received within the last 3000 milliseconds.
 *
 * For every call ping(t), count timestamps in the inclusive
 * interval [t - 3000, t].
 *
 * Approach:
 * Use a queue to store timestamps in increasing order.
 * 1. Add the current timestamp to the queue.
 * 2. Remove timestamps older than t - 3000.
 * 3. Return the number of timestamps remaining.
 *
 * Time Complexity: O(1) amortized per ping() call
 * Space Complexity: O(n), where n is the number of
 * timestamps currently stored in the queue.
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class RecentCounter {
private:
    // Stores timestamps from oldest to newest.
    // The queue persists between ping() calls.
    queue<int> q;

public:
    // Constructor: creates an empty queue.
    RecentCounter() {
    }

    // Records a new request at timestamp t.
    // Returns the number of requests in [t - 3000, t].
    int ping(int t) {
        // Step 1: Add the current request.
        q.push(t);

        // Step 2: Calculate the earliest valid timestamp.
        int lowerBound = t - 3000;

        // Step 3: Remove timestamps outside the valid interval.
        while (!q.empty() && q.front() < lowerBound) {
            q.pop();
        }

        // Step 4: Return the number of recent requests.
        return q.size();
    }
};

int main() {
    // Create one RecentCounter object.
    RecentCounter solution;

    // Example timestamps from the LeetCode problem.
    vector<int> timestamps = {1, 100, 3001, 3002};

    cout << "Number of Recent Calls\n";
    cout << "----------------------\n";

    // Send each timestamp to the same counter object.
    for (int t : timestamps) {
        int result = solution.ping(t);

        cout << "ping(" << t << ") = " << result << endl;
    }

    return 0;
}
