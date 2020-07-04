/*	Week 2 Programing Assignment 2 - double array with pointers
Rian Booyer - ccis 242
Version 0.8* */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//function declaration
int* expandArray(int[], int);
void showArray(int[], int);

int main()
{
	const int arraySize = 10;
	int mainArray[arraySize] = { 1,2,3,4,5,6,7,8,9,10 };
	int *secondArray = nullptr;
	
	secondArray = expandArray(mainArray, arraySize);
	
	showArray(secondArray, arraySize * 2);

	system("pause");
	return 0;
}
int* expandArray(int eArray[] , int size)//indicates the function returns a pointer to an int
{
	int *expandSecondArray = new int[size * 2];
	for (int count = 0; count < size*2; count++)
	{
		if (count < size)
		{
			expandSecondArray[count] = eArray[count];
		}
		if (count >= size)
			expandSecondArray[count] = 0;
	}
	
	return expandSecondArray;
}
void showArray(int sArray[], int size)
{
	system("cls");
	cout << string(60, '-') << endl;
	cout << string(20,' ')<< "Array Doubled" << endl;
	cout << string(60, '-') << endl;
	for (int count = 0; count < size; count++)
	{
		cout << " " << sArray[count];
		}
	cout << endl;
}