// Program Name:        Ch12_10: Password Verifier (Ch.12 #12 in 7th Edition)
// Program Description: This program takes a password from the user and verifies that
//                      it satisfies all requirements. If it does not satisfy the requirements,
//                      the reasons are displayed to the user.
// Programmer Name:     Doug Shamoo
// Due Date:            May 27, 2015

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void getPassword(string&);
bool checkPassword(string, int);
bool hasMinCh(string, int);
bool hasUpper(string);
bool hasLower(string);
bool hasDigit(string);

int main() {
	const int MIN_CH = 6;   // Minimum number of characters that the password must have
	
	string password;        // Password to be input by the user

	// Get password from the user
	getPassword(password);
	
	// Check the password and display either success or failure.
	// Running the check will also display any error messages.
	if (checkPassword(password, MIN_CH)) {
		cout << "Success: Password confirmed." << endl;
	}
	else {
		cout << "Failure: Please see the errors above and try again." << endl;
	}

	return 0;
}

/********************************************************************************
* Gets password from user and stores it in variable that is passed by reference *
********************************************************************************/
void getPassword(string& password) {
	cout << "Please enter your desired password: ";
	cin >> password;
	cout << endl;
}

/*************************************************************************************
* Checks password using the other bool functions below. Returns true if the password *
* passes all checks. If not, returns false and prints appropriate error messages.    *
*************************************************************************************/
bool checkPassword(string password, int minNumCh) {
	bool isGood = true;   // Keeps track of whether the password has failed or not

	if (!hasMinCh(password, minNumCh)) {
		isGood = false;
		cout << "Error: Password must be at least " << minNumCh << " characters." << endl;
	}

	if (!hasUpper(password)) {
		isGood = false;
		cout << "Error: Password must contain at least one uppercase letter." << endl;
	}

	if (!hasLower(password)) {
		isGood = false;
		cout << "Error: Password must contain at least one lowercase letter." << endl;
	}

	if (!hasDigit(password)) {
		isGood = false;
		cout << "Error: Password must contain at least one digit." << endl;
	}

	return isGood;
}

/*******************************************************************************************
* Returns true if password has at least the minimum number of characters, otherwise false. *
*******************************************************************************************/
bool hasMinCh(string password, int minNumCh) {
	return (password.length() >= minNumCh);
}

/***********************************************************************************
* Returns true if the password has at least one uppercase letter, otherwise false. *
***********************************************************************************/
bool hasUpper(string password) {
	char ch;
	for (int i = 0; i < password.length(); i++) {
		ch = password.at(i);
		if (isupper(ch))
			return true;
	}
	return false;
}

/***********************************************************************************
* Returns true if the password has at least one lowercase letter, otherwise false. *
***********************************************************************************/
bool hasLower(string password) {
	char ch;
	for (int i = 0; i < password.length(); i++) {
		ch = password.at(i);
		if (islower(ch))
			return true;
	}
	return false;
}

/************************************************************************
* Returns true if the password has at least one digit, otherwise false. *
************************************************************************/
bool hasDigit(string password) {
	char ch;
	for (int i = 0; i < password.length(); i++) {
		ch = password.at(i);
		if (isdigit(ch))
			return true;
	}
	return false;
}