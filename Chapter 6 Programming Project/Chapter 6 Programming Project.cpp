
//Write a program that determines which geographic regions within a major city(north, south, east, west, and central) had the fewest reported automobile accidents last year.
//Input Validation : Do not accept an accident number that is less than 0.

#include <iostream>
#include <string>
#include <limits>

using namespace std;

/*
    Function: getRegInfo
    Purpose : Gets the region name and number of accidents from user input.
    Parameters:
        - regionName: the name of the region
        - numAccidents: the number of reported accidents (must be >= 0)
    Preconditions:
        - numAccidents must be 0 or greater
    Postconditions:
        - regionName and validated numAccidents are set usig user input
*/
void getRegInfo(string& regionName, int& numAccidents) {
    cout << "Enter region name: ";
    cin >> regionName;

    do {
        cout << "Enter number of accidents in " << regionName << " (>= 0): ";
        cin >> numAccidents;

        if (cin.fail() || numAccidents < 0) {
            cout << "Invalid input. Number of accidents must be 0 or greater.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (numAccidents < 0);
}

/*
    Function: isLower
    Purpose : Checks if the first value is less than the second
    Parameters:
        - int value1: first number to compare
        - int value2: second number to compare
    Returns:
        - true if value1 < value2, otherwise false
*/
bool isLower(int value1, int value2) {
    return value1 < value2;
}

/*
    Function: showLowest
    Purpose : Displays the region with the fewest reported accidents
    Parameters:
        - string regionName: the name of the region
        - int numAccidents: number of reported accidents in that region
*/
void showLowest(string regionName, int numAccidents) {
    cout << "\nThe safest region is " << regionName
        << " with " << numAccidents << " reported accidents." << endl;
}

/*
    Function: main
    Purpose : Controls program flow to determine the safest region
*/
int main() {
    const int NUM_REGIONS = 5;
    string regions[NUM_REGIONS] = { "North", "South", "East", "West", "Central" };

    string safestRegion;
    int lowestAccidents = numeric_limits<int>::max();

    for (int i = 0; i < NUM_REGIONS; i++) {
        string currentRegion;
        int currentAccidents;

        currentRegion = regions[i];
        getRegInfo(currentRegion, currentAccidents);

        if (isLower(currentAccidents, lowestAccidents)) {
            lowestAccidents = currentAccidents;
            safestRegion = currentRegion;
        }
    }

    showLowest(safestRegion, lowestAccidents);

    return 0;
}
