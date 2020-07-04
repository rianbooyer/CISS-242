/*	Week 1 Programing Assignment 1 - Lottery Winners
Rian Booyer - ciss 241 ADE
Version 0.1*/
#include <iostream>
#include <iomanip>
#include <array>

using namespace std;
/*Assignment 1
Lottery Winners. Write a program that determines if 
the user is a winner in the lottery game. A lottery 
ticket buyer purchases 10 tickets a week, always 
playing the same 10 5-digit “lucky” combinations. 
The program will initialize an array with these numbers
and then lets the player enter this week’s winning 
5-digit number. The program should perform both a linear 
search and a binary search through the list of player’s 
numbers and report whether or not one of the tickets is 
a winner this week. Here are the numbers, and the array 
must be created with the values in this order: 
13579, 62483, 26791, 77777, 26792, 79422, 33445, 85647, 55555, 93121.
NOTE: The numbers are not in order, they must start this way.*/

int lotoNumber = 0,linPos,binPos;
bool linSearch = false;
bool binSearch = false;

int getInput();
bool linearSearch(int array[], int numElms, int value);
bool binarySearch(int linArray[], int numElms, int value);
void sortArray(int array[], int numElms);
void displayOutput(bool bin, bool lin);
void main()
{
	int lotoArray[10] = { 13579, 62483, 26791, 77777, 26792, 79422, 33445, 85647, 55555, 93121 };
	
	getInput();
	//lotoNumber = 93121;// for testing purposes
	linearSearch(lotoArray, 10, lotoNumber);
	sortArray(lotoArray, 10);
	binarySearch(lotoArray, 10, lotoNumber);
	displayOutput(binSearch, linSearch);
	system("pause");

	
}
int getInput()
{
	cout << "Please enter your number: ";
	cin >> lotoNumber;
	return lotoNumber;
}
bool linearSearch(int linArray[], int numElms, int value)
{
	/*following was from the book just slightly altered*/
	int index = 0;
	int position = -1;
	bool found = false;

	while (index < numElms && !found)
	{
		if (linArray[index] == value)
		{
			found = true;
			position = index;
		}
		index++;
	}
	linSearch = found;
	linPos = position;
	return linSearch;

}
bool binarySearch(int linArray[], int numElms, int value)
{
	/*following was from the book just slightly altered*/
		int first = 0, 
			last = numElms - 1,
			middle, 
			position = -1; 
		bool found = false; 
		while (!found && first <= last)
		{
			middle = (first + last) / 2; 
			if (linArray[middle] == value) 
			{
				found = true;
				position = middle;
			}
			else if (linArray[middle] > value) 
				last = middle - 1;
			else
				first = middle + 1; 
		}
		binSearch = found;
		binPos = position;
		return binSearch;
}
void sortArray(int linArray[], int numElms)
{
	
	
	int startScan, minIndex, minValue;
	for (startScan = 0; startScan < (numElms - 1); startScan++)
	{
		minIndex = startScan;
		minValue = linArray[startScan];
		for (int index = startScan + 1; index < numElms; index++)
		{
			if (linArray[index] < minValue)
			{
				minValue = linArray[index];
				minIndex = index;
			}
		}
		linArray[minIndex] = linArray[startScan];
		linArray[startScan] = minValue;
	
	}
	

}
void displayOutput(bool bin, bool lin)
{
	//following two lines can be uncommented out to display results from binary search and linear search
	cout << setw(10) << left << "Binary Search: " << boolalpha << bin << " at element: " << binPos << endl;
	cout << setw(10) << left << "Linear Search: " << boolalpha << lin << " at element: " << linPos << endl;
	
	
	/* The only reason i'm comparing bools for bin and lin is so that
	there is a verification that both the binary search and linear
	search functioned properly*/
	
	if (bin == true && lin == true)
		cout << "You are a winner!" << endl;
	else if (bin != true || lin != true)
		cout << "Sorry you didn't win today."<<endl;
}