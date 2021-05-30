// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 2
// Description: Source file contains functionalities for class Point()
// In the previous exercise, you saw that the point passed to the Distance() method was copied.
//  Since creating a copy is unnecessary in this case,
//      change this function so that it passes the input point “by reference”
//      so that no copy is made.
//      Pass it as “const reference” to make it impossible to change the input point
//      from within the Distance() function.
//  Run the program again.
//  It should call the copy constructor fewer times than before.
//  Also test if you can change the input point in the Distance() function.
//  This should result in a compiler error.

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
double Point::GetX() const
{
	return m_x;
}

// Set new value for x
void Point::SetX(double newX)
{ 
	m_x = newX;
}

// Get y value
double Point::GetY() const
{
	return m_y;
}

// Set new value for y
void Point::SetY(double newY)
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
double Point::DistanceOrigin() const
{
    return sqrt(pow(m_x,2) + pow(m_y,2));
}

// Calculate the distance between two points.
double Point::Distance(const Point& p) const
{
    return sqrt(pow(m_x-p.GetX(),2) + pow(m_y-p.GetY(),2));
}
