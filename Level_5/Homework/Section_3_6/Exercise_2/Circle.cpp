// Type: Homework
// Level: 5
// Section: 3.6 Exception Handling
// Exercise: 2
// Description: Source file contains functionalities for class Circle()
// Throwing an int is an easy solution.
// But exception handling is also object oriented and allows us to throw an object.
// In this exercise we will create an exception hierarchy
//  with an ArrayException base class and an OutOfBoundsExceptionderived class as shown in Figure 3:
//      •You can implement both exception classes in the header file for simplicity.
//      •Give the ArrayException an abstract GetMessage() function that returns a std::string.
//      •Give the OutOfBoundsException class a constructor with an int as argument
//          that indicates the erroneous array index and store it in a data member.
//      •Override the GetMessage() function
//          and let the implementation return a message string saying the given index is out of bounds.
//      •In the Array class, throw now a OutOfBoundsException object instead of an integer.
//      •Change the main program so that it catches the ArrayException base class
//          and uses the GetMessage() function to display an error message.

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
