#pragma once
class Payroll
{
	/*will have data members for an employee’s hourly pay rate, number of 
hours worked and total pay for the week. All of the data members will be 
doubles. The class only needs one constructor which can be a default 
constructor that sets all data members to zero*/
private:
	double hourlyPay;
	double hoursWorked;
	double totalPay;
public:
	Payroll();
	~Payroll();
	void setPay(double pay);
	bool setHours(double hours,bool &tf);
	void setTotalPay();
	double getPay() const;
	double getHours() const;
	double getTotalPay() const;
};

