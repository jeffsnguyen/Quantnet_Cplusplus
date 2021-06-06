// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 2
// Description: Definition file contains class Circle()
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
#ifndef Circle_HPP
#define Circle_HPP

#define _USE_MATH_DEFINES

#include <iostream>
#include <Point.hpp>
#include <cmath>

using namespace std;

/*---------------------------------*/
class Circle
{
private:
	Point C;  // point 1
	double r;  // point 2

public:
	// Constructors
	Circle();  // Default constructor
	Circle(Point& newC, double new_r);  // Initialize with center point and radius
    Circle(const Circle& circle);  // Copy constructor

    // Destructor
	~Circle();

	// Accessing functions
    Point centerP() const;  // The center point of the circle
    void centerP(const Point& newC);
    double rad() const;  // The radius
    void rad(const double new_r);
    string ToString() const;  // Return string description of the circle
    double Diameter() const;  // Calculate the diameter of the circle
    double Area() const;  // Calculate the area of the circle
    double Circumference() const;  // Calculate the circumference of the circle

    // Overloading operator
    Circle& operator = (const Circle& source); // Assignment operator.
};

ostream& operator << (ostream& os, const Circle& c); // Send to ostream.

#endif // Circle_HPP