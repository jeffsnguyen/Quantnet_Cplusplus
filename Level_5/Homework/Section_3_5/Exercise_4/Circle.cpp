// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 4
// Description: Source file contains functionalities for class Circle()
// Sometimes functions in the base class are only there to be overridden in the derived class.
// Assume that you want to draw all the shapes using the following code:
//      Shape* shapes[10];
//      shapes[0]=new Line;
//      shapes[1]=new Point;
//      ...
//      shapes[9]=new Line(Point(1.0, 2.5), Point(3.4, 5.2));
//      for (int i=0; i!=10; i++) shapes[i]->Draw();
//      for (int i=0; i!=10; i++) delete shapes[i];
//
// Create the Draw() function in the Shape base class
//  and override it in the derived classes (point, line and if present the circle class).
// Simulate drawing by just printing some text.
// What implementation did you give the Draw() function in Shape?
// Shape is just an abstraction to work with various kinds of shapes like lines and circles.
// Shapes don’t have a physical appearance.
// Therefore its Draw() function will have an empty implementation.
// But better is to give it no implementation at all by making it a pure virtual member function:
//      virtual void Draw()=0;
// Do this in your code.
// Try to create an instance of the Shape class.
// Is this possible? Now the Shape class is really an abstraction.
// You don’t make shape instances but you can still create shape pointers
//  that point to concrete shapes like point and line.
// The Shape class is now an abstract base class.

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
    cout << "Simulating point drawing." << endl;
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
