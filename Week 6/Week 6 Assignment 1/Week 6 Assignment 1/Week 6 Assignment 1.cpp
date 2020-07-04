/*	Week 6 Programing Assignment 1 - Employee Class
Rian Booyer - ciss 242
Version 0.1*/
#include <iostream>
#include <string>
#include <iomanip>
#include "employee.h"
using namespace std;
/*assignment definition -
*/

//global variables

//predefine functions
void displayEmployee(Employee* const e);
void outputDisplay(Employee* const a, Employee* const b, Employee* const c);
void main()
{
	/*
	below are possible variables for user input into the class mutators.
	string employeeName, employeeDepartment, employeePosition;
	int employeeID;
	*/
	
	/* Following creates three Employee class objects, boss, clerk, and misc.*/
		Employee Boss("Bob Ross", 1, "Paint Department", "Manager");
		Employee Clerk("Porky Pig", 2);
		Employee misc;
		Clerk.setDep("Therapy");
		Clerk.setPos("Speach Therapist");
		misc.setAll("\"Sparky\" Thomas", 3, "Electrical", "Line Tester");
		outputDisplay(&Boss, &Clerk, &misc);
	
	system("pause");
}
/*outputDisplay - starts the display table with the three objects declared passed from main and calls displayEmployee
3 times, once for each object and starts a table form.*/
void outputDisplay(Employee* const a, Employee* const b, Employee* const c)
{
	cout << setw(18) << left << "Name" << setw(10) << left << "Number" << setw(20) << left << "Department" << setw(20) << left << "Position" << endl;
	cout << string(60, '-') << endl;
	displayEmployee(a);
	displayEmployee(b);
	displayEmployee(c);
}
/*displayEmployee - displays the employee objects information to screen in table format.*/
void displayEmployee(Employee* const e)
{
	

	cout << setw(18) << left << e->getName() << setw(10) << left << e->getId() << setw(20) << left << e->getDep() << setw(20) << left << e->getPos() << endl;
}

