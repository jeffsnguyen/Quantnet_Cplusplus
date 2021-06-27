// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Description file contains class Shape()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.


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

// Template Method Pattern to Print derived class description via ToString()
void Shape::Print() const
{
    cout << ToString() << endl;
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