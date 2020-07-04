/*	Week 1 Programing Assignment 2 - Rainfall Ammounts Redux
Rian Booyer - ccis 242
Version 0.8*/
#include <iostream>
#include <string>
#include <iomanip>
//#include <algorithm>
using namespace std;

/*This program will be a modification of the program done in
CISS 241, Week 7 Programming Assignment 1. That was the
Rainfall Statistics program. For those who did not take 241,
that program description is below. Modify the Rainfall
Statistics program so that it displays a list of months,
sorted in the order of rainfall from highest to lowest.*/


//global variables


const int NumMonths = 12;
double rainTotal = 0;
double rainAverage = 0.00;
int rainLowest = 9999;
int rainHighest = 0;
int lowMonth;
int highMonth;

//preload functions

static double getTotal(double[], int);
double getAverage(double[], int);
double getLowest(double[], int, int&);
double getHighest(double[], int, int&);
void displayOutput(double, double, double, double);
void getInput();
void sortArray(const double linArray[], int numElms);
//Global Arrays
double tempArray[NumMonths];
double rainFallAmmounts[NumMonths];// = { 12,11,10,9,8,7,6,5,4,3,2,1 };
const string monthsOfYear[NumMonths] = { "January","February","March","April","May",
"June","July","August","September","October",
"November","December" };
string tempMonths[NumMonths];//to store temporary array of monthsOfYear for sorting with rainammounts in tempArray

void main()
{
	for (int i = 0; i < NumMonths; i++)
		tempMonths[i] = monthsOfYear[i];

	//getInput();
	getTotal(rainFallAmmounts, NumMonths);
	getAverage(rainFallAmmounts, NumMonths);
	getLowest(rainFallAmmounts, NumMonths, rainLowest);
	getHighest(rainFallAmmounts, NumMonths, rainHighest);
	sortArray(rainFallAmmounts, NumMonths);
	displayOutput(rainTotal, rainAverage, rainLowest, rainHighest);
	
	
}
void getInput()
{
	cout << "|---------------------------------------------------|" << endl;
	cout << "|                 Rainfall Ammounts                 |" << endl;
	cout << "|---------------------------------------------------|" << endl;
	cout << "|Please enter the rainfall for the following months.|" << endl;
	cout << "|---------------------------------------------------|" << endl;
	for (int count = 0; count < 12; count++) //displays month name from monthsOfYear then asks for input and stores in rainFallAmmount
	{
		cout << "| " << monthsOfYear[count] << ": ";
		cin >> rainFallAmmounts[count];
	}


}
double getTotal(double[], int)
{

	for (int count = 0; count < NumMonths; count++)
	{
		rainTotal += rainFallAmmounts[count];
	}
	return rainTotal;
}
double getAverage(double[], int)
{
	rainTotal = 0;
	for (int count = 0; count < NumMonths; count++)
		rainTotal += rainFallAmmounts[count];
	rainAverage = rainTotal / NumMonths;

	return rainAverage;
}
double getLowest(double[], int, int&)
{
	for (int count = 0; count < NumMonths; count++)
	{
		if (rainFallAmmounts[count] < rainLowest)
		{
			rainLowest = (int)(rainFallAmmounts[count]);
			lowMonth = count;
		}
	}

	return rainLowest;
}
double getHighest(double[], int, int&)
{
	for (int count = 0; count < NumMonths; count++)
	{
		if (rainFallAmmounts[count] > rainHighest)
		{
			rainHighest = (int)(rainFallAmmounts[count]);
			highMonth = count;
		}
	}

	return rainHighest;
}
void displayOutput(double, double, double, double)
{

	cout << char(0xc9) << string(50, char(0xcd)) << char(0xbb) << endl;
	cout << char(0xba)<< setw(25)<<right<< "Totals"<< setw(26)<<char(0xba)<< endl;
	cout << char(0xcc) << string(50, char(0xcd)) << char(0xb9) << endl;
	cout << char(0xba) << setw(33) << left << "Total Rain for the year was: " << setw(17) << left << rainTotal << char(0xba) << endl;
	cout <<char(0xba) << setw(33) << left << "Average Rain for the year Was: " << setw(17) << left << rainAverage << char(0xba) << endl;
	cout << char(0xba)<<setw(33)<<left<<"Month with the highest rainfall:" << setw(17) << left << monthsOfYear[highMonth] << char(0xba) << endl;
	cout << char(0xba) << setw(33) << left << "Month with the lowest rainfall: " << setw(17) << left<<monthsOfYear[lowMonth] <<char(0xba)<< endl;
	cout << char(0xc8) << string(50, char(0xcd)) << char(0xbc) << endl;

	cout << char(0xc9) << string(20, char(0xcd)) << char(0xbb) << endl;
	for (int i = 0; i < NumMonths; i++)
		cout << char(0xba) << setw(9) << left << tempMonths[i] << ":" << " " << setw(9) << left << tempArray[i] << char(0xba) << endl;
	cout << char(0xc8) << string(20, char(0xcd)) << char(0xbc) << endl;
	cout << endl;
	system("pause");
}
void sortArray(const double linArray[], int numElms)
{
	for (int i = 0; i < numElms; i++)
	{
		tempArray[i] = linArray[i];
	}

	int startScan, minIndex;
	double minValue;
	for (startScan = 0; startScan < (numElms - 1); startScan++)
	{
		minIndex = startScan;
		minValue = tempArray[startScan];
		for (int index = startScan + 1; index < numElms; index++)
		{
			if (tempArray[index] < minValue)
			{
				minValue = tempArray[index];
				minIndex = index;
			}
		}
		tempArray[minIndex] = tempArray[startScan];
		tempArray[startScan] = minValue;
		swap(tempMonths[minIndex], tempMonths[startScan]);


	}


}