#include <iostream>
#include "DVD.h"
#include <string>
#include <vector>
//using namespace std;
/*The DVD class will have data members for the title 
of the movie, the length of the movie, and the year 
the movie was released. The class will have a vector 
which is used to store the name of the actors and 
actresses in the movie. Another vector will be used 
to maintain the character names that the actor/actress 
played in the movie. These two vectors must work in 
parallel, meaning the first actor/actress in the list 
must correspond to the first character in the other vector.
Movie Title
Length of Movie
Year Released
Actors/Actresses
Characters*/

DVD::DVD()
{
}

DVD::~DVD()
{
	
}

/*accessThesbianVector - returns name of thesbian from this vector*/
std::string DVD::accessThesbianVector(int a) const
{
	return thesbianVector[a];
}

/*accessCharacterVector - returns name of character from the vector*/
std::string DVD::accessCharacterVector(int a) const
{
	return characterVector[a];
}
/*getCharVectorSize - Returns size of the character vector this is used without the thesbian vector check
because both should be the same.*/
int DVD::getCharVectorSize() const
{
	return characterVector.size();
}
/*setVectors - This is used to set the thesbian name and character name in their respective vectors.*/
void DVD::setVectors(int a, std::string b, std::string c)
{
	thesbianVector[a] = b;
	characterVector[a] = c;
}
/*setInfo - Set's the information for a new dvd*/
void DVD::setInfo(std::string a,std::string b, int c)
{
	dvdTitle = a;
	movieLength = b;
	movieYear = c;

}
/*accessTitle - returns name of the dvd movie*/
std::string DVD::accessTitle() const
{
	return dvdTitle;
}
/*accessLength - returns the length of the movie*/
std::string DVD::accessLength() const
{
	return movieLength;
}
/*accessMY - returns the movie year of production*/
int DVD::accessMY() const
{
	return movieYear;
}
/*setVectorSize - sets the vector size for the thesbian vector and the character vector to the
specified size this sets both at the same time to try to keep them the same size.*/
void DVD::setVectorSize(int size)
{
	characterVector.resize(size);
	thesbianVector.resize(size);
}
/*setDvdTitle - stores a passed string to set a new or update a dvd title in the dvd object vector*/
void DVD::setDvdTitle(std::string t)
{	dvdTitle = t; }
/*setMovieLength - stores the movie length into the dvd object vector*/
void DVD::setMovieLength(std::string rt)
{	movieLength = rt;}
/*setMovieYear - sets movie year of production into the dvd object vector*/
void DVD::setMovieYear(int ml)
{	movieYear = ml; }
/*deleteThesbian - delete's the thesbian and their character from related vectors*/
void DVD::deleteThesbian(int a,int b)
{
	characterVector.erase(characterVector.begin() + b);
	thesbianVector.erase(thesbianVector.begin() + b);
}
/*deleteMovie - Delete's a specific movie from the dvd object vector*/
void DVD::deleteMovie(std::vector<DVD>& l, int a)
{
	l.erase(l.begin() + a);
	l.shrink_to_fit();
}
