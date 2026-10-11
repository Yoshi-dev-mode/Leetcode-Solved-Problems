
/*
 * LeetCode 1700: Number of Students Unable to Eat Lunch
 *
 * Approach: Queue Simulation
 *
 * Description:
 * Students stand in a queue and each student prefers either
 * a circular sandwich (0) or a square sandwich (1).
 *
 * The sandwich at the current index is served first.
 * If the student at the front of the queue prefers that sandwich,
 * the student takes it and leaves the queue.
 * Otherwise, the student moves to the back of the queue.
 *
 * The process stops when every remaining student has refused
 * the current sandwich.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

        // Step 1: Add all students to the queue.
        // The first student added will be at the front.
        for (int student : students) {
            q.push(student);
        }

        // Counts consecutive students who refuse the current sandwich.
        int unableToEat = 0;

        // Tracks the current sandwich in the sandwiches vector.
        int i = 0;

        // Continue while students remain and not everyone has refused.
        while (!q.empty() && unableToEat < q.size()) {

            // Check whether the front student prefers the current sandwich.
            if (q.front() == sandwiches[i]) {

                // The student eats the sandwich and leaves the queue.
                q.pop();

                // Move to the next sandwich.
                i++;

                // Reset because the queue and current sandwich have changed.
                unableToEat = 0;

            } else {

                // The student does not prefer the current sandwich.
                // Save their preference before removing them.
                int student = q.front();
                q.pop();

                // Move the student to the back of the queue.
                q.push(student);

                // Count this student's refusal.
                unableToEat++;
            }
        }

        // Students remaining in the queue cannot eat lunch.
        return q.size();
    }
};

int main() {
    Solution solution;

    // 0 = circular sandwich, 1 = square sandwich.
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};

    // Calculate the number of students unable to eat.
    int result = solution.countStudents(students, sandwiches);

    cout << "Students unable to eat lunch: " << result << endl;

    return 0;
}
