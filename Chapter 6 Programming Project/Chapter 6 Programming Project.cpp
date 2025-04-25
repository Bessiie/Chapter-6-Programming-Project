
//Write a program that determines which geographic regions within a major city(north, south, east, west, and central) had the fewest reported automobile accidents last year.
//Input Validation : Do not accept an accident number that is less than 0.

#include <iostream>
#include <string>
#include <vector>

/*
   Function: getRegInfo
   Purpose : Prompts the user to enter the number of automobile accidents reported for a specific region and validates the input.
   Parameters:
	  - regionName (std::string): The name of the region for which accident data is being requested.
	  - numAccidents (int&): Reference to an integer where the validated accident count will be stored.
   Returns :
	  - None (void). The accident count is returned using pass by reference parameter.
   Preconditions:
	  - regionName must be a valid region string ("North", "South", etc.).
   Postconditions:
	  - numAccidents will contain a non-negative integer value entered by the user.
*/
void getRegInfo(std::string regionName, int& numAccidents) {
	do {
		std::cout << "Enter number of accidents in " << regionName << " (>= 0): ";
		std::cin >> numAccidents;

		if (numAccidents < 0) {
			std::cout << "Invalid input. Number of accidents must be 0 or greater. \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (numAccidents < 0);
}

/*
   Function: isLower
   Purpose : Compares two integers and returns true if the first is less than the second.
   Parameters:
	  - value1 (int): The first value to compare.
	  - value2 (int): The second value to compare.
   Returns :
	  - bool: true if value1 < value2; false otherwise.
   Preconditions:
	  - None.
   Postconditions:
	  - Returns a boolean indicating whether value1 is less than value2.
*/
bool isLower(int value1, int value2) {
	return value1 < value2;
}

/*
   Function: showLowest
   Purpose : Displays the name of the region with the lowest number of reported automobile accidents.
   Parameters:
      - regionName (const std::string&): Name of the region with the fewest accidents.
      - numAccidents (int): Number of accidents in that region.
   Returns :
      - None (void).
   Preconditions:
      - numAccidents should be a non-negative integer.
   Postconditions:
      - Outputs a formatted message to the console showing the safest region and its accident count.
*/
void showLowest(const std::string& regionName, int numAccidents) {
	std::cout << "\nThe safest region is " << regionName
		<< " with " << numAccidents << " reported accidents." << std::endl;
}

/*
   Function: main
   Purpose : Collects accident data for five regions and determines which had the fewest accidents.
*/
int main() {
	std::vector<std::string> regionNames = { "North", "South", "East", "West", "Central" };
	std::vector<int> numAccidents(regionNames.size());

	std::string safestRegion;
	int lowestAccidents;

	for (int i = 0; i < regionNames.size(); ++i) {
		getRegInfo(regionNames[i], numAccidents[i]);

		// Initialize with the first region
		if (i == 0 || isLower(numAccidents[i], lowestAccidents)) {
			lowestAccidents = numAccidents[i];
			safestRegion = regionNames[i];
		}
	}

	showLowest(safestRegion, lowestAccidents);

	return 0;
}