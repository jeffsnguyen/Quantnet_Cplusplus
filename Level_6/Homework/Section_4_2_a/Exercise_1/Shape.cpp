// Type: Homework
// Level: 6
// Section: 4.2a Introduction to Templates
// Exercise: 1
// Description: Source file contains functionalities for class Shape()
// In a previous exercise we created an Array class that stores Point objects.
// The disadvantage of this class was that it only stores Point objects.
// If we want to have an array class for Lines,
//  we need to copy the code and replace references to Point to Line.
// This is a lot of work and makes maintenance more difficult.
// A bug in one version has to be fixed in the other versions as well.
// Better is to use the same code for different data types.
// This is possible using templates as shown in Figure 1.
//
// Thus transform the Array class for points created earlier into a template class:
//  •In the header file, declare the Array class as a template of type T.
//  •Replace all references to Point with T.
//  •Where an array is used as input or output, replace Array by Array<T>.
//  •In the source file, every function must be declared as a template of type T.
//  •The functions are now not a member of Array anymore but a member of Array<T>.
//  •Further replace all references to Point with T.
//  •Finally where an array is used as input or output, replace Array by Array<T>.
//  •Don’t forget that the test program should now include the source file instead of the header file.
//  Therefore, the source file should now also include#ifndef/#define/#endif statements.
//
//  In the test program create an array of points and test it:
//      Array<Point> points(size);
//  Tip: by placing the following code at the end of the array header file,
//  but before the header file’s #endif, the client can keep including the header file
//  for template classes instead of the source file. Can you explain how this works?:
//      #ifndef Array_cpp // Must be the same name as in source file #define
//      #include "Array.cpp"
//      #endif

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