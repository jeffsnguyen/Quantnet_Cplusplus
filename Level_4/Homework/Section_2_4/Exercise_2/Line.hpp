// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 2
// Description: Definition file contains class Line()
// It would be nice if you could send a point or a line directly
//  to the cout object without calling the ToString() method,
//  just as with the primitive types.
// This is possible by adding a << operator function that has on the left an std::ostream
//  and on the right the point or line object.
// Since you can’t add a member function to the std::ostream class,
//  you have to create it as a global function
//  (outside the class definition, but inside the class header file):
//
//  ostream& operator << (ostream& os, const Point& p); // Send to ostream.
// The implementation uses the << operator to send data to the os input argument.
// Since it is a global function, you can’t access the private members of Point.
// To simplify things, you can use the ToString() method of Point to get the string to send to the os argument.
// Also create a similar << operator for printing lines (and circles if you made a circle class).
// Adapt the test program to test the << operator for points and lines.

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

ostream& operator << (ostream& os, const Line& l); // Send to ostream.

#endif // Line_HPP