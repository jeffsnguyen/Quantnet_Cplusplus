// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 1
// Description: Source file contains functionalities for class Point()
// In this exercise we are going to add extra constructors.
//  But first we do a little experiment.
//      In the Point class constructor and destructor, add some code that displays some text.
//      In the main program, make sure you use the Distance() function to calculate
//          the distance between two points. Run the program
//          and count how many times the constructor and destructor are called.
//  Are they the same?
//
//  Now add a copy constructor to the Point class that also displays some text.
//      Also add a constructor that accepts x- and y-coordinates so you
//          can create a point with the right values without using the set functions.
//      Use this constructor to create the point from the user input.
//      Run the program again and count the number of times the constructors and destructor are called.
//  Is the copy constructor called and is the number of constructor calls now the same
//      as the number of destructor calls?
//  We can derive two things from these results:
//      1. When calling the Distance() function, the input point is copied (call by value).
//      2. You will get the copy constructor 'for free' when you do not create one yourself.

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
double Point::Distance(Point p) const
{
    return sqrt(pow(m_x-p.GetX(),2) + pow(m_y-p.GetY(),2));
}
