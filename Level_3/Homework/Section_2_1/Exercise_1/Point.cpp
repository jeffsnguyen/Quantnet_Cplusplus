// Type: Homework
// Level: 3
// Section: 2.2 The Class Concept
// Exercise: 1
// Description: Source file contains functionalities for class Point()
// First add a header file for the Point class with private members for the x- and y-coordinates.
//  Do not forget to add the #ifndef/#define/#endif statements to avoid multiple inclusion.
//  Also make sure you make to following public functionality (see also Figure 1):
//      • Default constructor.
//      • Destructor.
//      • Getter functions for the x- and y-coordinates (GetX() and GetY() functions).
//      • Setter functions for the x- and y-coordinates (SetX() and SetY() functions).
//      • A ToString() that returns a string description of the point. Use the std::string class as return type.
//  Next create the source file that implements the Point class defined in the header file.
//  The source file must include the header file.
//  Making the string in the ToString() function, requires conversion of the double coordinates to a string.
//  Easiest is to use a std::stringstream object
//      and the standard stream operators (as with iostream) to create the string.
//      This requires the “sstream” header file.
//      Use the str() function to retrieve the string from the string buffer.
//      The output can be like: “Point(1.5, 3.9)”

/*---------------------------------*/
#include "Point.hpp"
#include <iostream>
#include <sstream>

using namespace std;

/*---------------------------------*/
// Initializing (x,y) = (newX,newY)
Point::Point(double newX, double newY) : m_x(newX), m_y(newY)
{
}

// Destructor
Point::~Point()
{
	cout << "Point destroyed.\n";
}

// Get x value
double Point::GetX() const
{
	return m_x;
}

// Set new value for x
void Point::SetX(double newX)
{ 
	m_x = newX;
}

// Get y value
double Point::GetY() const
{
	return m_y;
}

// Set new value for y
void Point::SetY(double newY)
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