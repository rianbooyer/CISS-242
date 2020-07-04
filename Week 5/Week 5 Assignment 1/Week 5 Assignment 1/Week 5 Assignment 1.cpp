/*	Week 5 Programing Assignment 1 - File Content
Rian Booyer - ciss 242
Version 0.1*/
/*Descripiton - Assignment 1 -File Display Program. Write a program that asks
the user for the name of a file. The program should display the content of 
the file on the screen. If the file’s contents won’t fit on a single screen, 
the program should display 24 lines of the output at a time, and then pause. 
Each time the program pauses, it should wait for the user to strike a key 
before the next 24 lines are displayed.*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
// Global Variables

// Predefine Functions
void programInput(string &fn);
void outputProcessing(string &fn);
void programOutputShort(string fn);
void programOutputLong(string fn);
void main()
{
	string fileName;
	
	programInput(fileName);
	outputProcessing(fileName);
	system("pause");
}
/*programInput - displays initial menu and asks for filename input. filename path is stored in
fileName string by reference*/
void programInput(string &fn)
{
	system("cls");
	cout << char(0xc9) << string(60, char(0xcd)) << char(0xbb) << endl;
	cout << setw(25) << left << char(0xba) << "File Content" << setw(25) << right << char(0xba) << endl;
	cout << char(0xcc) << string(60, char(0xcd)) << char(0xb9) << endl;
	cout << char(0xba) << setw(60) << left << "Displays Content of file specified" << char(0xba) << endl;
	cout << char(0xba) << setw(60) << left << "and if it is too large to fit on screen" << char(0xba) << endl;
	cout << char(0xba) << setw(60) << left << "it displays the file 24 lines at a time" << char(0xba) << endl;
	cout << char(0xba) << setw(60) << left << "" << char(0xba) << endl;
	cout << char(0xba) << setw(60) << left << "" << char(0xba) << endl;
	cout << char(0xc8) << string(60, char(0xcd)) << char(0xbc) << endl;
	cout << "Please specify a filename: ";
	getline(cin, fn);
	system("cls");

}
/*outputProcessing - initially calculates number of lines in the input file and runs different functions
depending on if the number of lines in the file is less or greater than 24*/
void outputProcessing(string &fn)
{
	/*The following lines detect total number of lines in the file and if greater than 24 passes the file name to the
	programOutputLong which steps throug and pauses every 24 lines. if the total lines are less than 24 it passes to
	programOutputShort that just displays the file.*/
	int number_of_lines = 0;
	string line;
	fstream myfile(fn, ios::in);
	while (std::getline(myfile, line))
		++number_of_lines;


	if (number_of_lines>24)
		programOutputLong(fn);
	if (number_of_lines <= 24)
		programOutputShort(fn);

}
/*programOutputShort - just displays the file if the output is less than 24 lines doesn't pause since
it doesn't need to increment*/
void programOutputShort(string fn)
{
	
	fstream inFile(fn, ios::in);
	string input;
	int length;
	if (inFile)
	{
		getline(inFile, input);
		length = input.size();
		while (inFile)
		{
			
			cout << input << endl;
			getline(inFile, input);
			
		}
		inFile.close();
	}
}
/*programOutputLong - This function is like programOutputShort but it counts number of lines that are output
and pauses at every 24 lines for the user to press any key to continue. clears screen after every iteration.*/
void programOutputLong(string fn)
{
	fstream inFile(fn, ios::in);
	string input;
	int count = 0;

	if (inFile)
	{

		
		getline(inFile, input);
		while (inFile)
		{
			do {

				if (!inFile.eof())// loops only while the end of file is not reached
				{
					//cout << (count + 1) << ":" << input << endl;//displays line numbers for confirmation of 24 lines
					cout <<input << endl;//just displays the output
					getline(inFile, input);

				}
				count++;
			} while (count <= 23);

			count = 0;
			system("pause");
			system("cls");
		}
		inFile.close();
	}
}
