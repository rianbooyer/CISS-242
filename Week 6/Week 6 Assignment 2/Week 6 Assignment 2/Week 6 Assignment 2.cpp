/*	Week 6 Programing Assignment 1 - Circle Class
Rian Booyer - ciss 242
Version 0.1*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Circle.h"
using namespace std;
//global variables

// Predefine Functions
double getInput(double &radInput);

void main()
{
	double rad = 0.0;
	
	getInput(rad);
	cout << "rad is: " << rad << endl;
	Circle one;//circle object one with default constructor
	one.setRadius(rad);//sends input radius into circle object one for calculations.
	Circle two(rad);//circle object two with second constructor for passing the radius into the class operations


	/*I decided to keep things short and sweet with the output. I set the output up as a table to display that both the constructors work.*/
	cout << setprecision(2) << fixed;
	cout << setw(14) << left << "" << setw(16) << left << "Circle One" << setw(10) << left << "Circle Two" << endl;
	cout << string(50, '-') << endl;
	cout << setw(15) << left << "Radius" << setw(16) << left << one.getRadius() << setw(10) << left << two.getRadius() << endl;
	cout << setw(15) << left << "Area" << setw(16) << left << one.getArea() << setw(10) << left << two.getArea() << endl;
	cout << setw(15) << left << "Diameter" << setw(16) << left << one.getDiameter() << setw(10) << left << two.getDiameter() << endl;
	cout << setw(15) << left << "Circumference" << setw(16) << left << one.getCircumference() << setw(10) << left << two.getCircumference() << endl;
	
	system("pause");
}
/*getInput - asks user for radius of the circle and returns it to main. This is usually where i make a fancy output for the menu.*/
double getInput(double &radInput)
{
	
	cout << "Please enter circle's RADIUS: ";
	cin >> radInput;
	
	return radInput;
}
