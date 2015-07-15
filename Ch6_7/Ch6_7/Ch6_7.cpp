//Program Name:        Ch6_7: Lowest Score Drop
//Program Description: This program calculates and displays the average
//                     of 5 user-inputted scores, dropping the lowest one.
//Programmer Name:     Doug Shamoo
//Due Date:            April 14, 2015

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getScore(int&);
void calcAverage(int, int, int, int, int, double&);
int findLowest(int, int, int, int, int);

int main() {
	int score1,            // 5 user-inputted scores
		score2,
		score3,
		score4,
		score5;

	double averageScore;  // Average score to display

	// Get and store the 5 scores from the user, passing by reference
	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);

	// Calculate and store the average score, passing by reference
	calcAverage(score1, score2, score3, score4, score5, averageScore);

	// Display the average score (not required by the assignment).
	// Comment the following line out to stop displaying the results.
	cout << "The average score is " << averageScore << endl;

	return 0;
}

/**********************************************************
* This function is passed a score variable by reference,  *
* validates input and then stores it in the variable.     *
**********************************************************/
void getScore(int& score) {
	cout << "Enter a score (0-100): ";
	cin >> score;
	// Validation
	while (score < 0 || score > 100) {
		cout << "Invalid score, please enter an integer 0-100: ";
		cin >> score;
	}
}

/******************************************************************************
* This function is passed 5 scores by value and an avg variable by reference. *
* Calls findLowest to determine which score to drop, calculates the average   *
* and stores it in the variable avg.                                          *
******************************************************************************/
void calcAverage(int s1, int s2, int s3, int s4, int s5, double& avg) {
	int total = s1 + s2 + s3 + s4 + s5;   // Local variable to store the sum of all scores
	
	// Find and subtract the lowest score from total, then calculate average
	total -= findLowest(s1, s2, s3, s4, s5);
	avg = total / 4.0;
}

/*************************************************************************************** 
* This function is passed 5 scores by value and returns the value of the lowest score. *
***************************************************************************************/
int findLowest(int s1, int s2, int s3, int s4, int s5) {
	int lowest = s1;  // Local variable to store lowest score, intialized to s1

	// Go through all scores checking and updating lowest
	if (s2 < lowest)
		lowest = s2;
	if (s3 < lowest)
		lowest = s3;
	if (s4 < lowest)
		lowest = s4;
	if (s5 < lowest)
		lowest = s5;

	return lowest;
}