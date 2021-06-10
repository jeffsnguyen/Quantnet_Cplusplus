// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 5
// Description: Definition file contains class Point()
// In this exercise we are going to create a Print() function
//  that is printing the shape information to the cout object.
// The Print() function can use the ToString() to obtain the string to print.
// You see that the implementation of Print() is in each derived class largely the same;
//  calling ToString() and sending the result to cout.
// Since the ToString() function is polymorphic,
//  we can use the polymorphic behavior in the Print() function of Shape.
// Thus:
//  •Add a Print() function to the Shape class.
//  •In this function, call the ToString() function and send the result to the cout object.
//  •In the test program, create a point and line object and call the Print() function. Does itprint the right information even when point and line do not have the Print() function?
// You have now created a function for the base class (Print())
//  that does all the functionality common to all derived classes.
// Only the part of that function that is different for each derived class
//  is delegated to a polymorphic function (ToString()).
// This mechanism is an often used design pattern called the “Template Method Pattern”.

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