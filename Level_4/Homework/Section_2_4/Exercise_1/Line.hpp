// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 1
// Description: Definition file contains class Line()
// By supporting operators, you can make your classes easier and more natural to use.
// However you must not “overuse” operators. Only use operators
//  if the functionality of the operator is clear without reading documentation.
// Thus adding mathematical operators to a complex number class is good
//  but using a + operator with a double as an argument on a point
//  to increase the x-coordinate is questionable. So use operators with care.
// In this exercise we add a few operators to the Point class.
// Most operators do not change the original objects but return the result as a new object.
// Normally only the = operator and += and variants change the original object. Add the following operators:
//
//  Point operator - () const; // Negate the coordinates.
//  Point operator * (double factor) const; // Scale the coordinates.
//  Point operator + (const Point& p) const; // Add coordinates.
//  bool operator == (const Point& p) const; // Equally compare operator.
//  Point& operator = (const Point& source); // Assignment operator.
//  Point& operator *= (double factor); // Scale the coordinates & assign.
//  Most operators above are self-explanatory.
//  The = and *= operator changes the current object so they can’t be const functions.
//  To make it possible to chain the = and *= operators (E.g.: a=b+=c),
//      it must return the “this” object.
//  Change the main program to test the operators.
//  Since the assignment operator is part of the canonical header file,
//      add this operator also to the Line and, if applicable, theCircle class.
//  Always be sure to preclude self-assignment inside your assignment operator functions.

/*---------------------------------*/
#ifndef Line_HPP
#define Line_HPP

#include <iostream>
#include <Point.hpp>

using namespace std;

/*---------------------------------*/
class Line
{
private:
	Point P1;  // point 1
	Point P2;  // point 2

public:
	// Constructors
	Line();  // Default constructor
	Line(Point& newP1, Point& newP2);  // Initialize with start and end points
    Line(const Line& line);  // Copy constructor

    // Destructor
	~Line();

	// Accessing functions
    Point point1() const;  // The start point
    void point1(const Point& newP1);
    Point point2() const;  // The end point
    void point2(const Point& newP2);
    string ToString() const;  // Return string description of the line
    double Length() const;  // Calculate the length of the line

    // Overloading Operator
    Line& operator = (const Line& source); // Assignment operator.
};



#endif // Line_HPP