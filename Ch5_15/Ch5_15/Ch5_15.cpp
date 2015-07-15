//Program name:        Ch5_15: Population
//Program Description: This program predicts the size of a population of organisms given the
//                     number of starting organisms, average daily population increase, and number of days.
//Programmer Name:     Doug Shamoo
//Date:                March 17, 2015

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int startPop,     // starting number of organisms input by the user
		numDays;      // number of days that the organisms will multiply input by the user
	
	double rate,      // average daily population increase input by the user
	       endPop;    // predicted ending number of organisms computed, rounded and displayed as a whole number for each day

	// Get starting population from the user, validate that it is >= 2
	do {
		cout << "Enter the starting number of organisms" << endl << "(Must be >= 2): ";
		cin >> startPop;
	} while (startPop < 2);
	cout << endl;

	// Get average daily population increase, validate that it is >= 0
	do {
		cout << "Enter the average daily population increase as a percentage in decimal form" << endl << "(Must be >= 0): ";
		cin >> rate;
	} while (rate < 0);
	cout << endl;

	// Get number of days that organisms will multiply
	do {
		cout << "Enter the number of days they will multiply" << endl << "(Must be > 0): ";
		cin >> numDays;
	} while (numDays <= 0);
	cout << endl;

	// start with endPop equal to startPop, then compute endPop for each additional day and display it
	endPop = startPop;
	for (int day = 1; day <= numDays; day++)
	{
		endPop = endPop * (1 + rate);
		cout << "Day " << setw(3) << day << ":" << setw(8) << fixed << setprecision(0) << endPop << endl;
	}

	return 0;
}