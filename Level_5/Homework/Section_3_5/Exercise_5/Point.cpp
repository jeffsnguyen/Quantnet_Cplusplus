// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 5
// Description: Source file contains functionalities for class Point()
// In this exercise we are going to create a Print() function
//  that is printing the shape information to the cout object.
// The Print() function can use the ToString() to obtain the string to print.
// You see that the implementation of Print() is in each derived class largely the same;
//  calling ToString() and sending the result to cout.
// Since the ToString() function is polymorphic,
//  we can use the polymorphic behavior in the Print() function of Shape.
// Thus:
//  •Add a Print() function to the Shape class.
//  •In this function, call the ToString() function and send the result to the cout object.
//  •In the test program, create a point and line object and call the Print() function. Does itprint the right information even when point and line do not have the Print() function?
// You have now created a function for the base class (Print())
//  that does all the functionality common to all derived classes.
// Only the part of that function that is different for each derived class
//  is delegated to a polymorphic function (ToString()).
// This mechanism is an often used design pattern called the “Template Method Pattern”.


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