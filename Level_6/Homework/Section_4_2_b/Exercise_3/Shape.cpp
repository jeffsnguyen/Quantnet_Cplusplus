// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 3
// Description: Source file contains functionalities for class Shape()
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