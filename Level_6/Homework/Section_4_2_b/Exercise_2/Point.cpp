// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 2
// Description: Source file contains functionalities for class Point()
// With templates it is possible to call functionality on the template argument.
// But when you do this, you limit the types you can use as the template argument
//  because they have to support that functionality.
// Thus when adding numeric functionality to the Array class like calculating the sum,
//  you would limit the types possible as the template argument to types that support numeric operations.
//  It is better to leave the Array class as generic as possible so it can be used in various situations.
//  Numeric functionality can then be put in a derived class
//      which itself is also a template (generic inheritance) as shown in Figure 2.
// In this exercise we are going to create a NumericArray derived from Array.
//  •Add a new source- and header file for a NumericArray class to your project.
//  •Create a template class called NumericArray and derive it from the Array class using generic inheritance.
//  •Since they are not inherited, create proper constructors, destructor and
//      assignment operator and call the base class where appropriate.
//  •Add the following numeric functionality:
//      o An operator * to scale the elements of the numeric array by a factor.
//      o An operator + to add the elements of two numeric arrays.
//          Throw an exception if the two arrays have not the same size.
//      o A function to calculate the dot product. The dot product is defined as:
// Change the main program to test the numeric array.
// What assumptions do you make about the type used as template argument?
// Can you create a numeric array with Point objects?


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
Point &Point::operator=(const Point &source) {
    cout << "Assignment operator" << endl;
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        // Call base class assignment
        Shape::operator= (source);

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