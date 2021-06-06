// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 4
// Description: Source file contains functionalities for class Point()
// Normally, only member functions of a class can access the private members of that class.
// Global functions and other classes can’t access the private members of that class.
// You can make an exception on that rule by declaring certain functions or classes as friend.
//
// For example the << operator for sending the point or line to the std::ostream class
//  had to be a global function and thus can’t access the private members.
// Move the << operator of Point and Line inside the class definition and declare it as friend.
// The function remains a global function but it can now access the data members directly
//  without the need for calling the getters or ToString() function.
//
//  Normally, friends are to be avoided because it violates the data hiding principle.
//  But in case of global operator functions it makes sense
//      because you would actually want to make those global operator functions as member function
//      but this was not possible.

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

// Negate the coordinates.
Point Point::operator - () const
{
    return Point(-m_x, -m_y);
}

// Scale the coordinates.
Point Point::operator * (double factor) const
{
    return Point(factor*m_x, factor*m_y);
}

// Add coordinates.
Point Point::operator + (const Point& p) const
{
    return Point(m_x+p.m_x, m_y+p.m_y);
}

// Equally compare operator.
bool Point::operator == (const Point& p) const
{
    if (m_x == p.m_x and m_y == p.m_y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Assignment operator.
Point& Point::operator = (const Point& source)
{
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        m_x = source.m_x;
        m_y = source.m_y;

        return *this;  // Assign the result to itself
    }
}

// Scale the coordinates & assign.
Point& Point::operator *= (double factor)
{
    m_x = factor * m_x;
    m_y = factor * m_y;

    return *this;  // Assign the result to itself
}

// Send to ostream.
ostream& operator << (ostream& os, const Point& p)
{
    os << "Point(" << p.m_x << "," << p.m_y << ")";  // Access private members

    return os;
}