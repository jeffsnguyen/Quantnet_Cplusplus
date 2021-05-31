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
#include "Circle.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing Circle(C,r) = ((0,0),0)
Circle::Circle(): C(0,0), r(0)
{
    cout << "Default circle created" << endl;
}

// Initializing Circle(C,r) = Circle(C(newC), r(new_r))
Circle::Circle(Point& newC, double new_r): C(newC), r(new_r)
{
    cout << "Circle created." << endl;
}

// Copy Constructor: Initializing Line(line) = Line(point1,point2)
Circle::Circle(const Circle& circle): C(circle.C), r(circle.r)
{
    cout << "Circle Copy constructor called." << endl;
}

// Destructor
Circle::~Circle()
{
	cout << "Circle destroyed.\n";
}

// Get center point value
Point Circle::centerP() const
{
	return C;
}

// Set new value for center point
void Circle::centerP(const Point& newC)
{ 
	C = newC;
}

// Get radius value
double Circle::rad() const
{
	return r;
}

// Set new value for radius
void Circle::rad(double new_r)
{ 
	r = new_r;
}

// Return string description of the circle, overloading from Point class
string Circle::ToString() const
{
    // Declare stringstream objects
    stringstream rSTR;

    // Insert inputs to stream
    rSTR << r;

    return "Circle(" + C.ToString() + "," + rSTR.str() + ")";
}

// Calculate the length of the line
double Circle::Diameter() const
{
    return 2*r;
}

// Calculate the area of the circle
double Circle::Area() const
{
    return M_PI * pow(r,2);
}

// Calculate the circumference of the circle
double Circle::Circumference() const
{
    return 2 * M_PI * r;
}
