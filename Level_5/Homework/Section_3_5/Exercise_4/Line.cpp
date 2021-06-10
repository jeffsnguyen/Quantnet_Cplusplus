// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 4
// Description: Source file contains functionalities for class Shape()
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
#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing (x,y) = (0,0)
Line::Line() : Shape(), P1(0, 0), P2(0, 0)
{
    cout << "Default line created" << endl;
}

// Initializing Line(p1,p2) = Line(Point(newX1, newY1), Point(newX2, newY2))
Line::Line(Point& newP1, Point& newP2) : Shape(), P1(newP1), P2(newP2)
{
    cout << "Line created." << endl;
}

// Copy Constructor: Initializing Line(line) = Line(point1,point2)
Line::Line(const Line& line) : Shape(), P1(line.P1), P2(line.P2)
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
    string s=Shape::ToString();

    return s + ": " + "Line(" + P1.ToString() + "," + P2.ToString() + ")";
}

// Calculate the length of the line
double Line::Length() const
{
    return P1.Distance(P2);
}

// Overidden function from Shape() simulating drawing by printing some text
void Line::Draw() const
{
    cout << "Simulating point drawing." << endl;
}

// Assignment operator.
Line &Line::operator=(const Line& source)
{
    cout << "Assignment operator" << endl;
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        // Call base class assignment
        Shape::operator= (source);

        return *this;
    }
}

// Send to ostream.
ostream &operator<<(ostream& os, const Line& l)
{
    os << "Line(" << l.P1 << "," << l.P2 << ")";  // // Access private members

    return os;
}