// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 2
// Description: Source file contains functionalities for class Line()
// It would be nice if you could send a point or a line directly
//  to the cout object without calling the ToString() method,
//  just as with the primitive types.
// This is possible by adding a << operator function that has on the left an std::ostream
//  and on the right the point or line object.
// Since you can’t add a member function to the std::ostream class,
//  you have to create it as a global function
//  (outside the class definition, but inside the class header file):
//
//  ostream& operator << (ostream& os, const Point& p); // Send to ostream.
// The implementation uses the << operator to send data to the os input argument.
// Since it is a global function, you can’t access the private members of Point.
// To simplify things, you can use the ToString() method of Point to get the string to send to the os argument.
// Also create a similar << operator for printing lines (and circles if you made a circle class).
// Adapt the test program to test the << operator for points and lines.

/*---------------------------------*/
#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing (x,y) = (0,0)
Line::Line() : P1(0,0), P2(0,0)
{
    cout << "Default line created" << endl;
}

// Initializing Line(p1,p2) = Line(Point(newX1, newY1), Point(newX2, newY2))
Line::Line(Point& newP1, Point& newP2): P1(newP1), P2(newP2)
{
    cout << "Line created." << endl;
}

// Copy Constructor: Initializing Line(line) = Line(point1,point2)
Line::Line(const Line& line): P1(line.P1), P2(line.P2)
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
Line& Line::operator = (const Line& source)
{
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        P1 = source.P1;
        P2 = source.P2;

        return *this;
    }
}

// Send to ostream.
ostream& operator << (ostream& os, const Line& l)
{
    os << l.ToString();  // Overloading ToString()

    return os;
}