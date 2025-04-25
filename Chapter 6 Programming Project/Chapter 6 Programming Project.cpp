// A particular talent competition has five judges, each of whom awards a score between 0 and 10 to each performer.
// Fractional scores, such as 8.3, are allowed.A performer’s final score is determined by dropping the highest and lowest score received, 
// then averaging the three remaining scores.Write a modular program that uses this method to calculate a contestant’s score.

#include <iostream>
#include <array>
#include <iomanip>
#include <limits>

/*
   Function: getScore
   Purpose : Prompts the user to enter a judge's score between 0 and 10 and validates the input.
   Parameters:
	  - scores: Reference to a double variable where the input score will be stored.
   Returns : None
   Preconditions:
	  - User must input a number between 0 and 10.
   Postconditions:
	  - The scores contains a validated value between 0 and 10.
*/
void getScore(double& scores) {
	do {
		std::cout << "Enter judge score: ";
		std::cin >> scores;
		
		if (scores < 0 || scores > 10) {
			std::cout << "Score cannot be less than 0 or more than 10";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		};
	} while (scores < 0 || scores > 10);
}

/*
   Function: isLower
   Purpose : Compares two values and checks if the first is less than the second.
   Parameters:
	  - value1 (double): First value.
	  - value2 (double): Second value.
   Returns :
	  - bool: True if value1 < value2, otherwise false.
*/
bool isLower(double value1, double value2) {
	return value1 < value2;
}

/*
Function: isHigher
Purpose : Compares two values and checks if the first is greater than the second.
Parameters :
	- value1(double) : First value.
	- value2(double) : Second value.
	Returns :
	-bool : True if value1 > value2, otherwise false.
*/
bool isHigher(double value1, double value2) {
	return value1 > value2;
}

/*
   Function: calcAverage
   Purpose : Calculates the average score after dropping the highest and lowest scores.
   Parameters:
	  - total (double): The sum of all scores.
	  - scoreCount (int): Total number of scores.
	  - minScore (double): The lowest score to exclude.
	  - maxScore (double): The highest score to exclude.
   Returns :
	  - double: The average of the middle three scores.
   Preconditions:
	  - scoreCount must be at least 3.
   Postconditions:
	  - Returns the average after removing highest and lowest values.
*/
double calcAverage(double total, int scoreCount, double minScore, double maxScore) {
	return (total - minScore - maxScore) / (scoreCount - 2);
}

/*
   Function: main
   Purpose : Calculates a contestant’s final score in a talent competition based on 5 judge scores,
			 dropping the highest and lowest scores before averaging the rest.
*/
int main() {
	const int numJudges = 5;
	double total = 0.0, minScore, maxScore;
	std::array<double, numJudges> scores;
	
	getScore(scores[0]);
	total += scores[0];
	minScore = scores[0];
	maxScore = scores[0];

	for (int i = 1; i < numJudges; ++i) {
		getScore(scores[i]);
		total += scores[i];

		if (isLower(scores[i], minScore)) {
			minScore = scores[i];
		}
		if (isHigher(scores[i], maxScore)) {
			maxScore = scores[i];
		}
	}
	
	double average = calcAverage(total, numJudges, minScore, maxScore);

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\nFinal Score (average of middle 3): " << average << std::endl;

	return 0;
}
