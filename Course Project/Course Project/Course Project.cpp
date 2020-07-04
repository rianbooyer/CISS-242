#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include "DVD.h"
using namespace std;
/*This program will allow the user to keep track 
of a CD or DVD collection. This can only work 
exclusively with either CDs or DVDs since some of 
the data is different—your choice. Each CD/DVD in 
the collection will be represented as a class, so 
you will have one class that is a single CD/DVD.*/
/*For the DVDs:

Movie Title
Length of Movie
Year Released
Actors/Actresses
Characters
Note: the movie title, length of movie and year 
released should only appear once while the actors/actresses
and characters will have several lines. So the other 
columns must be displayed with blanks.*/

//global variables

//predefine functions
void mainMenu(vector<DVD>& l, bool &ml);
//void dvdList(vector<DVD>& l, bool &ml);
void populate(vector<DVD>& l);
void editMovie(vector<DVD>& l, int a);
void movieOutput(vector<DVD>& l,int a);
void main()
{
	
	bool menuLoop = true;
	vector<DVD> list;
	
	populate(list); // populates DVD object vector and subvectors thesbianVector and characterVector
	
	do
	{
		
		mainMenu(list, menuLoop);
	} while (menuLoop == true);
	
	system("pause");
	
	
}

void mainMenu(vector<DVD>& l,bool &ml)
{
	/* outline
	displays title and main menu

	displays a list of movies in for loop

	options
	*D or d - display movie
	|-asks which movie to display then once selected displays an output of the movie
	*E or e - Edit Movie - display movie with numbers next to the characters to edit.
	| A or a - Add Character(s) to movie
	|- Prompt for number of actors/characters to enter.
	|- check thesbianVector and characterVector for size if they have insufficient size resize and continue
	|- start loop based on number of characters
	|- Prompt for actor name and store in variable
	|- Prompt for Character Name and store in variable
	|- store in respective vector values
	| C or c- Edit Character including actor
	|- input character or actor number
	|- prompt for actor name
	|- input name to string
	|- prompt for character name
	|- input name to string
	|- store actor name, character name, using setVectors(int number, "Actor Name", "Character Name")
	|- Return to previous menu
	|-D - Delete Movie
	|- delete movie using deleteMovie function
	|- return
	| N or n - Edit movieName
	|- prompt for new movie name
	|- store movie name into dvd object vector
	| R or r- Edit RunTime
	|- Prompt for new runtime in format of #h #min and put it into a string
	|- Store string into object array using list[#].setMovieLength(var)
	|- return
	| T or t- Edit Title
	|- Prompt for new title
	|- store string into object array using list[#].setMovieTitle(var)
	|- return
	| Q or q - return to previous menu
	*A or a - Add Movie
	|- detect dvd object array size and adds one to the array
	|- prompt for name of movie store in variable as string
	|- Prompt for run time in #h #min store in variable as string
	|- Prompt for year of production and store in variable as int
	|- Store in DVD object array using l[#].setInfo(MovieTitleVar, RunTimeVar, YearVar)
	*Q or q - quit program

	*/
	int vectorSize = l.size();
	int movieNum;
	char menuItem;
	system("cls");
	cout << char(0xda) << string(58, char(0xc4)) << char(0xbf) << endl;
	cout << char(0xb3) << setw(23) << left << "" << "DVD Collection" << setw(22) << right << char(0xb3) << endl;
	cout << char(0xc3) << string(58, char(0xc4)) << char(0xb4) << endl;
	cout << char(0xb3) << setw(23) << left << "" << "Main Menu" << setw(27) << right << char(0xb3) << endl;
	for (int count = 0; count < vectorSize; count++)
	{
		cout << char(0xb3) << count + 1 << "." << setw(20) << left << l[count].accessTitle() << setw(37) << right << char(0xb3) << endl;

	}
	cout << char(0xc0) << string(58, char(0xc4)) << char(0xd9) << endl;
	cout << " A. Add Movie, D. Display Movie Info, E. Edit Movie" << endl;
	cout << "Please enter a choice or q to quit: ";
	cin >> menuItem;

	if (toupper(menuItem) == 'A')
	{
		string movieName, movieLength;
		int movieYear;
		char addMovieYN;

		cout << "Enter Movie Title: ";
		cin.ignore();
		getline(cin, movieName);
		cout << "Enter Movie Length (#h #min): ";
		getline(cin, movieLength);
		cout << "Enter the year of production: ";
		cin >> movieYear;
		cout << "Are you sure you wish to add this movie y/n? ";
		cin >> addMovieYN;
		if (toupper(addMovieYN) == 'Y')
		{
			l.resize(vectorSize + 1);
			l[vectorSize].setInfo(movieName, movieLength, movieYear);
		}

	}
	if (toupper(menuItem) == 'D')
	{
		int movieNum;
		cout << "Which movie would you like to display (1 -" << vectorSize << "): ";
		cin >> movieNum;
		movieOutput(l, movieNum - 1);
	}
	if (toupper(menuItem) == 'E')
	{
		cout << "Which movie number would you like to Edit? ";
		cin >> movieNum;
		editMovie(l, movieNum - 1);
	}
	if (toupper(menuItem) == 'Q')
		ml = false;
	
	
		
}
/*void dvdList(vector<DVD>& l, bool &ml)
{
	/*
	displays title and main menu

	displays a list of movies in for loop

	options
	*D or d - display movie
		|-asks which movie to display then once selected displays an output of the movie
	*E or e - Edit Movie - display movie with numbers next to the characters to edit.
		| A or a - Add Character(s) to movie
			|- Prompt for number of actors/characters to enter.
			|- check thesbianVector and characterVector for size if they have insufficient size resize and continue
			|- start loop based on number of characters
			|- Prompt for actor name and store in variable
			|- Prompt for Character Name and store in variable
			|- store in respective vector values
		| C or c- Edit Character including actor
			|- input character or actor number
				|- prompt for actor name
					|- input name to string
				|- prompt for character name
					|- input name to string
				|- store actor name, character name, using setVectors(int number, "Actor Name", "Character Name")
				|- Return to previous menu
		|-D - Delete Movie
			|- delete movie using deleteMovie function
			|- return
		| N or n - Edit movieName
			|- prompt for new movie name
			|- store movie name into dvd object vector
		| R or r- Edit RunTime
			|- Prompt for new runtime in format of #h #min and put it into a string
			|- Store string into object array using list[#].setMovieLength(var)
			|- return
		| T or t- Edit Title
			|- Prompt for new title
			|- store string into object array using list[#].setMovieTitle(var)
			|- return
		| Q or q - return to previous menu
	*A or a - Add Movie
		|- detect dvd object array size and adds one to the array
		|- prompt for name of movie store in variable as string
		|- Prompt for run time in #h #min store in variable as string
		|- Prompt for year of production and store in variable as int
		|- Store in DVD object array using l[#].setInfo(MovieTitleVar, RunTimeVar, YearVar)
	*Q or q - quit program
	
	
	int vectorSize = l.size();
	int movieNum;
	char menuItem;
	system("cls");
	cout << char(0xda) << string(58, char(0xc4)) << char(0xbf) << endl;
	cout << char(0xb3) << setw(23) << left << "" << "DVD Collection" << setw(22) << right << char(0xb3) << endl;
	cout << char(0xc3) << string(58, char(0xc4)) << char(0xb4) << endl;
	cout << char(0xb3) << setw(23) << left << "" << "Main Menu" << setw(27) << right << char(0xb3) << endl;
	for (int count = 0; count < vectorSize; count++)
	{
		cout << char(0xb3) << count + 1 << "." << setw(20) << left << l[count].accessTitle() << setw(37) << right << char(0xb3) << endl;

	}
	cout << char(0xc0) << string(58, char(0xc4)) << char(0xd9) << endl;
	cout << " A. Add Movie, D. Display Movie Info, E. Edit Movie" << endl;
	cout << "Please enter a choice or q to quit: ";
	cin >> menuItem;
	
	if (toupper(menuItem)== 'A')
	{
		string movieName, movieLength;
		int movieYear;
		char addMovieYN;

		cout << "Enter Movie Title: ";
		cin.ignore();
		getline(cin, movieName);
		cout << "Enter Movie Length (#h #min): ";
		getline(cin, movieLength);
		cout << "Enter the year of production: ";
		cin >> movieYear;
		cout << "Are you sure you wish to add this movie y/n? ";
		cin >> addMovieYN;
		if (toupper(addMovieYN) == 'Y')
		{
			l.resize(vectorSize + 1);
			l[vectorSize].setInfo(movieName, movieLength, movieYear);
		}

	}
	if (toupper(menuItem)== 'D')
	{ 
		int movieNum;
		cout << "Which movie would you like to display (1 -" << vectorSize << "): ";
		cin >> movieNum;
		movieOutput(l, movieNum - 1);
	}
	if (toupper(menuItem)== 'E')
	{
		cout << "Which movie number would you like to Edit? ";
		cin >> movieNum;
		editMovie(l, movieNum-1);
	}
	if (toupper(menuItem) == 'Q')
		ml = false;
}*/

