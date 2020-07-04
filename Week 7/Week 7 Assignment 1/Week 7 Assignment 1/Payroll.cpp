#include "Payroll.h"
#include <iostream>
using namespace std;
/*double hourlyPay, hoursWorked, totalPay;*/

Payroll::Payroll()
{
	hourlyPay = 0.0;
	hoursWorked = 0.0;
	totalPay = 0.0;
}


Payroll::~Payroll()
{
}

void Payroll::setPay(double pay)
{
	hourlyPay = pay;
}
bool Payroll::setHours(double hours,bool &tf)
{
	if (hours > 60)
	{
		cout << "Invalid Number Of Hours." << endl;
		system("pause");
		tf = false;
	}
	if (hours <= 60)
	{
		hoursWorked = hours;
		tf = true;
	}
	return tf;
}
void Payroll::setTotalPay()
{
	totalPay = hoursWorked * hourlyPay;
}
double Payroll::getPay() const
{
	return hourlyPay;
}
double Payroll::getHours() const
{
	return hoursWorked;
}
double Payroll::getTotalPay() const
{
	return totalPay;
}
