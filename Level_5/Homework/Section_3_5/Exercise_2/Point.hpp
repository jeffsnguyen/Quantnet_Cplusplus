// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 2
// Description: Definition file contains class Point()
// The ToString() functions of Point and Line override the ToString() from the Shape base class.
// We saw that we could put a Point in a Shape* variable.
// But when calling the ToString() method on the Shape* variable,
//  the function in Shape was called instead the one in Point.
//
//  To make the compiler generate the required code to find out
//      what type of object the Shape*variable is actually pointing to so it can call the right version;
//      we need to declare the function as virtual.
//  Thus declare the ToString() function in the Shape class as virtual
//      and test the program again.
//  Is the ToString() function of Point called when you use a Shape* that contains a Point now?

/*---------------------------------*/
#ifndef Point_HPP
#define Point_HPP

#include "Shape.hpp"
#include <iostream>
using namespace std;

/*---------------------------------*/
class Point: public Shape
{
private:
    double m_x;  // X coordinate
    double m_y;  // Y coordinate

public:
    // Constructors
    Point();  // Default constructor
    Point(double newX, double newY);  // Initialize with x and y value
    Point(const Point &point);  // Copy constructor

    // Destructor
    ~Point();

    // Accessing functions
    double X() const;  // The x-coordinate
    void X(double newX);

    double Y() const;  // The y-coordinate
    void Y(double newY);

    string ToString() const;  // Return string description of the point
    double Distance() const; // Calculate the distance to the origin (0, 0).
    double Distance(const Point &p) const; // Calculate the distance between two points.

    // Overloading operators
    Point operator-() const; // Negate the coordinates.
    Point operator*(double factor) const; // Scale the coordinates.
    Point operator+(const Point &p) const; // Add coordinates.
    bool operator==(const Point &p) const; // Equally compare operator.
    Point &operator=(const Point &source); // Assignment operator.
    Point &operator*=(double factor); // Scale the coordinates & assign.
    friend ostream &operator<<(ostream &os, const Point &p); // Send to ostream.
};

#endif // Point_HPP