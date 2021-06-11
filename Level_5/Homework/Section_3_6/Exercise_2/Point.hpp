// Type: Homework
// Level: 5
// Section: 3.6 Exception Handling
// Exercise: 2
// Description: Description of the Point class
// Throwing an int is an easy solution.
// But exception handling is also object oriented and allows us to throw an object.
// In this exercise we will create an exception hierarchy
//  with an ArrayException base class and an OutOfBoundsExceptionderived class as shown in Figure 3:
//      •You can implement both exception classes in the header file for simplicity.
//      •Give the ArrayException an abstract GetMessage() function that returns a std::string.
//      •Give the OutOfBoundsException class a constructor with an int as argument
//          that indicates the erroneous array index and store it in a data member.
//      •Override the GetMessage() function
//          and let the implementation return a message string saying the given index is out of bounds.
//      •In the Array class, throw now a OutOfBoundsException object instead of an integer.
//      •Change the main program so that it catches the ArrayException base class
//          and uses the GetMessage() function to display an error message.

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