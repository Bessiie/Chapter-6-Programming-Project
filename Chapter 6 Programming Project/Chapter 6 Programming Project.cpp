// A particular talent competition has five judges, each of whom awards a score between 0 and 10 to each performer.
// Fractional scores, such as 8.3, are allowed.A performer’s final score is determined by dropping the highest and lowest score received, 
// then averaging the three remaining scores.Write a modular program that uses this method to calculate a contestant’s score.

#include <iostream>
#include <iomanip>

using namespace std;

/*
    Function: getScore
    Purpose : Prompts user to enter a score and validates it (must be between 0 and 10).
    Returns : double - the validated score
*/
double getScore() {
    double score;
    do {
        cout << "Enter judge's score (0 - 10): ";
        cin >> score;
        if (score < 0 || score > 10) {
            cout << "Invalid score. Score must be between 0 and 10.\n";
        }
    } while (score < 0 || score > 10);
    return score;
}

/*
    Function: isLower
    Purpose : Compares two scores and returns true if the first is lower than the second.
    Parameters:
        - a, b: double values
    Returns : bool - true if a < b
*/
bool isLower(double a, double b) {
    return a < b;
}

/*
    Function: isHigher
    Purpose : Compares two scores and returns true if the first is higher than the second.
    Parameters:
        - a, b: double values
    Returns : bool - true if a > b
*/
bool isHigher(double a, double b) {
    return a > b;
}

/*
    Function: calcAverage
    Purpose : Calculates the average after dropping the highest and lowest scores.
    Parameters:
        - total: total of all scores
        - scoreCount: total number of scores
        - minScore: the lowest score
        - maxScore: the highest score
    Returns : double - the average score
*/
double calcAverage(double total, int scoreCount, double minScore, double maxScore) {
    return (total - minScore - maxScore) / (scoreCount - 2);
}

/*
    Function: main
    Purpose : Main driver function. Collects scores from five judges, drops the highest and lowest,
              and displays the average of the remaining three.
*/
int main() {
    const int numJudges = 5;
    double score, total = 0.0;
    double minScore, maxScore;

    // Get first score
    score = getScore();
    total = score;
    minScore = score;
    maxScore = score;

    // Get remaining 4 scores
    for (int i = 1; i < numJudges; i++) {
        score = getScore();
        total += score;

        if (isLower(score, minScore)) {
            minScore = score;
        }
        if (isHigher(score, maxScore)) {
            maxScore = score;
        }
    }

    // Calculate and display average
    double average = calcAverage(total, numJudges, minScore, maxScore);
    cout << fixed << setprecision(2);
    cout << "Final average score (with highest and lowest dropped): " << average << endl;

    return 0;
}