/*populate - This function populates the DVD object vector with 5 movies and their actors and characters.
This gives at least some functionality if needed. If an empty program is needed the call can be removed from main.*/
void populate(vector<DVD>& l)
{
	l.resize(5);
	
	l[1].setInfo("Star Trek Beyond", "2h 2min", 2016);
	l[1].setVectorSize(10);
	l[1].setVectors(0, "Chris Pine","Captain James T. Kirk");
	l[1].setVectors(1, "Zachary Quinto", "Commander Spock");
	l[1].setVectors(2, "Karl Urban", "Doctor 'Bones' McCoy");
	l[1].setVectors(3, "Zoe Saldana", "Lieutenant Uhura");
	l[1].setVectors(4, "Simon Pegg", "Montgomery 'Scotty' Scott");
	l[1].setVectors(5, "John Cho", "Sulu");
	l[1].setVectors(6, "Anton Yelchin", "Chekov");
	l[1].setVectors(7, "Idris Elba", "Krall");
	l[1].setVectors(8, "Joe Taslim", "Manas");
	l[1].setVectors(9, "Lydia Wilson", "Kalara");
	
	l[2].setInfo("Schindler's List", "3h 15min", 1993);
	l[2].setVectorSize(10);
	l[2].setVectors(0, "Liam Neeson", "Oskar Schindler");
	l[2].setVectors(1, "Ben Kingsley", "Itzhak Stern");
	l[2].setVectors(2, "Ralph Fiennes", "Amon Goeth");
	l[2].setVectors(3, "Caroline Goodall", "Emilie Schindler");
	l[2].setVectors(4, "Jonathan Sagall", "Poldek Pfefferberg");
	l[2].setVectors(5, "Embeth Davidtz", "Helen Hirsch");
	l[2].setVectors(6, "Mark Ivanir", "Marcel Goldberg");
	l[2].setVectors(7, "Andrzej Seweryn", "Julian Scherner");
	l[2].setVectors(8, "Friedrich Von Thun", "Rolf Czurda");
	l[2].setVectors(9, "Krzysztof Luft", "Herman Toffel");

	l[3].setInfo("Spaceballs", "1h 36min", 1987);
	l[3].setVectorSize(4);
	l[3].setVectors(0, "Mel Brooks", "President Skroob / Yogurt");
	l[3].setVectors(1, "John Candy", "Barf");
	l[3].setVectors(2, "Rick Moranis", "Dark Helmet");
	l[3].setVectors(3, "Bill Pullman", "Lone Starr");

	l[4].setInfo("Monkeybone", "1h 33min", 2001);
	l[4].setVectorSize(6);
	l[4].setVectors(0, "Brendan Fraser", "Stu Miley");
	l[4].setVectors(1, "Bridget Fonda", "Dr. Julie McElroy");
	l[4].setVectors(2, "John Turturro", "Monkeybone (voice)");
	l[4].setVectors(3, "Chris Kattan", "Organ Donor Stu");
	l[4].setVectors(4, "Giancarlo Esposito", "Hypnos");
	l[4].setVectors(5, "Rose McGowan", "Miss Kitty");

	l[0].setInfo("Pacific Rim", "2h 11min", 2013);
	l[0].setVectorSize(13);
	l[0].setVectors(0, "Charlie Hunnam", "Raleigh Becket");
	l[0].setVectors(1, "Diego Klattenhoff", "Yancy Becket");
	l[0].setVectors(2, "Idris Elba", "Stacker Pentecost");
	l[0].setVectors(3, "Rinko Kikuchi", "Mako Mori");
	l[0].setVectors(4, "Charlie Day", "Dr. Newton Geiszler");
	l[0].setVectors(5, "Burn Gorman", "Gottieb");
	l[0].setVectors(6, "Max Martini", "Herc Hansen");
	l[0].setVectors(7, "Robert Kazinsky", "Chuck Hansen");
	l[0].setVectors(8, "Clifton Collins Jr.", "Ops Tendo Choi");
	l[0].setVectors(9, "Ron Perlman", "Hannibal Chau");
	l[0].setVectors(10, "Brad William Henke", "Construction Foreman");
	l[0].setVectors(11, "Larry Joe Campbell", "Construction Worker");
	l[0].setVectors(12, "Mana Ashida", "Young Mako");

}

