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
    cout << "Simulating line drawing." << endl;
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