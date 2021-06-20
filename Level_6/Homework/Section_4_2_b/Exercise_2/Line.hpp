// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 2
// Description: Definition file contains class Line()
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
#ifndef Line_HPP
#define Line_HPP

#include <iostream>
#include "Point.hpp"
#include "Shape.hpp"

using namespace std;

/*---------------------------------*/
class Line : public Shape
{
private:
    Point P1;  // point 1
    Point P2;  // point 2

public:
    // Constructors
    Line();  // Default constructor
    Line(Point &newP1, Point &newP2);  // Initialize with start and end points
    Line(const Line &line);  // Copy constructor

    // Destructor
    ~Line();

    // Accessing functions
    Point point1() const;  // The start point
    void point1(const Point &newP1);

    Point point2() const;  // The end point
    void point2(const Point &newP2);

    string ToString() const;  // Return string description of the line
    double Length() const;  // Calculate the length of the line
    void Draw() const;  // Overidden function from Shape() simulating drawing by printing some text

    // Overloading Operator
    Line &operator=(const Line &source); // Assignment operator.
    friend ostream &operator<<(ostream &os, const Line &l); // Send to ostream.
};

#endif // Line_HPP