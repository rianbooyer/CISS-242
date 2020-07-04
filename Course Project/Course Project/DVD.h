
#ifndef DVD_H
#define DVD_H
#include <string>
#include <vector>
//using namespace std;
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
class DVD
{
	private:
		std::string dvdTitle;
		std::string movieLength;
		int movieYear;
		std::string thesbians;
		std::string characters;
		std::vector<std::string> thesbianVector;
		std::vector<std::string> characterVector;

public:
	DVD();
	~DVD();
	
	std::string DVD::accessThesbianVector(int a) const;
	
	std::string accessCharacterVector(int a) const;
	int getCharVectorSize() const;
	
	std::string accessTitle() const;
	std::string DVD::accessLength() const;
	int DVD::accessMY() const;
		
	void setVectorSize(int size);
	void setVectors(int a, std::string b, std::string c);
	void setInfo(std::string a,std::string b, int c);
	
	void setDvdTitle(std::string t);
	void setMovieLength(std::string rt);
	void setMovieYear(int ml);
	
	void deleteThesbian(int a,int b);
	void deleteMovie(std::vector<DVD>& l, int a);

};

#endif
