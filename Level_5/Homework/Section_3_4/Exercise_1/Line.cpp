// Type: Homework
// Level: 5
// Section: 3.4 Simple Inheritance
// Exercise: 1
// Description: Source file contains functionalities for class Line()
// The colon syntax can improve the performance of constructors.
// To test this, make sure that you print some text in the point’s constructors, destructor
//  and also the assignment operator.
// Now, execute the following code in the test program
//  and count the number of point constructor, destructor and assignment calls:
//      Line l;
// Now, change the constructors in the Line class to use the colon syntax
//  to set the start- and end-point data members and run the test program again.
// Is the number of point constructor, destructor and assignment calls less than before?
// Apply the colon syntax also for the Point class constructors and if applicable also for the Circle class.

/*---------------------------------*/
#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing (x,y) = (0,0)
Line::Line() : P1(0, 0), P2(0, 0)
//Line::Line()
{
    //P1 = Point(0,0);
    //P2 = Point(0,0);
    cout << "Default line created" << endl;
}

// Initializing Line(p1,p2) = Line(Point(newX1, newY1), Point(newX2, newY2))
Line::Line(Point &newP1, Point &newP2) : P1(newP1), P2(newP2)
{
    cout << "Line created." << endl;
}

// Copy Constructor: Initializing Line(line) = Line(point1,point2)
Line::Line(const Line &line) : P1(line.P1), P2(line.P2)
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
void Line::point1(const Point &newP1)
{
    P1 = newP1;
}

// Get P2 value
Point Line::point2() const
{
    return P2;
}

// Set new value for P2
void Line::point2(const Point &newP2)
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
Line &Line::operator=(const Line &source)
{
    cout << "Assignment operator" << endl;
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
ostream &operator<<(ostream &os, const Line &l)
{
    os << "Line(" << l.P1 << "," << l.P2 << ")";  // // Access private members

    return os;
}