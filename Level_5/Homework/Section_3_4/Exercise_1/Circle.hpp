// Type: Homework
// Level: 5
// Section: 3.4 Simple Inheritance
// Exercise: 1
// Description: Definition file contains class Circle()
// The colon syntax can improve the performance of constructors.
// To test this, make sure that you print some text in the point’s constructors, destructor
//  and also the assignment operator.
// Now, execute the following code in the test program
//  and count the number of point constructor, destructor and assignment calls:
//      Line l;
// Now, change the constructors in the Line class to use the colon syntax
//  to set the start- and end-point data members and run the test program again.
// Is the number of point constructor, destructor and assignment calls less than before?
// Apply the colon syntax also for the Point class constructors and if applicable also for the Circle class.

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