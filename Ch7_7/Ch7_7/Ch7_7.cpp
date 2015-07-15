// Program Name:        Ch7_7: Inventory Class
// Program Description: This client program uses the Inventory class to perform
//                      simple operations on a retail store's inventory. This file
//                      should be combined with the Inventory.h file.
// Programmer Name:     Doug Shamoo
// Due Date:            April 14, 2015

#include "Inventory.h"
#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void getItemData(Inventory&);
void displayReceipt(const Inventory&);



int main() {
	Inventory item;   // A new inventory item with default fields

	getItemData(item);
	displayReceipt(item);

	return 0;
}

/************************************************************************
* This function is passed an inventory object by reference. User is     *
* asked to input id, cost, and quantity which are validated and then    *
* assigned to the object's member variables using its setter functions. *
************************************************************************/
void getItemData(Inventory& item) {
	int id,           // Item ID number to be input by user
		quant;        // Quantity of item to be input by user
	double cost;      // Cost of item (per unit) to be input by user

	// Get item ID number and validate
	cout << "Enter item number: ";
	cin >> id;
	while (id < 0) {
		cout << "Invalid item number. Item number must be an integer greater than 0." << endl
			 << "Enter a valid item number: ";
		cin >> id;
	}
	cout << endl;

	// Get item cost and validate
	cout << "Enter item cost (per unit): ";
	cin >> cost;
	while (cost < 0.0) {
		cout << "Invalid cost. Cost must be greater than 0." << endl
			 << "Enter a valid cost: ";
		cin >> cost;
	}
	cout << endl;

	// Get item quantity and validate
	cout << "Enter the quantity: ";
	cin >> quant;
	while (quant < 0) {
		cout << "Invalid quantity. Quantity must be an integer greater than 0." << endl
			 << "Enter a valid quantity: ";
		cin >> quant;
	}
	cout << endl;

	// Assign data to member variables of item, an Inventory object
	item.setItemNumber(id);
	item.setCost(cost);
	item.setQuantity(quant);
}

/***********************************************************************
* This function is passed an Inventory object as a constant reference. *
* It displays a simple summary receipt with item number, price,        *
* quantity, and total cost using the object's getter functions.        *
***********************************************************************/
void displayReceipt(const Inventory& item) {
	// Set the output formatting
	cout << fixed << showpoint << setprecision(2);

	cout << "Inventory Summary" << endl
		 << "Item: " << item.getItemNumber() << endl
		 << "Price per unit: $" << item.getCost() << endl
		 << "Quantity: " << item.getQuantity() << endl
		 << "Total Cost: $" << item.getTotalCost() << endl;
}