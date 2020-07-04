/*	Week 7 Programing Assignment 1 - employee hourly rate
Rian Booyer - ccis 242
Version 0.8*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Payroll.h"
using namespace std;
/* The 
class will have data members for an employee’s hourly pay rate, number of 
hours worked and total pay for the week. All of the data members will be 
doubles. The class only needs one constructor which can be a default 
constructor that sets all data members to zero. Then add the mutators and 
accessor for the class. The program will have an array of 7 Payroll objects. 
The program will prompt the user for number of hours each employee has worked 
and will then display the amount of gross pay each has earned. Before asking 
the user for the hours, the program should set the pay rate for each employee
without user input. Validation: Do not accept values greater than 60 for the 
number of hours worked.*/

//global variables


//predefine functions

void main()
{
	const int payrollArNum = 7;
	Payroll one[payrollArNum];
	double hrs;
	bool hourloop = true;

	//set payrate without prompting user
	one[0].setPay(7.65);
	one[1].setPay(7.85);
	one[2].setPay(7.65);
	one[3].setPay(8.25);
	one[4].setPay(8.50);
	one[5].setPay(10.50);
	one[6].setPay(16.75);


	for (int count = 0; count < payrollArNum; count++)
	{
		do
		{
			cout << "Enter hours worked for employee "<<count+1<< ": ";
			cin >> hrs;
			one[count].setHours(hrs, hourloop);
			one[count].setTotalPay();
		} while (!hourloop);
	}
	
	/* The following creates a table for output of the employee number, hours the employee worked
	their hourly pay and gross Pay*/
	system("clear");
	cout << setw(11) << left << "Employee" << setw(10) << left << "|Hours Worked" <<setw(10) << left<<"|Hourly Pay" << setw(10) << left << "|Gross Pay " << endl;
	cout << string(60, '-') << endl;

	//loops through each employee.
	for (int count = 0; count <payrollArNum;count++)
	{
		cout << "Employee " << count + 1 << ": " <<setprecision(2) << fixed << setw(13) << left << one[count].getHours() << setw(11) << left << one[count].getPay() << setw(10) << left << one[count].getTotalPay() << endl;
		
	}
	system("pause");
}