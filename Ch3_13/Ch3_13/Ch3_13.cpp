// This program calculates sales tax.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	double productSales, totalIncome, countyTax, stateTax, totalTax;
	double countyTaxRate = .02, stateTaxRate = .04;
	double totalTaxRate = countyTaxRate + stateTaxRate;
	string month, year;

	// Get month and year.
	cout << "What is the month? ";
	getline(cin, month);

	cout << "What is the year? ";
	getline(cin, year);

	// Get the total collected income.
	cout << "What is the total amount of money collected at the register? ";
	cin >> totalIncome;

	// Calculate the product sales as follows, productSales = totalIncome / (1 + totalTaxRate)
	productSales = totalIncome / (1 + totalTaxRate);

	// Calculate county tax, state tax, and total tax.
	countyTax = countyTaxRate * productSales;
	stateTax = stateTaxRate * productSales;
	totalTax = countyTax + stateTax;

	// Display the report.
	cout << endl;
	cout << "Month: " << month << " " << year << endl;
	cout << "--------------------" << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(21) << "Total Collected:" << "$" << right << setw(9) << totalIncome << endl;
	cout << left << setw(21) << "Sales:"<< "$" << right << setw(9) << productSales << endl;
	cout << left << setw(21) << "County Sales Tax:" << "$" << right << setw(9) << countyTax << endl;
	cout << left << setw(21) << "State Sales Tax:" << "$" << right << setw(9) << stateTax << endl;
	cout << left << setw(21) << "Total Sales Tax:" << "$" << right << setw(9) << totalTax << endl;
}