// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 2
// Description: Source file contains functionalities for class Shape()
// With templates it is possible to call functionality on the template argument.
// But when you do this, you limit the types you can use as the template argument
//  because they have to support that functionality.
// Thus when adding numeric functionality to the Array class like calculating the sum,
//  you would limit the types possible as the template argument to types that support numeric operations.
//  It is better to leave the Array class as generic as possible so it can be used in various situations.
//  Numeric functionality can then be put in a derived class
//      which itself is also a template (generic inheritance) as shown in Figure 2.
// In this exercise we are going to create a NumericArray derived from Array.
//  •Add a new source- and header file for a NumericArray class to your project.
//  •Create a template class called NumericArray and derive it from the Array class using generic inheritance.
//  •Since they are not inherited, create proper constructors, destructor and
//      assignment operator and call the base class where appropriate.
//  •Add the following numeric functionality:
//      o An operator * to scale the elements of the numeric array by a factor.
//      o An operator + to add the elements of two numeric arrays.
//          Throw an exception if the two arrays have not the same size.
//      o A function to calculate the dot product. The dot product is defined as:
// Change the main program to test the numeric array.
// What assumptions do you make about the type used as template argument?
// Can you create a numeric array with Point objects?


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