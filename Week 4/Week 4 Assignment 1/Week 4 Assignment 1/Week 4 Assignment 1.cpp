/*	Week 4 Programing Assignment 1 - corporate divisions
Rian Booyer - ciss 242
Version 0.1*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//struct CorpStruct - creates the structure CorpStruct and defines the variables it is to contain.

struct Division
{
	string divName;
	double firstQuarter, secondQuarter, thirdQuarter, fourthQuarter, annualSales, quarterAv;
};

//predefine functions
void DisplayCorpInformation(const Division& east, const Division& west, const Division& north, const Division& south);
void FindTotalAndAverageSales(Division& div);
void GetDivisionSales(Division& div);
void isNeg(double s,bool &a);
void main()
{
	// local variables
	
	const int divSize = 4;

	/* creates the corpDivision array for the CorpStruct Structure. Initializes only the string divName for
	each division east, west, north, south*/
	
	Division corpDivision[divSize] = {
										{"East"},
										{"West"},
										{"North"},
										{"South"}
										};
	
	/*following function calls use a for loop to go through each division and cuts
	down the number of function call lines from 8 to 4 */
	
	for (int count = 0; count < divSize; count++)
	GetDivisionSales(corpDivision[count]);
	
	for (int count = 0; count < divSize; count++)
		FindTotalAndAverageSales(corpDivision[count]);

	DisplayCorpInformation(corpDivision[0], corpDivision[1], corpDivision[2], corpDivision[3]);
	system("pause");
}
/*DisplayCorpInformation - Displays output of data (after clearing the screen to match specified output
parameters) in the structure corpDivision array for each division annualSales
and quarterAV (quarter Average)*/
void DisplayCorpInformation(const Division& east, const Division& west, const Division& north, const Division& south)
{
	system("cls");
	cout << setprecision(2) << fixed;
	cout << "Total Annual Sales: " << endl;
		cout << "\tEast Division: " << east.annualSales << endl;
		cout << "\tWest Division: " << west.annualSales << endl;
		cout << "\tNorth Division: " << north.annualSales << endl;
		cout << "\tSouth Division: " << south.annualSales << endl;
	cout << "Average Quarterly Sales: " << endl;
		cout << "\tEast Division: " << east.quarterAv << endl;
		cout << "\tWest Division: " << west.quarterAv << endl;
		cout << "\tNorth Division: " << north.quarterAv << endl;
		cout << "\tSouth Division: " << south.quarterAv << endl;
}
/*FindTotalAndAverageSales - Calculates annual sales and quarter averages and stores them in the passed structure Division
corpDivision as div.annualSales and div.quarterAv*/
void FindTotalAndAverageSales(Division& div)
{
	div.annualSales = div.firstQuarter + div.secondQuarter + div.thirdQuarter + div.fourthQuarter;
	div.quarterAv = div.annualSales / 4;
}

/*GetDivisionSales - Gets input for the structure array for each division quarter and stores it in the
appropriate variable*/
void GetDivisionSales(Division& div)
{
	bool isneg = true;
	cout << "Enter the quarterly sales for the " << div.divName << " Division: " << endl;
	do
	{
		cout << "\tFirst quarter: ";
		cin >> div.firstQuarter;
		isNeg(div.firstQuarter,isneg);
	} while (isneg == true);
	do
	{
		cout << "\tSecond quarter: ";
		cin >> div.secondQuarter;
		isNeg(div.secondQuarter, isneg);
	} while (isneg == true);
	do
	{
		cout << "\tThird quarter: ";
		cin >> div.thirdQuarter;
		isNeg(div.thirdQuarter, isneg);
	} while (isneg == true);
	do
	{
		cout << "\tFourth quarter: ";
		cin >> div.fourthQuarter;
		isNeg(div.fourthQuarter, isneg);
	} while (isneg == true);
}
void isNeg(double s,bool &a)
{
	if (s >= 0)
		a = false;
	if (s < 0)
	{
		cout << "Please enter a number greater or equal to 0:" << endl;
		system("pause");
		a = true;
	}
	//return s;
	//return a;
}