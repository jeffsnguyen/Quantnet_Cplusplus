// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 3
// Description: Definition file contains class Circle()
// You can create an array of points by directly instantiating the Array class for the Point class.
// This works well but we can’t add points specific functionality to the Array class in this way.
// A solution is to create a derived class
//  of which the template argument is fixed to a specific type (concrete inheritance) as shown in Figure 3.
// In this exercise we will create a PointArray which is derived from Array with the template argument set to Point.
//  •Add a new source- and header file for the PointArray class to your project.
//  •Create a regular class called PointArray which is derived from Array.
//      The template argument given to Array is Point.
//  •Since they are not inherited, create proper constructors, destructor
//      and assignment operator and call the base class where appropriate.
//  •Now we can add functionality specific for a point array.
//      For example add a Length()function that returns the total length between the points in the array.
//  •Change the main program to test the point array.


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