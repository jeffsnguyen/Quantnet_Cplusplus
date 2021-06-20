// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 2
// Description: Definition file contains class Circle()
// With templates it is possible to call functionality on the template argument.
// But when you do this, you limit the types you can use as the template argument
//  because they have to support that functionality.
// Thus when adding numeric functionality to the Array class like calculating the sum,
//  you would limit the types possible as the template argument to types that support numeric operations.
//  It is better to leave the Array class as generic as possible so it can be used in various situations.
//  Numeric functionality can then be put in a derived class
//      which itself is also a template (generic inheritance) as shown in Figure 2.
// In this exercise we are going to create a NumericArray derived from Array.
//  •Add a new source- and header file for a NumericArray class to your project.
//  •Create a template class called NumericArray and derive it from the Array class using generic inheritance.
//  •Since they are not inherited, create proper constructors, destructor and
//      assignment operator and call the base class where appropriate.
//  •Add the following numeric functionality:
//      o An operator * to scale the elements of the numeric array by a factor.
//      o An operator + to add the elements of two numeric arrays.
//          Throw an exception if the two arrays have not the same size.
//      o A function to calculate the dot product. The dot product is defined as:
// Change the main program to test the numeric array.
// What assumptions do you make about the type used as template argument?
// Can you create a numeric array with Point objects?


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