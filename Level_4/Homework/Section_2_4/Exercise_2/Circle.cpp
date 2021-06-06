// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 2
// Description: Source file contains functionalities for class Circle()
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

// Assignment operator.
Circle& Circle::operator = (const Circle& source)
{
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        C = source.C;
        r = source.r;

        return *this;  // Assign the result to itself
    }
}

// Send to ostream.
ostream& operator << (ostream& os, const Circle& c)
{
    os << c.ToString();  // Overloading ToString()

    return os;
}