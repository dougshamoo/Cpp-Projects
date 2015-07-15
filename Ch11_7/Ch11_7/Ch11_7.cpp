// Program Name:        Ch11_7: Corporate Sales
// Program Description: This client program is designed to use the DivSales class,
//                      defined in DivSales.h.  This program gets quarterly sales info
//                      from the user, which it uses to calculate and display a table of
//                      quarterly sales data and totals.
// Programmer Name:     Doug Shamoo
// Due Date:            May 27, 2015

#include <iostream>
#include <iomanip>
#include "DivSales.h"
using namespace std;

// Function prototypes
void inputSales(double&, int);
void displayDivSales(DivSales[], int);

// Definition of the static member of the DivSales class
double DivSales::totalSales = 0;


int main() {
	const int NUM_DIVS = 6;         // Number of divisions in the company
	DivSales divisions[NUM_DIVS];   // Array of DivSales objects, one for each division
	
	// Get quarterly sales for each division
	for (int i = 0; i < NUM_DIVS; i++) {
		double q1,      // Four local variables to hold quarterly sales 
			q2,       // input by user. Will be passed by reference
			q3,       // into inputSales for input and validation.
			q4;

		// Get and validate quarterly sales input
		cout << "Enter Sales for Division " << i + 1 << ":" << endl
			<< "---------------------------" << endl;
		inputSales(q1, 1);
		inputSales(q2, 2);
		inputSales(q3, 3);
		inputSales(q4, 4);
		
		// Set quarterly sales in the DivSales object
		divisions[i].setQuarterSales(q1, q2, q3, q4);
		cout << endl;
	}
	cout << endl;
	
	// Display the data to the user
	displayDivSales(divisions, NUM_DIVS);

	return 0;
}

/***********************************************************
* This function gets an input from the user, validates it, *
* then stores it in the variable passed by reference. It   *
* displays the quarter number accoring to qNum.            *
***********************************************************/
void inputSales(double& qSales, int qNum) {
	cout << "Quarter " << qNum << ": ";
	cin >> qSales;
	
	// Validate that quarterly sales number is > 0
	while (qSales < 0) {
		cout << "Invalid. Re-enter Quarter " << qNum << " Sales: ";
		cin >> qSales;
	}
}

/*****************************************************************
* This function takes an array of DivSales objects, and displays *
* a table showing quarterly sales by division, quarterly totals, *
* and the total corporate sales for the entire year.             *
*****************************************************************/
void displayDivSales(DivSales divs[], int numDivs) {
	// Set output formatting
	cout << fixed << showpoint << setprecision(2);
    
	// Display report header
	cout << setw(4) << "Div." << setw(11) << "Q1" << setw(11) << "Q2" << setw(11) << "Q3" << setw(11) << "Q4" << setw(11) << "Total" << endl;
	cout << "-----------------------------------------------------------" << endl;


	for (int i = 0; i < numDivs; i++) {
		double q1 = divs[i].getQuarter(0),  // Get the sales data for each quarter
			q2 = divs[i].getQuarter(1),     // to be displayed in the table
			q3 = divs[i].getQuarter(2),
			q4 = divs[i].getQuarter(3),
			divTotal = q1 + q2 + q3 + q4;
		
		cout << setw(4) << (i + 1) << setw(11) << q1 << setw(11) << q2 << setw(11) << q3 << setw(11) << q4 << setw(11) << divTotal << endl;
	}

	// Display final total corporate sales across all divisions for the entire year
	cout <<  setw(59) << "----------" << endl;
	cout << setw(48) << "Total Annual Corporate Sales:" << setw(11) << divs[0].getTotalSales() << endl;
	cout << endl;
}