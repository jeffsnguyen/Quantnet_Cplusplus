// Type: Homework
// Level: 6
// Section: 4.2a Introduction to Templates
// Exercise: 1
// Description: Definition file contains class Circle()
// In a previous exercise we created an Array class that stores Point objects.
// The disadvantage of this class was that it only stores Point objects.
// If we want to have an array class for Lines,
//  we need to copy the code and replace references to Point to Line.
// This is a lot of work and makes maintenance more difficult.
// A bug in one version has to be fixed in the other versions as well.
// Better is to use the same code for different data types.
// This is possible using templates as shown in Figure 1.
//
// Thus transform the Array class for points created earlier into a template class:
//  •In the header file, declare the Array class as a template of type T.
//  •Replace all references to Point with T.
//  •Where an array is used as input or output, replace Array by Array<T>.
//  •In the source file, every function must be declared as a template of type T.
//  •The functions are now not a member of Array anymore but a member of Array<T>.
//  •Further replace all references to Point with T.
//  •Finally where an array is used as input or output, replace Array by Array<T>.
//  •Don’t forget that the test program should now include the source file instead of the header file.
//  Therefore, the source file should now also include#ifndef/#define/#endif statements.
//
//  In the test program create an array of points and test it:
//      Array<Point> points(size);
//  Tip: by placing the following code at the end of the array header file,
//  but before the header file’s #endif, the client can keep including the header file
//  for template classes instead of the source file. Can you explain how this works?:
//      #ifndef Array_cpp // Must be the same name as in source file #define
//      #include "Array.cpp"
//      #endif

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