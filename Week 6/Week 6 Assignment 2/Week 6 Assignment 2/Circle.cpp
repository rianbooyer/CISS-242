#include "Circle.h"
using namespace std;


/*pi is set in the default and secondary constructor*/
Circle::Circle()
{
	pi = 3.14159;
}
Circle::Circle(double r)
{
	pi = 3.14159;
	radius = r;
}
void Circle::setRadius(double r)
{
	radius = r;
}
double Circle::getRadius() const
{
	return radius;
}

Circle::~Circle()
{
}
