// Type: Homework
// Level: 4
// Section: 2.5 The Free Store
// Exercise: 1
// Description: Definition file contains class Point()
// Until now, we created objects on the stack.
// The stack is limited in size thus when creating many objects,
//  the stack will overflow.
// Also arrays created on the stack can only have a fixed size determined at compile time.
//
// To overcome these problems we have to create objects on the heap using new.
// In the main program, create Point objects on the heap with new using the default constructor,
//  constructor with coordinates and the copy constructor
//  and assign it to pointer (Point*) variables.
// Note that you can’t directly pass a pointer variable as argument to the copy constructor.
// The pointer must first be dereferenced when passing it to the copy constructor.
//  (Point* p2=new Point(*p1)).
// Next call the Distance() function on the pointers and try to send the Point pointers to cout.
// You need to dereference the pointer when passing it as argument.
// Don’t forget to delete the object created with new.
// Test the main program.
//
// Next, we will create an array of points.
// First ask the user for the size of the array and read it using cin.
// Then try to create an array on the stack using the entered size.
// You will see a compiler error.
// Arrays on the stack must have the size set at compile time.
// Now create the array on the heap using new.
// Can you use other constructors than the default constructor for the objects created in the array?
// Don’t forget to delete the array after use.
// Don’t forget the square brackets when deleting arrays!
//
// Some C++ compilers (e.g. GCC) support variable length arrays (VLA)
//  where the size can be determined at run-time.
// However this is a C99 feature that is not in the C++ standard.
// Because VLA is not in the C++ standard you should avoid its usage since it will lead to less portable code.

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
    friend ostream& operator << (ostream& os, const Point& p); // Send to ostream.
};

#endif // Point_HPP