// Type: Homework
// Level: 5
// Section: 3.4 Simple Inheritance
// Exercise: 2
// Description: Source file contains functionalities for class Point()
// It can be useful to create a hierarchy of related classes using base- and derived classes.
//  •Classes are related (same family)
//  •Common data and functionality can be put in a base class.
//  •You can work with derived classes as if it is the base class.
// In this exercise we are going to transform the Point and Line class into a Shape hierarchy as shown in Figure 1.
// First create a Shape base class.
//  •Add a source- and header file for a Shape class.
//  •Add a data member for an id number of type int.
//  •Add a default constructor that initializes the id using a random number.
//      You can usethe rand() function from the “stdlib.h” header file.
//  •Add a copy constructor that copies the id member.
//  •Add an assignment operator that copies the id member.
//  •Add a ToString() function that returns the id as string e.g. “ID: 123”.
//  •Add an ID() function the retrieve the id of the shape.
// Next the Point and Line classes (and the Circle class if applicable) must derive from Shape.
//  •Add the Shape class in the inheritance list of the Point, Line and optionallythe Circle class.
//  •The constructors of the Point, Line and optionally the Circle class
//      should call theappropriate constructor in the Shapebase class.
//  •The assignment operator should call the assignment operator of the Shape baseclass.
//      Otherwise the shape data will not be copied.
//  •Finally add code to the main program to test inheritance:
//      Shape s;// Create shape.
//      Point p(10, 20);// Create point.
//      Line l(Point(1,2), Point(3, 4)); // Create line.
//
//      cout<<s.ToString()<<endl;// Print shape.
//      cout<<p.ToString()<<endl;// Print point.
//      cout<<l.ToString()<<endl;// Print line
//
//      cout<<"Shape ID: "<<s.ID()<<endl; // ID of the shape.
//      cout<<"Point ID: "<<p.ID()<<endl; // ID of the point. Does this work?
//      cout<<"Line ID: "<<l.ID()<<endl; // ID of the line. Does this work?
//
//      Shape* sp; // Create pointer to a shape variable.
//      sp=&p; // Point in a shape variable. Possible?
//      cout<<sp->ToString()<<endl;// What is printed?
//
//      //Create and copy Point p to new point.
//      Point p2;
//      p2=p;
//      cout<<p2<<", "<<p2.ID()<<endl; // Is the ID copied if you do not call
//      //the base class assignment in point?
//      Answer the questions in the comments of the code above.

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
Point::Point(double newX, double newY) : m_x(newX), m_y(newY)
{
    cout << "Point created." << endl;
}

// Copy Constructor: Initializing (x,y) = (newX,newY)
Point::Point(const Point &point) : m_x(point.m_x), m_y(point.m_y)
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
    return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

// Calculate the distance between two points.
double Point::Distance(const Point &p) const
{
    return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
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