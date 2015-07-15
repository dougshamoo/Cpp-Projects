// Program Name:        Ch10_7: Movie Statistics
// Program Description: This program uses a dynamically allocated array to gather statistical
//                      data about the number of movies college students see in a month. It 
//                      then calculates and displays average, median, and mode of the entered values.
// Programmer Name:     Doug Shamoo
// Due Date:            May 27, 2015

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void inputNumStudents(int&);
void inputMovieStats(int*, int);
void selectSort(int[], int);
void displayArr(int[], int);
double getMean(int[], int);
double getMedian(int[], int);
int getMode(int[], int);


int main() {
	int numStudents;  // Number of students to be input by user;
	
	int* movieStats;  // Pointer that will point to a dynamically allocated array
	                  // of integers representing the number of movies each student has seen.

	// Get number of students from user
	inputNumStudents(numStudents);

	// Dynamically allocate an array large enough to data for each student 
	movieStats = new int[numStudents];

	// Get number of movies seen by each student from user
	inputMovieStats(movieStats, numStudents);

	// Display the array before and after sorting
	cout << setw(10)<< left << "Unsorted: ";
	displayArr(movieStats, numStudents);

	selectSort(movieStats, numStudents);

	cout << setw(10) << "Sorted: ";
	displayArr(movieStats, numStudents);
	cout << endl;
	
	// Display the calculated statistics
	cout << setw(10) << "Mean: " << getMean(movieStats, numStudents) << endl;
	cout << setw(10) << "Median: " << getMedian(movieStats, numStudents) << endl;
	cout << setw(10) << "Mode: " << getMode(movieStats, numStudents) << endl;

	return 0;
}

/********************************************************************
* This function gets the number of students for which data should   *
* be input and stores it in a variable that is passed by reference. *
********************************************************************/ 
void inputNumStudents(int& numStudents) {
	int num;   // Number of students to be input by user
	
	cout << "How many students? ";
	cin >> num;
	// validate that the number is greater than 0.
	while (num <= 0) {
		cout << "Invalid. Enter an integer greater than 0: ";
		cin >> num;
	}
	numStudents = num;
	cout << endl;
}

/*******************************************************
* This function gets the number of movies each student *
* has seen from the user and stores them in the array  *
* referenced by the pointer passed to the function.    *
*******************************************************/
void inputMovieStats(int* stats, int size) {
	int numMovies;  // Number of movies each student has seen to be input by user

	// Get the values to add the to the array from the user
	cout << "Please enter the number of movies each student has seen:" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Student " << (i + 1) << ": ";
		cin >> numMovies;
		// Validate that number of movies is 0 or greater
		while (numMovies < 0) {
			cout << "Invalid. Enter an integer 0 or greater: ";
			cin >> numMovies;
		}
		
		// Assign the proper array value to numMovies
		stats[i] = numMovies;
	}
	cout << endl;
}

/**********************************************************************
* This function implements selection sort for an array of integers.   *
* It takes an integer array and sorts it in ascending order in place. *
**********************************************************************/
void selectSort(int array[], int size) {
	int startScan,     // Index to start the scan each time the outer for loop runs
		minIndex,      // Index of the current minimum element found in the inner for loop
	    minValue;      // Integer that has the lowest value

	// Advances startScan by 1 each iteration, swapping the value at startScan
	// index with the minimum value integer found in the inner for loop
	for (startScan = 0; startScan < size - 1; startScan++) {
		minIndex = startScan;
		minValue = array[startScan];

		// Checks each of the remaining unsorted integers and finds the one with the minimum value
		for (int index = startScan + 1; index < size; index++) {
			if (array[index] < minValue) {
				minValue = array[index];
				minIndex = index;
			}
		}
		// Swap minimum value integer and the integer at the startScan index
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}

/******************************************************
* This function takes an array and displays its items *
* in one line with spaces in between them using cout  *
******************************************************/
void displayArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

/************************************************************************
* This function calculates and returns the mean of an array of integers *
************************************************************************/
double getMean(int arr[], int size) {
	int sum = 0;  // Stores the total sum of all items
	double mean;  // The resulting mean value to be returned by function

	// Sum all items
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}

	// Calculate mean
	mean = double(sum) / size;

	return mean;
}

/********************************************************************************
* This function calculates and returns the median of a sorted array of integers *
********************************************************************************/
double getMedian(int arr[], int size) {
	double median;  // The resulting mean value to be returned by function
	int index = size / 2;   // If odd number of items, stores the index of the median
	                        // value. If even number of items, stores the index of the 
	                        // right value to be averaged to calculate the median.

	// Odd number of items
	if (size % 2 == 1) {
		median = arr[index];
	}
	// Even number of items
	else {
		median = (arr[index] + arr[index - 1]) / 2.0;
	}

	return median;
}
/*******************************************************************************
* This function calculates and returns the mode of a sorted array of integers. *
* If there is no mode (i.e. no repeated values or array of length=1), it       *
* will return the first value of the sorted array (i.e. the lowest value).     *
*******************************************************************************/
int getMode(int arr[], int size) {
	int modeIndex = 0,      // Stores the index of the mode value
		current = 0,        // Stores the index of the current number being test in the loop
		count = 1,          // Stores the number of times the current value has been seen in the loop
		highestCount = 1;   // Stores the highest count seen so far in the loop

	for (int i = 1; i < size; i++) {
		// if the item is the same as the item we are currently counting
		if (arr[i] == arr[current]) {
			count++;
			if (count > highestCount) {
				highestCount = count;
				modeIndex = current;
			}
		}
		// if the number is different than the item we are currently counting
		else {
			current = i;
			count = 1;
		}
	}
	
	return arr[modeIndex];
}