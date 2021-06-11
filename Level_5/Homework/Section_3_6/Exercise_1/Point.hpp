// Type: Homework
// Level: 5
// Section: 3.6 Exception Handling
// Exercise: 1
// In the array class we created previously, the bounds checking was very basic.
// There was no error generated, but setting an element was ignored or the first element was returned.
// Obviously you want to know if there was an out of bounds error.
// This is possible by exception handling. Change the Array class to throw exceptions:
//  •In the GetElement(), SetElement() and index operator throw -1 if the index was too small or too big.
//  •In the main program, create an Array object and access an element that does not exist.
//      Run the program. What happens?
//  •The exception must be caught, so place the code inside a try ... catch block that catches an int.
//  •In the catch handler, print an error message.

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
    void Draw() const;  // Overidden function from Shape() simulating drawing by printing some text

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