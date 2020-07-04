/*	Week 4 Programing Assignment 2 - soccer scores
Rian Booyer - ciss 242
Version 0.1*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//global variables

//structures
struct Player
{
	string pName;
	int pNumber;
	int pPointsScored;
};

//predefine functions

void getPlayerInfo(Player &pI,int cnt);
void showInfo(Player);
int getTotalPoints(const Player[], int &tP);
void showHighest(Player[], int);
void isNeg(int tempNum,bool &t);

void main()
{
	//local variables
	const int arraySize = 12;
	int totalPoints = 0;
	int highestScore = 0;
	
	//structure array
	Player pInfo[arraySize];/* uncomment for pre initialized imput = {
								{"Jo-Bob Dylan",1,243},
								{"Jimmy Bean",2,934},
								{"Bobby Singer",3,40},
								{"Anthony Dinozzo",4,90},
								{"Timmothy McGee",5,400},
								{"Jethro Gibbs",6,34},
								{"Rex Bridges",7,1000},
								{"Ant Man",8,69},
								{"Brock Sampson",9,23},
								{"Arduino Mackson",10,99},
								{"Carbuncle Shiva",11,420},
								{"Shacka Laa",12,900}
									};*/
	
	
	for (int count = 0;count < arraySize;count++)
		getPlayerInfo(pInfo[count], count + 1);
	getTotalPoints(pInfo, totalPoints);
	cout << setw(20) << left << "NAME" << setw(10) << left << "NUMBER" << "POINTS SCORED" << endl;
	for (int count = 0; count < 12; count++)
	showInfo(pInfo[count]);
	cout << "TOTAL POINTS: " << totalPoints << endl;
	showHighest(pInfo, arraySize);
	system("pause");



}
void getPlayerInfo(Player &pI,int cnt)
{
	bool temp = false;
	int pn;
	
		cout << "PLAYER #" << cnt << endl;
		cout << "---------" << endl;
		cout << "Player Name: ";
		cin.ignore();
		getline(cin, pI.pName);
		
		do
		{
			cout << "Player's Number: ";
			cin >> pI.pNumber;
			pn = pI.pNumber;
			isNeg(pn,temp);
			
		} while (temp == true);
		do
		{
			cout << "Points Scored: ";
			cin >> pI.pPointsScored;
			pn = pI.pPointsScored;
			isNeg(pn, temp);
		} while (temp == true);
		cout << endl;
}
void showInfo(Player pI)
{
	cout << setw(21) << left << pI.pName << setw(10) << left << pI.pNumber << pI.pPointsScored << endl;
}
int getTotalPoints(const Player pI[], int &tP)
{
	for (int count = 0; count < 12; count++)
		tP = tP + pI[count].pPointsScored;

	return tP;
}
void showHighest(Player pI[], int aS)
{
	int max = 0;
	string loc;

	for (int count = 0; count < 12; count++)
	{
		if (max < pI[count].pPointsScored)
		{
			max = pI[count].pPointsScored;
			loc = pI[count].pName;
		}

	}
	
	cout << "The player who scored the most points is: " << loc << endl;
}
void isNeg(int tempNum,bool &t)
{
	if (tempNum < 0 )
	{
		cout << "Please Enter A Non-Negative Number."<<endl;
		t = true;
		system("pause");
	}
	else
	{
		t = false;
	}
}
