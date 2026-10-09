
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * Determines the number of car fleets that reach the target.
     *
     * @param target   The destination position.
     * @param position The starting position of each car.
     * @param speed    The speed of each car.
     * @return         The total number of distinct car fleets.
     */
    int carFleet(int target, vector<int>& position,
                 vector<int>& speed) {

        // Store each car as {position, speed}.
        // This keeps the position and speed of each car together.
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort cars by position in descending order.
        // Cars closest to the target are processed first.
        sort(cars.rbegin(), cars.rend());

        // Stores the arrival times of distinct fleets.
        stack<double> st;

        for (auto car : cars) {
            int pos = car.first;
            int spd = car.second;

            // Calculate the time this car would take to reach
            // the target if it traveled without catching a fleet.
            // Casting to double allows fractional arrival times.
            double time = (double)(target - pos) / spd;

            // If there is no fleet ahead, or this car arrives
            // later than the fleet ahead, it forms a new fleet.
            if (st.empty() || time > st.top()) {
                st.push(time);
            }

            // Otherwise, this car catches up to the fleet ahead
            // and joins it. No additional fleet is created.
        }

        // Each stack entry represents one distinct fleet.
        return st.size();
    }
};

int main() {
    Solution solution;

    // Example input
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    // Calculate the number of car fleets.
    int result = solution.carFleet(target, position, speed);

    // Expected output: 3
    cout << result << endl;

    return 0;
}