// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 5
// Description: Source file contains functionalities for class Line()
// In the final exercise for this chapter we are going to create a Line class.
// The Line class has a start- and an end-point. So the Line class should have two Point objects as data members.
// This mechanism is called “composition”. See also Figure 3. Give the Line class the following functionality:
//  • Default constructor (set the points to 0, 0).
//  • Constructor with a start- and end-point.
//  • Copy constructor.
//  • Destructor.
//  • Overloaded getters for the start- and end-point.
//  • Overloaded setters for the start- and end-point.
//  • A ToString() function that returns a description of the line.
//  • A Length() function that returns the length of the line.
//      Note that you can use the distance function on the embeddedPoint objects to calculate the length.
//      This mechanism is called “delegation”.
//  Use const arguments, const functions and pass objects by reference where applicable.

/*---------------------------------*/
#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing Line(p1,p2) = Line((0,0),(0,0))
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
