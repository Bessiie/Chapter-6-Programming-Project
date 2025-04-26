// A painting company has determined that for every 110 square feet of wall space, 
// 1 gallon of paint and 8 hours of labor will be required. 
// The company charges $25.00 per hour for labor. 
// Write a modular program that allows the user to enter the number of rooms that are to be painted and the price of the paint per gallon. 
// It should also ask for the square feet of wall space in each room. It should then display the following data:

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

const double gallonsPerSqFt = 1.0/110.0;
const double laborPerSqFt = 8.0/110.0;
const double laborChargePerHour = 25.00;

/*
   Function: getRooms
   Purpose : Prompts the user to input the number of rooms to paint, validating input (must be > 0).
   Parameters:
	  - None
   Returns :
	  - int: Number of rooms to be painted
   Preconditions:
	  - User must input a positive integer.
   Postconditions:
	  - Returns a positive integer representing the number of rooms.
*/
int getRooms() {
	int numRooms;
	do {
		std::cout << "Input the number of rooms needed to be painted (must be more than 1 room) :";
		std::cin >> numRooms;

		if (numRooms < 1) {
			std::cout << "Has to be more one room\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
		}
	} while (numRooms < 1);
	return numRooms;
}

/*
   Function: getSqFtPerRoom
   Purpose : Prompts the user to input the square footage for a room, validating input (cannot be negative).
   Parameters:
	  - None
   Returns :
	  - int: Square footage of the room
   Preconditions:
	  - User must input a non-negative number.
   Postconditions:
	  - Returns the non-negative square footage value.
*/
int getSqFtPerRoom() {
	double sqFtPerRoom;
	do {
		std::cout << "Input the square foot for the room needed to be painted (cannot be less than 0) :";
		std::cin >> sqFtPerRoom;

		if (sqFtPerRoom < 0) {
			std::cout << "Square foot per room cannot be less than 0\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
		}
	} while (sqFtPerRoom < 0);
	return sqFtPerRoom;
}

/*
   Function: getPaintPricePerGallon
   Purpose : Prompts the user to input the price per gallon of paint, validating input (must be >= $10).
   Parameters:
	  - None
   Returns :
	  - int: Paint price per gallon
   Preconditions:
	  - User must input a value greater than or equal to $10.
   Postconditions:
	  - Returns the valid paint price.
*/
int getPaintPricePerGallon() {
	double paintPricePerGallon;
	do {
		std::cout << "Input the paint price (cannot be less than $10) : $ ";
		std::cin >> paintPricePerGallon;

		if (paintPricePerGallon < 10) {
			std::cout << "Paint must be more than $10\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
		}
	} while (paintPricePerGallon < 10);
	return paintPricePerGallon;
}

/*
   Function: calcGallonsPerRoom
   Purpose : Calculates the number of gallons needed for a room based on square footage.
   Parameters:
	  - squareFeet (double): Area of the room in square feet
   Returns :
	  - int: Number of gallons required (rounded up)
   Preconditions:
	  - squareFeet must be non-negative.
   Postconditions:
	  - Returns the ceiling of squareFeet * gallonsPerSqFt.
*/
int calcGallonsPerRoom(double squareFeet) {
	return ceil(squareFeet * gallonsPerSqFt);
}

/*
   Function: writeEstimate
   Purpose : Displays the painting job estimate including paint and labor costs.
   Parameters:
	  - numRooms (int): Number of rooms to paint
	  - gallonsNeeded (double): Total gallons of paint required
	  - laborHours (double): Total labor hours required
	  - paintCharge (double): Total paint cost
	  - laborCharge (double): Total labor cost
	  - totalCost (double): Overall cost of the painting job
   Returns :
	  - None
   Preconditions:
	  - All input values must be correctly calculated.
   Postconditions:
	  - Outputs a formatted estimate to the console.
*/
void writeEstimate(int numRooms, double gallonsNeeded, double laborHours, double paintCharge, double laborCharge, double totalCost) {
	std::cout << "Estimate for painting " << numRooms << " rooms:" << std::endl;
	std::cout << "Gallons of paint to purchase: " << gallonsNeeded << std::endl;
	std::cout << "Number of hours required to paint rooms: " << laborHours << std::endl;
	std::cout << "Cost of Paint: $" << paintCharge << std::endl;
	std::cout << "Cost of labor: $" << laborCharge << std::endl;
	std::cout << "Total cost for job: $" << totalCost << std::endl;
}

/*
   Function: main
   Purpose : Controls the program flow for estimating the cost of a paint job.
   Parameters:
	  - None
   Returns :
	  - int: Exit status code (0 for success)
   Preconditions:
	  - None
   Postconditions:
	  - Runs the full paint estimate process and displays results.
*/
int main() {
	double paintCharge = 0, laborCharge = 0, gallonsNeeded = 0, laborHours = 0, totalCost = 0;
	double paintPrice, squareFeet, gallons, labor;

	int numRooms = getRooms();
	
	for (int i = 0; i < numRooms; ++i) {
		squareFeet = getSqFtPerRoom();
		gallons = calcGallonsPerRoom(squareFeet);
		gallonsNeeded += gallons;
		paintPrice = getPaintPricePerGallon();
		paintCharge += gallons * paintPrice;
		labor = squareFeet * laborPerSqFt;
		laborHours += labor;
		laborCharge += labor * laborChargePerHour;
	}
	
	totalCost = paintCharge + laborCharge;
	std::cout << std::fixed << std::setprecision(2);
	writeEstimate(numRooms, gallonsNeeded, laborHours, paintCharge, laborCharge, totalCost);
	
	return 0;
}