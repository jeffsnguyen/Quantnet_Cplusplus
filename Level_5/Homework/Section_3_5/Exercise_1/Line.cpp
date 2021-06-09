// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 1
// Description: Source file contains functionalities for class Shape()
// The ToString() functions of Point and Line override the ToString() from the Shape base class.
// We saw that we could put a Point in a Shape* variable.
// But when calling the ToString() method on the Shape* variable,
//  the function in Shape was called instead the one in Point.
//
//  To make the compiler generate the required code to find out
//      what type of object the Shape*variable is actually pointing to so it can call the right version;
//      we need to declare the function as virtual.
//  Thus declare the ToString() function in the Shape class as virtual
//      and test the program again.
//  Is the ToString() function of Point called when you use a Shape* that contains a Point now?

/*---------------------------------*/
#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing (x,y) = (0,0)
Line::Line() : Shape(), P1(0, 0), P2(0, 0)
{
    cout << "Default line created" << endl;
}

// Initializing Line(p1,p2) = Line(Point(newX1, newY1), Point(newX2, newY2))
Line::Line(Point& newP1, Point& newP2) : Shape(), P1(newP1), P2(newP2)
{
    cout << "Line created." << endl;
}

// Copy Constructor: Initializing Line(line) = Line(point1,point2)
Line::Line(const Line& line) : Shape(), P1(line.P1), P2(line.P2)
{
    cout << "Line Copy constructor called." << endl;
}

// Destructor
Line::~Line()
{
    cout << "Line destroyed.\n";
}

// Get P1 value
Point Line::point1() const
{
    return P1;
}

// Set new value for P1
void Line::point1(const Point& newP1)
{
    P1 = newP1;
}

// Get P2 value
Point Line::point2() const
{
    return P2;
}

// Set new value for P2
void Line::point2(const Point& newP2)
{
    P2 = newP2;
}

// Return string description of the line, overloading from Point class
string Line::ToString() const
{
    return "Line(" + P1.ToString() + "," + P2.ToString() + ")";
}

// Calculate the length of the line
double Line::Length() const
{
    return P1.Distance(P2);
}

// Assignment operator.
Line &Line::operator=(const Line& source)
{
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

        return *this;
    }
}

// Send to ostream.
ostream &operator<<(ostream& os, const Line& l)
{
    os << "Line(" << l.P1 << "," << l.P2 << ")";  // // Access private members

    return os;
}