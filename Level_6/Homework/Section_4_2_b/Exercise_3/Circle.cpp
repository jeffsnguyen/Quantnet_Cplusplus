// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 3
// Description: Source file contains functionalities for class Circle()
// You can create an array of points by directly instantiating the Array class for the Point class.
// This works well but we can’t add points specific functionality to the Array class in this way.
// A solution is to create a derived class
//  of which the template argument is fixed to a specific type (concrete inheritance) as shown in Figure 3.
// In this exercise we will create a PointArray which is derived from Array with the template argument set to Point.
//  •Add a new source- and header file for the PointArray class to your project.
//  •Create a regular class called PointArray which is derived from Array.
//      The template argument given to Array is Point.
//  •Since they are not inherited, create proper constructors, destructor
//      and assignment operator and call the base class where appropriate.
//  •Now we can add functionality specific for a point array.
//      For example add a Length()function that returns the total length between the points in the array.
//  •Change the main program to test the point array.


/*---------------------------------*/
#include "Circle.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing Circle(C,r) = ((0,0),0)
Circle::Circle(): Shape(), C(0,0), r(0)
{
    cout << "Default circle created" << endl;
}

// Initializing Circle(C,r) = Circle(C(newC), r(new_r))
Circle::Circle(Point& newC, double new_r): Shape(), C(newC), r(new_r)
{
    cout << "Circle created." << endl;
}

// Copy Constructor: Initializing Line(line) = Line(point1,point2)
Circle::Circle(const Circle& circle): Shape(), C(circle.C), r(circle.r)
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

    string s=Shape::ToString();

    return s + ": " + "Circle(" + C.ToString() + "," + rSTR.str() + ")";
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

// Overidden function from Shape() simulating drawing by printing some text
void Circle::Draw() const
{
    cout << "Simulating circle drawing." << endl;
}

// Assignment operator.
Circle& Circle::operator = (const Circle& source)
{
    cout << "Assignment operator" << endl;
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        Shape::operator=(source);  // Call base class assignment

        return *this;  // Assign the result to itself
    }
}

// Send to ostream.
ostream& operator << (ostream& os, const Circle& c)
{
    os << c.ToString();  // Overloading ToString()

    return os;
}
