/*	Week 3 Programing Assignment 2 - Phone Number List
Rian Booyer - ciss 242
Version 0.1*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;
// global variables

//predefine functions
string getInput(string &search);
void searchArray(string search, char array[][30], int size);

int main()
{
	const int arraySize = 11;
	const int arrayLength = 30;
	string searchParmTemp;
	char charArray[arraySize][arrayLength]= { "Rene Javens, 678-1223"
									, "Joe Looney, 586-0097"
									, "Geri Palmer, 223-8787"
									, "Lynn Presnell, 887-1212"
									, "Bill Wolfe, 223-8878"
									, "Sam Wiggins, 486-0998"
									, "Bob Kain, 586-8712"
									, "Tim Haynes, 586-7676"
									, "John Johnson, 223-9037"
									, "Jean James, 678-4939"
									, "Ron Palmer, 486-2783" };
	getInput(searchParmTemp);
	searchArray(searchParmTemp, charArray, arraySize);
	system("pause");
	return 0;
}

/*getInput - displays main information and asks for input then stores as string in variable search*/
string getInput(string &search)
{
	system("cls");
	cout << char(0xc9) << string(60, char(0xcd)) << char(0xbb) << endl;
	cout << setw(23) << left << char(0xba) << "Phone Number List" << setw(22) << right << char(0xba) << endl;
	cout << char(0xcc) << string(60, char(0xcd)) << char(0xb9) << endl;
	cout << char(0xba) << setw(60) << left << "Your parameters can be alphanumeric in nature." << char(0xba) << endl;
	cout << char(0xc8) << string(60, char(0xcd)) << char(0xbc) << endl;
	cout << "Please enter search parameters: ";
	cin >> search;
	return search;
}

/*searchArray - uses passed information to search the array after copying a string to a char array
searchParm using strcpy_s because according to visual studio 2015 strcpy is depreciated and it wants
you to use strcpy_s afterward the result is used with strstr to search the char array "charArray" for
the specified input.*/
void searchArray(string search,char array[][30],int size)
{
	char searchParm[30];
	strcpy_s(searchParm, search.c_str());
	for (int count = 0; count < size; count++)
	{
		char *stringPointer = nullptr;
		stringPointer = strstr(array[count], searchParm);
		if (stringPointer != nullptr)
		cout << array[count] << endl;
	}
}