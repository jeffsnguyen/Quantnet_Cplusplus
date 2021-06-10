// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 5
// Description: Test file to test Shape() class.
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
#include "Point.hpp"
#include "Point.cpp"
#include "Line.hpp"
#include "Line.cpp"
#include "Circle.hpp"
#include "Circle.cpp"
#include "Shape.hpp"
#include "Shape.cpp"
#include <iostream>

using namespace std;

/*---------------------------------*/
int main()
{
    // Test Point::ToString()
    Shape* sPoint = new Point(1,1);  // Create pointer to a shape variable.
    (*sPoint).Print();

    // Test Line::ToString()
    Point p1 = Point(1,1);
    Point p2 = Point(2,2);
    Shape* sLine = new Line(p1, p2);  // Create pointer to a shape variable.
    (*sLine).Print();

    // Test Circle::ToString()
    double d = p1.Distance(p2);
    Shape* sCircle = new Circle(p1, d);
    (*sCircle).Print();

    // All correct information are printed even when point, circle and line don't have Print()

    return 0;
}



