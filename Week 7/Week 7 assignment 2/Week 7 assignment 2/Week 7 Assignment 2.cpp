/*	Week 7 Programing Assignment 2 - Register
Rian Booyer - ccis 242
Version 0.8*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "CashRegister.h"
#include "InventoryItem.h"
using namespace std;
 
//global variables

//predefine functions


bool checkUnits(CashRegister const cR,InventoryItem iI[],int pI, int u,int &au,bool &ub);
bool checkUnits(int u, bool &ub);
void main()
{	
	const int invItemArraySize = 5;
	int purchaseItem;
	int units,availUnits;
	double subTotal;
	bool unitsBool = false;
	bool repeatPurchase = false;
	char repPur;
	CashRegister registerOne;
	InventoryItem inventory[invItemArraySize] = { InventoryItem("Adjustable Wrench",9.95,10),
													InventoryItem("Screwdriver",1.95,20),
													InventoryItem("Pliers",4.95,35),
													InventoryItem("Ratchet",14.95,10), 
													InventoryItem("Socket Wrench",11.95,7)};
	do
	{
		system("cls");
		cout << setw(5) << left << "#" << setw(20) << left << "Item" << setw(15) << left << "Qty on Hand" << endl;
		cout << string(50, '-') << endl;
		for (int count = 0; count < invItemArraySize; count++)
		{
			cout << setw(5) << left << count + 1 << setw(20) << left << inventory[count].getDescription() << setw(15) << left << inventory[count].getUnits() << endl;
		}
		cout << "Which item above is being purchased? ";
		cin >> purchaseItem;
		do
		{
			cout << "How many units? ";
			cin >> units;

			//checks that the units are 0 and above
			checkUnits(units, unitsBool);
			
		//following checks if number of units selected is over available units
		checkUnits(registerOne,inventory,purchaseItem, units,availUnits,unitsBool);
		
		} while (unitsBool==true);

		availUnits = inventory[purchaseItem - 1].getUnits();
		inventory[purchaseItem - 1].setUnits(availUnits - units);// removes units from stock that were purchased
		subTotal = inventory[purchaseItem - 1].getCost() * units;//gets the subtotal
		registerOne.setPrice(subTotal);//assigns price with markup in cashregister class for register one.
		
		cout << setprecision(2) << fixed;
		cout << setw(12) << left << "Subtotal: " << "$" << registerOne.getPrice() << endl;
		cout << setw(12) << left << "Sales Tax: " << "$" << registerOne.getItemTax(subTotal) << endl;
		cout << setw(12) << left << "Total: " << "$" << registerOne.getPrice() + registerOne.getItemTax(subTotal) << endl;
		cout << "Do you want to purchase another item? ";
		cin >> repPur;
		if (toupper(repPur) == 'Y')
			repeatPurchase = true;
		
		if (toupper(repPur) == 'N')
			repeatPurchase = false;
		
	} while (repeatPurchase == true);
	system("pause");
}
/*checkUnits - First Iteration - this function checks to see if the number of units are zero or above
and returns a true or false for the unitsBool loop*/
bool checkUnits(int u, bool &ub)
{
	if (u < 0)
	{
		cout << "Number Of Units Must Be A Positive Number." << endl;
		ub = true;
		system("pause");
	}
	if (u >= 0)
		ub = false;
	
	return ub;
}
/*checkUnits - second iteration - I used the same name just to see for myself how c++ can have the ability like a 
class does it use the same name (in the class it's a constructor of course) for functions but use the items passed
to the function to select which function to use. 
	This function first checks to see if unitsBool (ub) is set to true from the previous iteration of checkUnits.
	if it is then it halts processing so that a new unit can be input. Secondly I added this function to check and
	see if the number of units entered were not more than the number of units available, if the number of units
	entered are more than what's available even if the previous checkUnits function allows the unitsBool loop to 
	continue this function will override the previous iteration and keep the loop going if the number of units input 
	are not available and tells the user to enter a number below available units +1*/
bool checkUnits(CashRegister const cR,InventoryItem iI[],int pI, int u,int &au,bool &ub)
{
	if (ub == true)
		return ub;
	
	au = iI[pI- 1].getUnits();
	if (au < u)
	{
		cout << "Number of units input is more than the number of units available." << endl;
		cout << "Please enter a number below: " << au+1 << endl;
		system("pause");
		ub = true;
	}
	if (au > u)
		ub = false;
	
	return ub;
}
