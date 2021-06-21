// Type: Homework
// Level: 6
// Section: 4.2a Introduction to Templates
// Exercise: 1
// Description: Source file contains functionalities for class Point()
// In a previous exercise we created an Array class that stores Point objects.
// The disadvantage of this class was that it only stores Point objects.
// If we want to have an array class for Lines,
//  we need to copy the code and replace references to Point to Line.
// This is a lot of work and makes maintenance more difficult.
// A bug in one version has to be fixed in the other versions as well.
// Better is to use the same code for different data types.
// This is possible using templates as shown in Figure 1.
//
// Thus transform the Array class for points created earlier into a template class:
//  •In the header file, declare the Array class as a template of type T.
//  •Replace all references to Point with T.
//  •Where an array is used as input or output, replace Array by Array<T>.
//  •In the source file, every function must be declared as a template of type T.
//  •The functions are now not a member of Array anymore but a member of Array<T>.
//  •Further replace all references to Point with T.
//  •Finally where an array is used as input or output, replace Array by Array<T>.
//  •Don’t forget that the test program should now include the source file instead of the header file.
//  Therefore, the source file should now also include#ifndef/#define/#endif statements.
//
//  In the test program create an array of points and test it:
//      Array<Point> points(size);
//  Tip: by placing the following code at the end of the array header file,
//  but before the header file’s #endif, the client can keep including the header file
//  for template classes instead of the source file. Can you explain how this works?:
//      #ifndef Array_cpp // Must be the same name as in source file #define
//      #include "Array.cpp"
//      #endif



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