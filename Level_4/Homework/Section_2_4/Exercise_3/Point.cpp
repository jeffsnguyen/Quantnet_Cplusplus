// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 3
// Description: Source file contains functionalities for class Point()
// In this exercise we are going to do a little experiment.
//
// First add to the Point class a constructor that accepts one double as an argument.
// The implementation should set both the x- and y-coordinate to this value.
// Next try the following code in the test program:
//      Point p(1.0, 1.0);
//      if (p==1.0) cout<<"Equal!"<<endl;
//      else cout<<"Not equal"<<endl;
// Will this code compile and can you explain why?
// It turns out that the Point constructor with the single double argument
//  is implicitly used to convert the number in the if statement to a Point object.
// Thus constructors are used as implicit conversion operators.
//
// To prevent the usage of constructors are implicit conversion operators, declare the constructor as explicit:
//      explicit Point(double value);
// Now try to compile the program again and you will see that now the if statement gives a compiler error.
// You can still use the constructor as conversion operator but then explicitly:
//      if (p==(Point)1.0) cout<<"Equal!"<<endl;

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

// Implicit constructor
//Point::Point(double value): m_x(value), m_y(value)
//{
//    cout << "Point created." << endl;
//}

// Explicit constructor
Point::Point(double value): m_x(value), m_y(value)
{
    cout << "Point created." << endl;
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
    os << p.ToString();  // Overloading ToString()

    return os;
}