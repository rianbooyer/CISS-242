/*	Week 3 Programing Assignment 1 - Password Verifier
Rian Booyer - ciss 242
Version 0.1*/
#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;
//global variables
bool validatedLoop = true;
//predefine functions
void getInput(char *array, int size);
bool validatePassword(char[] );
/*******************************************************
Pasword Verifier: create program to verify following
Password Should Be: 

at least 6 characters long, have min 1 uppercase and 1 lowercase characters,
have at least 1 number

display error if it doesn't meet minimum requirements.
*********************************************************/
int main()
{
	const int charArraySize = 61;
	char passwordArray[charArraySize];
	bool bValue;
	while (validatedLoop == true)//loops untill a valid password is entered then exits
	{
		getInput(passwordArray, charArraySize); //gets program input
		bValue = validatePassword(passwordArray); // validates password
	}
	if (bValue == true)
	{
		cout << "Failed" << endl;
	}
	else
		cout << "Passed" << endl;

	system("pause");

	return 0;
}
//getInput - get's initial input of password and passes the values back to main.
void getInput(char *array, int size)
{
	system("cls");
	cout << char(0xc9) << string(60, char(0xcd)) << char(0xbb) << endl;
	cout << setw(23) << left<<char(0xba) << "Password Verifier" <<setw(22)<<right<<char(0xba) << endl;
	cout << char(0xcc) << string(60, char(0xcd)) << char(0xb9) << endl;
	cout << char(0xba) << setw(60) << left << "The following password must be at least 6 characters long" << char(0xba) << endl;
	cout << char(0xba) << setw(60) << left << "and include the following:" << char(0xba) << endl;
	cout << char(0xba) << setw(60) << left << "" << char(0xba) << endl;
	cout << char(0xba) << setw(60) << left << "At least 1 Uppercase, 1 lowercase letter and at least 1" << char(0xba) << endl;
	cout << char(0xba) << setw(60) << left << "number." << char(0xba) << endl;
	cout << char(0xc8) << string(60, char(0xcd)) << char(0xbc) << endl;
	cout << "Please enter password: ";
	cin.getline(array, size);
	
}
/*validatePassword - Validates password contains required information, displays specific
errors if meetsDigit, meetsUpper, meetsLower is false this way the user knows what they did
also returns validateLoop to restart the input if password is not validated

i could have used a local bool variable in main for true/false for the validation loop
but was unsure if i could have altered the following function more than what i have already
bool validatePassword(char array[],bool loop) where validateLoop is passed into loop*/
/*validatePassword - validates password using 4 different checks, length is greater that 6, isDigit checks that the password
has at least 1 digit, isupper that checks for at least one uppercase letter, islower that checks for at least one lower case
letter. These checks are done inside a loop so that i can break back to main if there is a specific error*/
bool validatePassword(char array[])
{
	bool meetsDigit = false;
	bool meetsUpper = false;
	bool meetsLower = false;
	

	while (array)// not really needed but allows my code to be able to break and return to main if there is an error
	{
		int length = strlen(array);
		for (int count = 0;count < length; count++)
		{
			if (isdigit(array[count]))
				meetsDigit = true;
			if (isupper(array[count]))
				meetsUpper = true;
			if (islower(array[count]))
				meetsLower = true;
		}
		if (strlen(array) < 6)// moved inside loop to change to new bValue format
		{
			cout << "Your password is only " << strlen(array) << " characters. Your password needs to be more than 6 characters" << endl;
			system("pause");
			validatedLoop = true;
			break;
		}

		if (meetsDigit == true && meetsUpper == true && meetsLower == true)
		{
			cout << "Password is acceptable" << endl;
			validatedLoop = false;
			break;
		}
		if (meetsDigit == false)
		{
			cout << "ERROR: Your password must have at least one number between 0 and 9." << endl;
			system("pause");
			validatedLoop = true;
			break;
		}
		if (meetsUpper == false)
		{
			cout << "ERROR: Your password must have at least one uppercase letter." << endl;
			validatedLoop = true;
			system("pause");
			break;
		}
		if (meetsLower == false)
		{
			cout << "ERROR: Your password must have at least one lowercase letter." << endl;
			validatedLoop = true;
			system("pause");
			break;
		}
	}
	
	
	return validatedLoop;
}