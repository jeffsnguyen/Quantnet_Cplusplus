// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 2
// Description: Source file contains functionalities for class Point()
// Until now, we created objects on the stack.
// The stack is limited in size thus when creating many objects,
//  the stack will overflow.
// Also arrays created on the stack can only have a fixed size determined at compile time.
//
// To overcome these problems we have to create objects on the heap using new.
// In the main program, create Point objects on the heap with new using the default constructor,
//  constructor with coordinates and the copy constructor
//  and assign it to pointer (Point*) variables.
// Note that you can’t directly pass a pointer variable as argument to the copy constructor.
// The pointer must first be dereferenced when passing it to the copy constructor.
//  (Point* p2=new Point(*p1)).
// Next call the Distance() function on the pointers and try to send the Point pointers to cout.
// You need to dereference the pointer when passing it as argument.
// Don’t forget to delete the object created with new.
// Test the main program.
//
// Next, we will create an array of points.
// First ask the user for the size of the array and read it using cin.
// Then try to create an array on the stack using the entered size.
// You will see a compiler error.
// Arrays on the stack must have the size set at compile time.
// Now create the array on the heap using new.
// Can you use other constructors than the default constructor for the objects created in the array?
// Don’t forget to delete the array after use.
// Don’t forget the square brackets when deleting arrays!
//
// Some C++ compilers (e.g. GCC) support variable length arrays (VLA)
//  where the size can be determined at run-time.
// However this is a C99 feature that is not in the C++ standard.
// Because VLA is not in the C++ standard you should avoid its usage since it will lead to less portable code.

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