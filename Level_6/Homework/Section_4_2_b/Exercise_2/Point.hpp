// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 2
// Description: Description of the Point class
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