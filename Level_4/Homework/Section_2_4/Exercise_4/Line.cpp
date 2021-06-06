// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 4
// Description: Source file contains functionalities for class Line()
// Normally, only member functions of a class can access the private members of that class.
// Global functions and other classes can’t access the private members of that class.
// You can make an exception on that rule by declaring certain functions or classes as friend.
//
// For example the << operator for sending the point or line to the std::ostream class
//  had to be a global function and thus can’t access the private members.
// Move the << operator of Point and Line inside the class definition and declare it as friend.
// The function remains a global function but it can now access the data members directly
//  without the need for calling the getters or ToString() function.
//
//  Normally, friends are to be avoided because it violates the data hiding principle.
//  But in case of global operator functions it makes sense
//      because you would actually want to make those global operator functions as member function
//      but this was not possible.

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
    os << "Line(" << l.P1 << "," << l.P2 << ")";  // // Access private members

    return os;
}