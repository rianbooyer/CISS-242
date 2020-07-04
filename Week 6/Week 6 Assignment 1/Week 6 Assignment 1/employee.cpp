#include <iostream>
#include <string>
#include "employee.h"
using namespace std;
Employee::Employee()//Default Constructor
{
	name = "";
	idNumber = 0;
	department = "";
	position = "";
}

Employee::Employee(string n, int num, string dep, string pos)
{
	name = n;
	idNumber = num;
	department = dep;
	position = pos;
}
Employee::Employee(string n, int num)
{
	name = n;
	idNumber = num;
	department = "";
	position = "";
}
Employee::~Employee()//destructor
{

}
string Employee::getName() const
{
	return name;
}
int Employee::getId() const
{
	return idNumber;
}
string Employee::getDep() const
{
	return department;
}
string Employee::getPos() const
{
	return position;
}

void Employee::setDep(string dep)
{
	department = dep;
}
void Employee::setPos(string pos)
{
	position = pos;
}
void Employee::setId(int id)
{	idNumber = id; }
void Employee::setName(string n)
{	name = n; }
void Employee::setAll(string n, int id, string dep, string pos)
{
	name = n;
	idNumber = id;
	department = dep;
	position = pos;
}

