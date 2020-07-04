/*	Week 5 Programing Assignment 2 - Punch Line
Rian Booyer - ciss 242
Version 0.1*/
/*Description - Assignment 2
Punch Line. Write a program that reads and prints a joke and its punch line from two different files (please keep 
it clean). The first file contains a joke, but not its punch line. The second file has the punch line as its last 
line, preceded by “garbage text” (does not matter what it is). Note: the last sentence (punch line) will have a newline 
character before it. The program is to search for the start of the last sentence; it should NOT move backward from the 
file a fixed number of characters. It should work for any punch line file. The main function of your program should open 
the two files and then call two functions, passing each one the file it needs. The first function should read and display each 
line in the file it is passed (the joke file). The second function should display only the last line of the file it is 
passed (the punch line file). IT should find this line by seeking to the end of the file and then backing up to the beginning of the 
last line. Data to test your program can be found in the joke.txt and punchline.text files provided at the textbook web site.*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Global Variables

// Predefine Functions
void displayJoke(ifstream &infile); //Display joke
void displayPunchline(ifstream &infile); //Display punchline
void main()
{
	ifstream jokeFile("joke.txt"), punchLine("punchline.txt");

	displayJoke(jokeFile);
	displayPunchline(punchLine);
	system("pause");
}

/*displayJoke - steps through the first file and outputs contents*/
void displayJoke(ifstream &infile)
{
	string line;
	while (getline(infile, line))
	{
		cout << line << endl;
	}
	infile.close();
}

/*displayPunchline - jumps to 1 character before EOF then steps backwards till newline is detected then grabs the
last line and outputs it. additional help came from the wonderfull folks at stackoverflow.com*/
void displayPunchline(ifstream &infile)
{/*instructions - The second function should display only the last line of the file it is 
passed (the punch line file). IT should find this line by seeking to the end of the file and then backing up to the beginning of the 
last line.*/
	string line;
	bool punchLoop = true;
	infile.seekg(-1,ios::end);//sets read position at 1 character before EOF
		
	while (punchLoop) {
		char ch;
		infile.get(ch);                            

		if ((int)infile.tellg() <= 1) {             
			infile.seekg(0);                      
			punchLoop = false;                
		}
		else if (ch == '\n') {                   
			punchLoop = false;                
		}
		else {                                 
			infile.seekg(-2, ios_base::cur); //steps backwards  
		}
	}
	getline(infile, line);
	cout << line << endl;
	infile.close();
	
}