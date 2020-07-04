#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;
// class declaration

class Employee
{
private:
	string name;
	int idNumber;
	string department;
	string position;
public:
	Employee();
	Employee(string n, int num, string dep, string pos);
	Employee(string n, int num);
	~Employee();
	void setDep(string dep);
	void setPos(string pos);
	void setId(int id);
	void setName(string n);
	string getName() const;
	int getId() const;
	string getDep() const;
	string getPos() const;	
	void setAll(string n, int id, string dep, string pos);
};

#endif

