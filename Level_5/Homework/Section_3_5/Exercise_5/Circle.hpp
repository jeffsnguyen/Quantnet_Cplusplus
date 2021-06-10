// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 5
// Description: Definition file contains class Circle()
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
#ifndef Circle_HPP
#define Circle_HPP

#define _USE_MATH_DEFINES

#include <iostream>
#include <Point.hpp>
#include <Shape.hpp>
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
    void Draw() const;  // Overidden function from Shape() simulating drawing by printing some text

    // Overloading operator
    Circle& operator = (const Circle& source); // Assignment operator.
};

ostream& operator << (ostream& os, const Circle& c); // Send to ostream.

#endif // Circle_HPP