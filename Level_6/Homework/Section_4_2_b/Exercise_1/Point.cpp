// Type: Homework
// Level: 6
// Section: 4.2a Advanced Templates
// Exercise: 1
// Description: Source file contains functionalities for class Point()
// Static variables, which are shared between all instances of a class,
//  behave slightly different with templates.
// We are going to test this with a static variable in the Array class
//  that indicates the default array size when using the default constructor.
//  •Add a static data member to the Array class indicating the default size.
//  •Initialise this static in the source file to a value.
//  •Also add static functions to set and get the default size.
//  •In the default constructor, use the static default size variable instead of a literal valueto set the array size.
// Test the following code in the main program:
//  Array<int> intArray1;
//  Array<int> intArray2;
//  Array<double> doubleArray;
//
//  cout<<intArray1.DefaultSize()<<endl;
//  cout<<intArray2.DefaultSize()<<endl;
//  cout<<doubleArray.DefaultSize()<<endl;
//
//  intArray1.DefaultSize(15);
//
//  cout<<intArray1.DefaultSize()<<endl;
//  cout<<intArray2.DefaultSize()<<endl;
//  cout<<doubleArray.DefaultSize()<<endl;
//
// What values are printed? Can you explain the result?


/*---------------------------------*/
#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing (x,y) = (0,0)
Point::Point() : Shape(), m_x(0), m_y(0)
{
    cout << "Default point created" << endl;
}

// Initializing (x,y) = (newX,newY)
Point::Point(double newX, double newY) : Shape(), m_x(newX), m_y(newY)
{
    cout << "Point created." << endl;
}

// Copy Constructor: Initializing (x,y) = (newX,newY)
Point::Point(const Point &point) : Shape(), m_x(point.m_x), m_y(point.m_y)
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

    string s=Shape::ToString();

    return s + ": " + "Point(" + xSTR.str() + "," + ySTR.str() + ")";
}

// Calculate the distance to the origin (0, 0).
double Point::Distance() const
{
    return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

// Calculate the distance between two points.
double Point::Distance(const Point &p) const
{
    return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}

// Overidden function from Shape() simulating drawing by printing some text
void Point::Draw() const
{
    cout << "Simulating point drawing." << endl;
}


// Negate the coordinates.
Point Point::operator-() const
{
    return Point(-m_x, -m_y);
}

// Scale the coordinates.
Point Point::operator*(double factor) const
{
    return Point(factor * m_x, factor * m_y);
}

// Add coordinates.
Point Point::operator+(const Point &p) const {
    return Point(m_x + p.m_x, m_y + p.m_y);
}

// Equally compare operator.
bool Point::operator==(const Point &p) const
{
    if (m_x == p.m_x and m_y == p.m_y)
    {
        return true;
    } else
    {
        return false;
    }
}

// Assignment operator.
Point& Point::operator = (const Point& source)
{
    cout << "Assignment operator" << endl;
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }

    {
        // Call base class assignment
        Shape::operator= (source);

        m_x = source.m_x;
        m_y = source.m_y;

        return *this;  // Assign the result to itself
    }
}

// Scale the coordinates & assign.
Point &Point::operator*=(double factor)
{
    m_x = factor * m_x;
    m_y = factor * m_y;

    return *this;  // Assign the result to itself
}

// Send to ostream.
ostream &operator<<(ostream &os, const Point &p)
{
    os << "Point(" << p.m_x << "," << p.m_y << ")";  // Access private members

    return os;
}