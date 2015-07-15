// This program calculates a theater's gros and net box office profit for a night.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string movie;
	int adultTickets, childTickets;
	double grossProfit, paidToDistributor, netProfit;

	// Get the name of the movie.
	cout << "What is the name of the movie? ";
	getline(cin, movie);

	// Get the number of adult tickets sold.
	cout << "How many adult tickets were sold? ";
	cin >> adultTickets;

	// Get the number of child tickets sold.
	cout << "How many child tickets were sold? ";
	cin >> childTickets;

	// Calculate the gross box office profit, amount paid to distributor, and net box office profit.
	// Adult tickets are $6.00, Child tickets are $3.00, and the theater keeps 20% of the gross box office profit.
	grossProfit = adultTickets * 6.00 + childTickets * 3.00;
	paidToDistributor = grossProfit * .80;
	netProfit = grossProfit * .20;

	// Display the report. setw() values vary to match the whitespace used in the book's program specification.
	cout << endl;
	cout << left << setw(30) << "Movie Name:" << "\"" << movie << "\"" << endl;
	cout << left << setw(32) << "Adult Tickets Sold:" << adultTickets << endl;
	cout << left << setw(32) << "Child Tickets Sold:" << childTickets << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(32) << "Gross Box Office Profit:" << "$" << right << setw(8) << grossProfit << endl;
	cout << left << setw(31) << "Amount Paid to Distributor:" << "-$" << right << setw(8) << paidToDistributor << endl;
	cout << left << setw(32) << "Net Box Office Profit:" << "$" << right << setw(8) << netProfit << endl;

	return 0;
}