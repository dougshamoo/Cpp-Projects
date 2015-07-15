//Program Name:        Ch5_24: Using Files- Total and Average Rainfall
//Program Description: This program calculates and displays total rainfall and average monthly rainfall,
//                     given a rainfall data file (specifically in the form of the provided rainfall.txt)
//Programmer Name:     Doug Shamoo
//Date:                March 17, 2015

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int monthCount = 0;              // Incremented in the input loop to count the number of months

	double averageRainfall = 0.0,    // Average monthly rainfall calculated from the input data and displayed, initialize to 0.0 in case there is no data in file
		   totalRainfall = 0.0,      // Total rainfall calculated from the input data and displayed, initialize to 0.0 in case there is no data in file
	       monthRainfall;            // Rainfall data for each month from the input file is read into this variable

	string startMonth,               // Stores the starting month from the input file to be displayed
		   endMonth;                 // Stores the ending month from the end file to be displayed

	ifstream inFile;                 // Declaring the input file stream to read in data from a file
	
	// Attempt to open the input file, in case of failure display an error message and end the program
	inFile.open("rainfall.txt");
	if (inFile.fail()) {
		cout << "There was an error opening the file." << endl
			 << "Make sure that the file is correctly named rainfall.txt" << endl
			 << "and that it is in the same directory as this program." << endl;
		return 0;
	}


	// Get the starting and ending months from the first two lines of the rainfall file
	inFile >> startMonth;
    inFile >> endMonth;

	// Until we reach the end of the file, read in monthly rainfall amounts and add to total rainfall, incrementing the number of months each time
	while (inFile >> monthRainfall) {
		totalRainfall += monthRainfall;
		monthCount++;
	}
	inFile.close();

	// Calculate the average rainfall by dividing the total rainfall by the number of months
	averageRainfall = totalRainfall / monthCount;
	
	// Display total rainfall and average monthly rainfall
	cout << "During the months of " << startMonth << "-" << endMonth << " the total rainfall was " << endl
		 << totalRainfall << " inches and the average monthly rainfall was " << averageRainfall << " inches." << endl;

	return 0;
}