// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 6
// Description: Source file contains functionalities for class Circle()
// Create a Circle class.
// It has a center point and radius.
// Create the proper constructors, destructor, selector and modifier functions.
// Also add functions for getting the diameter, area and circumference.
// Don’t forget a ToString() function.
// In further exercises, all optimizations requested for Line
//  should also be implemented for Circle. See also Figure 4.
// Note that instead of using your own PI value,
//  Microsoft’s version of the math library defines a constant for PI named M_PI.
// But because it is not standard you need to enable that define
//  by setting the _USE_MATH_DEFINES symbol in the project settings or add before including “cmath”:
//  #define _USE_MATH_DEFINES

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
