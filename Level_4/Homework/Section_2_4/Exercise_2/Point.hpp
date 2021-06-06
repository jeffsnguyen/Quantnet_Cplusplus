// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 2
// Description: Definition file contains class Point()
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
#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;

/*---------------------------------*/
class Point
{
private:
	double m_x;  // X coordinate
	double m_y;  // Y coordinate

public:
	// Constructors
	Point();  // Default constructor
	Point(double newX, double newY);  // Initialize with x and y value
    Point(const Point& point);  // Copy constructor

    // Destructor
	~Point();

	// Accessing functions
    double X() const;  // The x-coordinate
    void X(double newX);
    double Y() const;  // The y-coordinate
    void Y(double newY);
    string ToString() const;  // Return string description of the point
    double Distance() const; // Calculate the distance to the origin (0, 0).
    double Distance(const Point& p) const; // Calculate the distance between two points.

    // Overloading operators
    Point operator - () const; // Negate the coordinates.
    Point operator * (double factor) const; // Scale the coordinates.
    Point operator + (const Point& p) const; // Add coordinates.
    bool operator == (const Point& p) const; // Equally compare operator.
    Point& operator = (const Point& source); // Assignment operator.
    Point& operator *= (double factor); // Scale the coordinates & assign.
};

ostream& operator << (ostream& os, const Point& p); // Send to ostream.

#endif // Point_HPP