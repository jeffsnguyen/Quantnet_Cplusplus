// Type: Homework
// Level: 5
// Section: 3.4 Simple Inheritance
// Exercise: 2
// Description: Source file contains functionalities for class Shape()
// It can be useful to create a hierarchy of related classes using base- and derived classes.
//  •Classes are related (same family)
//  •Common data and functionality can be put in a base class.
//  •You can work with derived classes as if it is the base class.
// In this exercise we are going to transform the Point and Line class into a Shape hierarchy as shown in Figure 1.
// First create a Shape base class.
//  •Add a source- and header file for a Shape class.
//  •Add a data member for an id number of type int.
//  •Add a default constructor that initializes the id using a random number.
//      You can usethe rand() function from the “stdlib.h” header file.
//  •Add a copy constructor that copies the id member.
//  •Add an assignment operator that copies the id member.
//  •Add a ToString() function that returns the id as string e.g. “ID: 123”.
//  •Add an ID() function the retrieve the id of the shape.
// Next the Point and Line classes (and the Circle class if applicable) must derive from Shape.
//  •Add the Shape class in the inheritance list of the Point, Line and optionallythe Circle class.
//  •The constructors of the Point, Line and optionally the Circle class
//      should call theappropriate constructor in the Shapebase class.
//  •The assignment operator should call the assignment operator of the Shape baseclass.
//      Otherwise the shape data will not be copied.
//  •Finally add code to the main program to test inheritance:
//      Shape s;// Create shape.
//      Point p(10, 20);// Create point.
//      Line l(Point(1,2), Point(3, 4)); // Create line.
//
//      cout<<s.ToString()<<endl;// Print shape.
//      cout<<p.ToString()<<endl;// Print point.
//      cout<<l.ToString()<<endl;// Print line
//
//      cout<<"Shape ID: "<<s.ID()<<endl; // ID of the shape.
//      cout<<"Point ID: "<<p.ID()<<endl; // ID of the point. Does this work?
//      cout<<"Line ID: "<<l.ID()<<endl; // ID of the line. Does this work?
//
//      Shape* sp; // Create pointer to a shape variable.
//      sp=&p; // Point in a shape variable. Possible?
//      cout<<sp->ToString()<<endl;// What is printed?
//
//      //Create and copy Point p to new point.
//      Point p2;
//      p2=p;
//      cout<<p2<<", "<<p2.ID()<<endl; // Is the ID copied if you do not call
//      //the base class assignment in point?
//      Answer the questions in the comments of the code above.

/*---------------------------------*/
#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing (x,y) = (0,0)
Line::Line() : P1(0, 0), P2(0, 0)
//Line::Line()
{
    //P1 = Point(0,0);
    //P2 = Point(0,0);
    cout << "Default line created" << endl;
}

// Initializing Line(p1,p2) = Line(Point(newX1, newY1), Point(newX2, newY2))
Line::Line(Point &newP1, Point &newP2) : P1(newP1), P2(newP2)
{
    cout << "Line created." << endl;
}

// Copy Constructor: Initializing Line(line) = Line(point1,point2)
Line::Line(const Line &line) : P1(line.P1), P2(line.P2)
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
void Line::point1(const Point &newP1)
{
    P1 = newP1;
}

// Get P2 value
Point Line::point2() const
{
    return P2;
}

// Set new value for P2
void Line::point2(const Point &newP2)
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

// Assignment operator.
Line &Line::operator=(const Line &source)
{
    cout << "Assignment operator" << endl;
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        P1 = source.P1;
        P2 = source.P2;

        return *this;
    }
}

// Send to ostream.
ostream &operator<<(ostream &os, const Line &l)
{
    os << "Line(" << l.P1 << "," << l.P2 << ")";  // // Access private members

    return os;
}