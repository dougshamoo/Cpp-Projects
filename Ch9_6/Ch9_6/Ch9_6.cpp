//Program Name:        Ch9_6: String Selection Sort
//Program Description: This program is a driver for testing the
//                     selectionSort function on a string array of names.
//Programmer Name:     Doug Shamoo
//Due Date:            May 5, 2015

#include <string>
#include <iostream>
using namespace std;

// Function prototypes
void selectionSort(string [], int);
void displayArray(string [], int);

int main()
{
	const int SIZE = 20;  // Size of the array of strings to sort

	string name[SIZE] =   // String array of names to be sorted alphabetically
	    { "Collins, Bill", "Smith, Bart", "Michalski, Joe", "Griffin, Jim",
	    "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
	    "Allison, Jeff", "Moreno, Juan", "Wolfe, Bill", "Whitman, Jean",
	    "Moretti, Bella", "Wu, Hong", "Patel, Renee", "Harrison, Rose",
	    "Smith, Cathy", "Conroy, Pat", "Kelly, Sean", "Holland, Beth" };

	// Display the list before sorting
	cout << "Before sorting:" << endl
		<< "---------------" << endl;
	displayArray(name, SIZE);

	// Sort the array in place
	selectionSort(name, SIZE);

	// Display the list after sorting
	cout << "After sorting:" << endl
		<< "--------------" << endl;
	displayArray(name, SIZE);
}

/******************************************************************
* This function implements selection sort for an array of strings *
* to sort them alphabetically. It takes the string array and      *
* array size and sorts the array in place, returning nothing.     *
******************************************************************/
void selectionSort(string array[], int size) {
	int startScan,     // Index to start the scan each time the outer for loop runs
		minIndex;      // Index of the current minimum element found in the inner for loop
    string minString;  // String that has the lowest value and is thus the first alphabetically among still unsorted strings

	// Advances startScan by 1 each iteration, swapping the String at startScan
	// index with the minimum value string found in the inner for loop
	for (startScan = 0; startScan < size - 1; startScan++) {
		minIndex = startScan;
		minString = array[startScan];
		
		// Checks each of the remaining unsorted strings and finds the one with the minimum value
		for (int index = startScan + 1; index < size; index++) {
			if (array[index] < minString) {
				minString = array[index];
				minIndex = index;
			}
		}
		// Swap minimum value string and the string at the startScan index
		array[minIndex] = array[startScan];
		array[startScan] = minString;
	}
}

/************************************************
* This function takes an array and its size and *
* outputs its elements to the console as a list *
************************************************/
void displayArray(string array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << endl;
	}
	cout << endl;
}