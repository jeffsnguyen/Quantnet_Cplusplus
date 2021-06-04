// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 1
// Description: Source file contains functionalities for class Line()
// By supporting operators, you can make your classes easier and more natural to use.
// However you must not “overuse” operators. Only use operators
//  if the functionality of the operator is clear without reading documentation.
// Thus adding mathematical operators to a complex number class is good
//  but using a + operator with a double as an argument on a point
//  to increase the x-coordinate is questionable. So use operators with care.
// In this exercise we add a few operators to the Point class.
// Most operators do not change the original objects but return the result as a new object.
// Normally only the = operator and += and variants change the original object. Add the following operators:
//
//  Point operator - () const; // Negate the coordinates.
//  Point operator * (double factor) const; // Scale the coordinates.
//  Point operator + (const Point& p) const; // Add coordinates.
//  bool operator == (const Point& p) const; // Equally compare operator.
//  Point& operator = (const Point& source); // Assignment operator.
//  Point& operator *= (double factor); // Scale the coordinates & assign.
//  Most operators above are self-explanatory.
//  The = and *= operator changes the current object so they can’t be const functions.
//  To make it possible to chain the = and *= operators (E.g.: a=b+=c),
//      it must return the “this” object.
//  Change the main program to test the operators.
//  Since the assignment operator is part of the canonical header file,
//      add this operator also to the Line and, if applicable, theCircle class.
//  Always be sure to preclude self-assignment inside your assignment operator functions.

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
