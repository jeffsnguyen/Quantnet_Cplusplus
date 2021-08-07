// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Definition file contains class Circle()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.


/*---------------------------------*/
#ifndef Circle_HPP
#define Circle_HPP

#define _USE_MATH_DEFINES

#include <iostream>
#include "Point.hpp"
#include "Shape.hpp"
#include <cmath>

using namespace std;

/*---------------------------------*/
class Circle : public Shape
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
    virtual ~Circle();

    // Accessing functions
    Point centerP() const;  // The center point of the circle
    void centerP(const Point& newC);
    double rad() const;  // The radius
    void rad(const double new_r);
    string ToString() const;  // Return string description of the circle
    double Diameter() const;  // Calculate the diameter of the circle
    double Area() const;  // Calculate the area of the circle
    double Circumference() const;  // Calculate the circumference of the circle
    void Draw() const;  // Overidden function from Shape() simulating drawing by printing some text

    // Overloading operator
    Circle& operator = (const Circle& source); // Assignment operator.
};

ostream& operator << (ostream& os, const Circle& c); // Send to ostream.

#endif // Circle_HPP