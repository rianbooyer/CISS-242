/*	Week 2 Programing Assignment 1 - Test scores and pointers
Rian Booyer - ccis 242
Version 0.8*/
#include <iostream>
#include <string>
#include <iomanip>

//#include <algorithm>
using namespace std;
double scoreAverage = 0;

//predefine functions
void getGrades(double * score, int size);
void displayGrades(double* score, int size, double avg);
void sort(double* score, int size);
double average(double* score, int numScores);
bool isneg(double input,bool &negTF);

int main()
{
	int userArraySize = 0;
	double UAS = 0;
	double *ptrArray = nullptr;
	bool testNeg = false;
	do
	{
		if (system("cls")) system("clear");
		cout << "How many tests do you wish to score: ";
		cin >> UAS;
		userArraySize = int (UAS);//fixes a problem where it would loop if a float or double is entered
		isneg(userArraySize,testNeg);//checks for negative value
	} while (testNeg==false);
	
	
	ptrArray = new double[userArraySize];
		
	
	getGrades(ptrArray, userArraySize);
	sort(ptrArray, userArraySize);
	average(ptrArray, userArraySize);
	displayGrades(ptrArray, userArraySize, scoreAverage);
	

	delete[] ptrArray;
	system("pause");
	return 0;

}
bool isneg(double input,bool &negTF)
{
	if (input <= 0)
	{
		cout << "Please enter number greater than 0." << endl;
		system("pause");
		negTF = false;
	}
	if (input > 0)
	{
		
		negTF = true;
		
	}
	
	//return bool;
	return negTF;

}
void getGrades(double * score, int size)
{
	double grade;
	bool getGradesNeg = false;
	for (int count = 0; count < size; count++)
	{
		do
		{
			cout << "Test " << (count + 1) << ": ";
			cin >> grade;
			isneg(grade, getGradesNeg);
			
		} while (getGradesNeg==false);
			score[count] = grade;

	}
}
void displayGrades(double* score, int size, double avg)
{
	if (system("CLS")) system("clear");
	cout << "Score" << endl;
	cout << string(5,char (0xc4)) << endl;
	for (int count = 0; count < size; count++)
	{
		cout << " " <<setprecision(2)<<fixed<< score[count]<<endl<<endl;
	}
	cout << "Average Score: " << avg << endl;
}
void sort(double* score, int size)
{
	int startScan, minIndex;
	double minValue;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = score[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (score[index] < minValue)
			{
				minValue = score[index];
				minIndex = index;
			}
		}
		score[minIndex] = score[startScan];
		score[startScan] = minValue;

	}
	
	//return score;

}
double average(double* score, int numScores)
{
	double total = 0.0;
	for (int count = 0; count < numScores; count++)
	{
		total += score[count];
	}
	scoreAverage = (total / numScores);
	return 0;
}