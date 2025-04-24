//The formula for converting a temperature from Fahrenheit to Celsius is C = 5/9(F - 32).
//where F is the Fahrenheit temperature and C is the Celsius temperature.Write a modular program that creates a table showing the temperature in Celsius for Fahrenheit temperatures between 0 and 20.

#include <iostream>
#include <iomanip>

using namespace std;

/*
    Function: getCelsius
    Purpose : Converts a Fahrenheit temperature to Celsius.
    Parameters:
        - fahrenheit: The temperature in Fahrenheit.
    Returns:
        - The equivalent temperature in Celsius.
    Preconditions:
        - Fahrenheit is an integer (can be negative or positive).
    Postconditions:
        - Returns Celsius value calculated as 5.0 / 9.0 * (fahrenheit - 32)
*/
double getCelsius(int fahrenheit) {
    return 5.0 / 9.0 * (fahrenheit - 32);
}

/*
    Function: main
    Purpose : Displays a table of Fahrenheit to Celsius conversions for temperatures from 0 to 20.
*/
int main() {
    // Print table header
    cout << "Fahrenheit to Celsius Conversion Table\n";
    cout << left << setw(12) << "Fahrenheit" << "Celsius\n";

    // Loop through Fahrenheit values 0 to 20
    for (int f = 0; f <= 20; f++) {
        double celsius = getCelsius(f);
        cout << left << setw(12) << f << fixed << setprecision(2) << celsius << endl;
    }

    return 0;
}
