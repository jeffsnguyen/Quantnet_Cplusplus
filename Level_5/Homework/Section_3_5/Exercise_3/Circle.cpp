// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 3
// Description: Source file contains functionalities for class Circle()
// When objects are removed from memory, the destructor is called.
// When a derived class destructor is called,
//  it will automatically call the base class destructor.
// But when you have pointers to a base class, deleting objects might not be done correctly.
// If not done already, print some text in the destructors of the Shape, Point and Line classes.
// Then test the following code:
//  Shape* shapes[3];
//  shapes[0]=new Shape;
//  shapes[1]=new Point;
//  shapes[2]=new Line;
//  for (int i=0; i!=3; i++) delete shapes[i];
// Will the proper destructors (including the destructor of the Shape base class) be called?
// In this case, the derived class destructor
//  will only be called when the destructor is declared virtual in the base class.
// Do this in the Shape class and run the code again. Are the proper destructors called now?

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
