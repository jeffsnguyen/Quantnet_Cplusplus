// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 1
// Description: Source file contains functionalities for class Shape()
// The ToString() functions of Point and Line override the ToString() from the Shape base class.
// We saw that we could put a Point in a Shape* variable.
// But when calling the ToString() method on the Shape* variable,
//  the function in Shape was called instead the one in Point.
//
//  To make the compiler generate the required code to find out
//      what type of object the Shape*variable is actually pointing to so it can call the right version;
//      we need to declare the function as virtual.
//  Thus declare the ToString() function in the Shape class as virtual
//      and test the program again.
//  Is the ToString() function of Point called when you use a Shape* that contains a Point now?

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