#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
class Circle
{
	/*had to add extra variables for the calculations*/
private:
	double radius;
	double pi;
	double diameter;
	double area;
	double circumference;
public:
	Circle();
	Circle(double r);
	void setRadius(double r);
	double getRadius() const;
	double getArea()
	{return area = pi * radius * radius;}
	double getDiameter()
	{return diameter = radius * 2;}
	double getCircumference()
	{return circumference = 2 * pi*radius;}

	~Circle();
};
#endif
