// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 4
// Description: Definition file contains class Line()
// Normally, only member functions of a class can access the private members of that class.
// Global functions and other classes can’t access the private members of that class.
// You can make an exception on that rule by declaring certain functions or classes as friend.
//
// For example the << operator for sending the point or line to the std::ostream class
//  had to be a global function and thus can’t access the private members.
// Move the << operator of Point and Line inside the class definition and declare it as friend.
// The function remains a global function but it can now access the data members directly
//  without the need for calling the getters or ToString() function.
//
//  Normally, friends are to be avoided because it violates the data hiding principle.
//  But in case of global operator functions it makes sense
//      because you would actually want to make those global operator functions as member function
//      but this was not possible.

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
    friend ostream& operator << (ostream& os, const Line& l); // Send to ostream.
};



#endif // Line_HPP