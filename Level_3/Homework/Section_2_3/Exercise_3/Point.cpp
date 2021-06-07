// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 3
// Description: Source file contains functionalities for class Point()
// Previously you saw that there could be more than one constructor
//  as long as the input arguments are different.
// You can do the same for normal member functions.
// Thus you can rename the DistanceOrigin() function to Distance().
// Also you can rename the SetX() andGetX() functions to just X().
// The same is true for the setter and getter of the y-coordinate.

/*---------------------------------*/
#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing (x,y) = (0,0)
Point::Point() : m_x(0), m_y(0)
{
    cout << "Default point created" << endl;
}

// Initializing (x,y) = (newX,newY)
Point::Point(double newX, double newY): m_x(newX), m_y(newY)
{
    cout << "Point created." << endl;
}

// Copy Constructor: Initializing (x,y) = (newX,newY)
Point::Point(const Point& point): m_x(point.m_x), m_y(point.m_y)
{
    cout << "Copy constructor called." << endl;
}

// Destructor
Point::~Point()
{
	cout << "Point destroyed.\n";
}

// Get x value
double Point::X() const
{
	return m_x;
}

// Set new value for x
void Point::X(double newX)
{ 
	m_x = newX;
}

// Get y value
double Point::Y() const
{
	return m_y;
}

// Set new value for y
void Point::Y(double newY)
{ 
	m_y = newY;
}

// Return string description of the point
string Point::ToString() const
{
    // Declare stringstream objects
    stringstream xSTR, ySTR;

    // Insert inputs to stream
    xSTR << m_x;
    ySTR << m_y;

    return "Point(" + xSTR.str() + "," + ySTR.str() + ")";
}

// Calculate the distance to the origin (0, 0).
double Point::Distance() const
{
    return sqrt(pow(m_x,2) + pow(m_y,2));
}

// Calculate the distance between two points.
double Point::Distance(const Point& p) const
{
    return sqrt(pow(m_x-p.m_x,2) + pow(m_y-p.m_y,2));
}