/*editMovie - This function displays the dvd info just like the movieOutput function and allows the user
to edit different aspects of the movie. Users can add a multiple of characters, remove a character,
edit actor/actress and their character by selecting the number next to the actor/actress in the display,
delete the movie object from the dvd list vector, edit movie name, runtime and year.*/
void editMovie(vector<DVD>& l, int a)
{
	bool editMovieBool = true;
	do
	{
		int vectorSize;
		vectorSize = l[a].getCharVectorSize();
		char menuItem;
		system("cls");
		cout << char(0xda) << string(61, char(0xc4)) << char(0xbf) << endl;
		cout << char(0xb3) << setw(14) << left << "Movie Title: " << setw(47) << left << l[a].accessTitle() << char(0xb3) << endl;
		cout << char(0xb3) << setw(14) << left << "Movie Length: " << setw(47) << left << l[a].accessLength() << char(0xb3) << endl;
		cout << char(0xb3) << setw(14) << left << "Movie Year: " << setw(47) << left << l[a].accessMY() << char(0xb3) << endl;
		cout << char(0xc3) << string(30, char(0xc4)) << char(0xc2) << string(30, char(0xc4)) << char(0xb4) << endl;

		cout << char(0xb3) << setw(30) << left << "      Actor" << char(0xb3) << "      Character" << setw(16) << right << char(0xb3) << endl;
		cout << char(0xc6) << string(30, char(0xcd)) << char(0xd8) << string(30, char(0xcd)) << char(0xb5) << endl;
		for (int count = 0; count < vectorSize; count++)
		{
			cout << char(0xb3) << setw(2) << left << count << ". " << setw(26) << left << fixed << l[a].accessThesbianVector(count) << char(0xb3) << setw(30) << left << l[a].accessCharacterVector(count) << char(0xb3) << endl;
		}
		cout << char(0xc0) << string(30, char(0xc4)) << char(0xc1) << string(30, char(0xc4)) << char(0xd9) << endl;
		cout << "A. Add/Remove Actor/Character(s), C. Edit Actor/Character, " << endl;
		cout << "D. Delete Movie, N. Edit movie name, R. Edit movie runtime" << endl;
		cout << "Y. Edit Movie Year" << endl;
		cout << "Please enter a selection or q to quit: ";
		cin >> menuItem;

		if (toupper(menuItem) == 'A')//add actors/characters
		{
			int thesbianNumber;
			string actorName, charName;
			char choiceAR;

			cout << "Do you wish to (A)dd or (R)emove an actor and character: ";
			cin >> choiceAR;
			if (toupper(choiceAR) == 'A')
			{
				int vs, vs2, numAdd;
				string actorName, charName;

				vs = l[a].getCharVectorSize();
				
				cout << "How many actors/characters do you wish to add: ";
				cin >> numAdd;
				l[a].setVectorSize(l[a].getCharVectorSize() + numAdd);
				vs2 = l[a].getCharVectorSize();
				
				cin.ignore();
				for (int count = vs; count < vs2; count++)
				{
					
					cout << "Please enter actor/actress name: ";
					getline(cin, actorName);
					//cin.ignore();
					cout << "Please enter the character name: ";
					getline(cin, charName);
					l[a].setVectors(count, actorName, charName);
					cout << endl;
				}
			}
			if (toupper(choiceAR) == 'R')
			{
				cout << "Enter the actor/character number you wish to remove: ";
				cin >> thesbianNumber;
				l[a].deleteThesbian(a, thesbianNumber);

			}
		}
		if (toupper(menuItem) == 'C')//edit actor/character
		{
			int thesbianNumber;
			string actorName, charName;
			char changeYN;
			//cin.ignore();
			cout << "Please enter actor/character number: ";
			cin >> thesbianNumber;
			cin.ignore();
			cout << "Please enter actor name: ";
			getline(cin, actorName);
			cin.ignore();
			cout << "Please enter Character Name: ";
			getline(cin, charName);
			cout << "Are you sure you wish to change the actor/character y/n: ";
			cin >> changeYN;
			if (toupper(changeYN) == 'Y')
				l[a].setVectors(thesbianNumber, actorName, charName);

		}
		if (toupper(menuItem) == 'D')//delete movie
		{
			char deleteChoice;
			cout << "Are you sure you wish to delete " << l[a].accessTitle() << " y/n: ";
			cin >> deleteChoice;

			if (toupper(deleteChoice) == 'Y')
			{
				int pos;
				pos = a;
				l[a].deleteMovie(l, pos);

			}
		}
		if (toupper(menuItem) == 'N')//edit movie name
		{
			string movieName;
			char movieNameYN;
			cin.ignore();
			cout << "Please enter a new/updated name: ";
			getline(cin, movieName);
			cout << "Are you sure you wish to alter the name y/n: ";
			cin >> movieNameYN;
			if (toupper(movieNameYN) == 'Y')
			{
				l[a].setDvdTitle(movieName);

			}
		}
		if (toupper(menuItem) == 'R')//edit movie runtime
		{
			string movieRunTime;
			char movieRunTimeYN;
			cin.ignore();
			cout << "Please enter the movie runtime in #h #min format: ";
			getline(cin, movieRunTime);
			cout << "Are you sure you wish to change the runtime y/n: ";
			cin >> movieRunTimeYN;
			if (toupper(movieRunTimeYN) == 'Y')
				l[a].setMovieLength(movieRunTime);
		}
		if (toupper(menuItem) == 'Y')
		{
			int movieYear;
			cout << "Please enter the year the movie was produced: ";
			cin >> movieYear;
			l[a].setMovieYear(movieYear);
}
		if (toupper(menuItem) == 'Q')//return to previous menu
		{
			editMovieBool = false;
		}
	}while (editMovieBool == true);
	system("pause");
}
/*movieOutput - Displays the information about the movie including Title, Run Time, Year of production and the 
actors/actresses and their corresponding characters in the movie*/
void movieOutput(vector<DVD>& l, int a)
{
	int vectorSize;
	vectorSize = l[a].getCharVectorSize();
	system("cls");
	cout << char(0xda) << string(61, char(0xc4)) << char(0xbf)<< endl;
	cout << char(0xb3) << setw(14) << left <<"Movie Title: " << setw(47) << left << l[a].accessTitle() << char(0xb3)<< endl;
	cout << char(0xb3) << setw(14) << left <<"Movie Length: " << setw(47) << left << l[a].accessLength() << char(0xb3)<< endl;
	cout << char(0xb3) << setw(14) << left <<"Movie Year: " << setw(47) << left << l[a].accessMY() << char(0xb3) <<endl;
	cout << char(0xc3) << string(30, char(0xc4)) << char(0xc2) << string(30,char(0xc4)) << char(0xb4) << endl;
	
	cout << char(0xb3) << setw(30) << left << "      Actor" << char(0xb3) << "      Character" <<setw(16)<<right<<char(0xb3)<< endl;
	cout << char(0xc6) << string(30, char(0xcd)) << char(0xd8) << string(30, char(0xcd)) << char(0xb5) << endl;
	for (int count = 0; count < vectorSize; count++)
	{
		cout << char(0xb3) << setw(30) << left << l[a].accessThesbianVector(count) << char(0xb3) <<setw(30)<<left<< l[a].accessCharacterVector(count) << char(0xb3)<< endl;
	}
	cout << char(0xc0) << string(30, char(0xc4)) << char(0xc1) << string(30,char(0xc4))<<char(0xd9) << endl;
	system("pause");
}