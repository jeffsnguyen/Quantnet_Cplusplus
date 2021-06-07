// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 3
// Description: Source file contains functionalities for class Point()
// It is easy to forget to delete memory created with new.
// A good practice is to let a class manage memory.
// Then the client of that class does not have to manage memory and can’t forget to delete memory.
// So instead of creating a C array with new, you can use an array class that handle memory for you.
// In this exercise we are going to create an array class for Point objects (see Figure 5):
//  • Add a source- and header file for the Array class to your current project.
//  • Add a data member for a dynamic C array of Point objects (Point* m_data).
//  • Add a data member for the size of the array.
//  • Add a default constructor that allocates for example 10 elements.
//  • Add a constructor with a size argument. The implementation should allocate
//      the number of elements specified by thesize input argument.
//  • Add a copy constructor. Keep in mind that just copying the C array pointer
//      will create an Array object that shares the data with the original Array object.
//      Thus you need to allocate a new C array with the same size and copy each element separately.
//  • Add a destructor. It should delete the internal C array. Don’t forget the square brackets.
//  • Add an assignment operator.
//      Keep in mind you can’t copy only the C array pointers just as in the case of the copy constructor.
//  • Also don’t forget to delete the old C array and
//      allocate new memory before copying the elements. This is because C arrays can’t grow.
//
//  Further check if the source object is not the same as the this object.
//  If you don’t check it, then a statement like arr1=arr1 will go wrong.
//  The internal C array will then be deleted before it is copied.
//  • Add a Size() function that returns the size of the array.
//  • Add a SetElement() function that sets an element.
//      When the index is out of bounds, ignore the “set”. We will add better error handling later.
//  • Add a GetElement() function.
//      You can return the element by reference since the returned element
//      has a longer lifetime than the GetElement() function.
//      When the index is out of bounds, return the first element.
//      We will add better error handling later.
//  • You can also add a square bracket operator.
//      Return a reference so the [] operator can be used for both reading and writing elements.
//      When the index is out of bounds, return the first element. We will add better error handling later.
//          Point& operator [] (int index);
//  • In the main program, test the Array class.

/*---------------------------------*/
#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing (x,y) = (0,0)
Point::Point() : m_x(0), m_y(0)
{
    cout << "Default point created" << endl;
}

// Initializing (x,y) = (newX,newY)
Point::Point(double newX, double newY): m_x(newX), m_y(newY)
{
    cout << "Point created." << endl;
}

// Copy Constructor: Initializing (x,y) = (newX,newY)
Point::Point(const Point& point): m_x(point.m_x), m_y(point.m_y)
{
    cout << "Copy constructor called." << endl;
}

// Destructor
Point::~Point()
{
	cout << "Point destroyed.\n";
}

// Get x value
double Point::X() const
{
	return m_x;
}

// Set new value for x
void Point::X(double newX)
{ 
	m_x = newX;
}

// Get y value
double Point::Y() const
{
	return m_y;
}

// Set new value for y
void Point::Y(double newY)
{ 
	m_y = newY;
}

// Return string description of the point
string Point::ToString() const
{
    // Declare stringstream objects
    stringstream xSTR, ySTR;

    // Insert inputs to stream
    xSTR << m_x;
    ySTR << m_y;

    return "Point(" + xSTR.str() + "," + ySTR.str() + ")";
}

// Calculate the distance to the origin (0, 0).
double Point::Distance() const
{
    return sqrt(pow(m_x,2) + pow(m_y,2));
}

// Calculate the distance between two points.
double Point::Distance(const Point& p) const
{
    return sqrt(pow(m_x-p.m_x,2) + pow(m_y-p.m_y,2));
}

// Negate the coordinates.
Point Point::operator - () const
{
    return Point(-m_x, -m_y);
}

// Scale the coordinates.
Point Point::operator * (double factor) const
{
    return Point(factor*m_x, factor*m_y);
}

// Add coordinates.
Point Point::operator + (const Point& p) const
{
    return Point(m_x+p.m_x, m_y+p.m_y);
}

// Equally compare operator.
bool Point::operator == (const Point& p) const
{
    if (m_x == p.m_x and m_y == p.m_y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Assignment operator.
Point& Point::operator = (const Point& source)
{
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        m_x = source.m_x;
        m_y = source.m_y;

        return *this;  // Assign the result to itself
    }
}

// Scale the coordinates & assign.
Point& Point::operator *= (double factor)
{
    m_x = factor * m_x;
    m_y = factor * m_y;

    return *this;  // Assign the result to itself
}

// Send to ostream.
ostream& operator << (ostream& os, const Point& p)
{
    os << "Point(" << p.m_x << "," << p.m_y << ")";  // Access private members

    return os;
}