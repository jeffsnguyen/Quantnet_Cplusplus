// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 5
// Description: Definition file contains class Line()
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
#ifndef Line_HPP
#define Line_HPP

#include <iostream>
#include <Point.hpp>
#include <Shape.hpp>

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