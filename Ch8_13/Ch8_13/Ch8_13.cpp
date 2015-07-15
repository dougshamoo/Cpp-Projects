// Program Name:        Ch8_13: Array of Payroll Objects
// Program Description: This client program uses the Payroll class defined in PayrollType.h
//                      to calculate the gross pay of employees, reading their hours worked
//                      and hourly pay from a .dat file. This file should be combined with 
//                      the PayrollType.h and PayrollType.cpp files.
// Programmer Name:     Doug Shamoo
// Due Date:            May 5, 2015

#include "PayrollType.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void displayAllGrossPay(Payroll [], int); // Function prototype

int main() {
	const int NUM_EMPLOYEES = 7;       // The number of employee payroll objects to create
	Payroll payrolls[NUM_EMPLOYEES];   // Array of Payroll objects to store and calculate information
	ifstream dataFile;                 // File stream to read the hours and hourly pay from the data file

	// Open the data file
	dataFile.open("payroll.dat");
	if (!dataFile)
		cout << "Error opening data file" << endl;
	else {
		// Read in and set hours and hourly pay for each employee Payroll object
		for (int i = 0; i < NUM_EMPLOYEES; i++) {
			double inputHours,         // Used to temporarily store the input hours from data file
				inputRate;             // Used to temporarily store the input hourly rate from data file
			dataFile >> inputHours;
			dataFile >> inputRate;
			
			// Set member variables of the Payroll object
			payrolls[i].setHoursWorked(inputHours);
			payrolls[i].setPayRate(inputRate);
		}
		// Display the gross pay of each employee
		displayAllGrossPay(payrolls, NUM_EMPLOYEES);
	}
	dataFile.close();

	return 0;
}

/*************************************************************
* This function takes an array of Payroll objects and the    *
* number of employees and displays each employees gross pay. *
*************************************************************/
void displayAllGrossPay(Payroll employeePayrolls[], int numEmployees) {
	// Output formatting
	cout << fixed << showpoint << setprecision(2);
	
	// Display header
	cout << "Employee Gross Pay" << endl
		<< "------------------" << endl;

	// Employees are assigned a number 1 to (numEmployees + 1) in the order that they were read in.
	// Displays employee numbers and gross pay as a list.
	for (int i = 0; i < numEmployees; i++) {
		cout << "Employee " << i + 1 << ": " << employeePayrolls[i].getGrossPay() << endl;
	}
	cout << endl;
}