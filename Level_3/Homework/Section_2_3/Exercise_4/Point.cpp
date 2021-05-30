// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 4
// Description: Source file contains functionalities for class Point()
// In the test program create a const point and try to set the x-coordinate:
//      const Point cp(1.5, 3.9);
//      cp.X(0.3);
//  Compile the program. Did you get a compiler error?
//  It should give a compiler error because you try to change a const object.
//
//  Now replace the line that changes the x-coordinate to code that reads the x-coordinate:
//      cout<<cp.X()<<endl;
//  Compile the program again.
//  You will see that is still gives a compiler error
//      even while retrieving the x-coordinate does not change the point object.
//  This is because the compiler does not know that the function does not change anything.
//  So we need to mark the x-coordinate getter as const by making it a const function.
//  Do this also for the y-coordinate getter and the Distance() and ToString() functions
//      because these don’t change the point object as well. Recompile the application.
//  It should now work.

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
    return sqrt(pow(m_x-p.X(),2) + pow(m_y-p.Y(),2));
}
