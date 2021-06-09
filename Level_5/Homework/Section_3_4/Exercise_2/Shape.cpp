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
//      You can use the rand() function from the “stdlib.h” header file.
//  •Add a copy constructor that copies the id member.
//  •Add an assignment operator that copies the id member.
//  •Add a ToString() function that returns the id as string e.g. “ID: 123”.
//  •Add an ID() function the retrieve the id of the shape.
// Next the Point and Line classes (and the Circle class if applicable) must derive from Shape.
//  •Add the Shape class in the inheritance list of the Point, Line and optionally the Circle class.
//  •The constructors of the Point, Line and optionally the Circle class
//      should call the appropriate constructor in the Shape base class.
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
#include "Shape.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

/*---------------------------------*/
// Initializing Shape with random ID value
Shape::Shape() : m_id(rand())
{
    cout << "Default shape created" << endl;
}

// Initializing Shape with speicifc ID
Shape::Shape(int newID) : m_id(newID)
{
    cout << "Shape created." << endl;
}

// Copy Constructor: Initializing (m_id) = shape.m_id
Shape::Shape(const Shape &shape) : m_id(shape.m_id)
{
    cout << "Shape Copy constructor called." << endl;
}

// Destructor
Shape::~Shape()
{
    cout << "Shape destroyed.\n";
}

// Get id value
int Shape::ID() const
{
    return m_id;
}

// Set new value for id
void Shape::ID(int newID)
{
    m_id = newID;
}

// Return string description of the shape
string Shape::ToString() const
{
    // Declare stringstream objects
    stringstream idSTR;

    // Insert inputs to stream
    idSTR << m_id;

    return "Shape(" + idSTR.str() + ")";
}

// Assignment operator.
Shape &Shape::operator=(const Shape &source)
{
    cout << "Assignment operator" << endl;
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        m_id = source.m_id;

        return *this;  // Assign the result to itself
    }
}

// Send to ostream.
ostream &operator<<(ostream &os, const Shape &s)
{
    os << "Shape(" << s.m_id << ")";  // Access private members

    return os;
}