#include <iostream>
#include <vector>
using namespace std;

/**
 * LeetCode 2469: Convert the Temperature
 *
 * Converts a given temperature in Celsius to Kelvin and Fahrenheit.
 *
 * Formulas:
 * - Kelvin = Celsius + 273.15
 * - Fahrenheit = Celsius * 1.80 + 32.00
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
class Solution
{
public:
    /**
     * Converts Celsius to Kelvin and Fahrenheit.
     *
     * @param celsius The temperature in Celsius.
     * @return A vector containing:
     *         - index 0: Temperature in Kelvin
     *         - index 1: Temperature in Fahrenheit
     */
    vector<double> convertTemperature(double celsius)
    {
        // Convert Celsius to Kelvin by adding 273.15.
        double kelvin = celsius + 273.15;

        // Convert Celsius to Fahrenheit using the formula.
        double fahrenheit = celsius * 1.80 + 32.00;

        // Return both temperatures in the required order.
        return {kelvin, fahrenheit};
    }
};

int main()
{
    // Create an instance of the Solution class.
    Solution solution;

    // Set the input temperature in Celsius.
    double celsius = 123;

    // Call the function and store the converted temperatures.
    vector<double> res = solution.convertTemperature(celsius);

    // Display the results: Kelvin followed by Fahrenheit.
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}