// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 3
// Description: Definition file contains class Circle()
// When objects are removed from memory, the destructor is called.
// When a derived class destructor is called,
//  it will automatically call the base class destructor.
// But when you have pointers to a base class, deleting objects might not be done correctly.
// If not done already, print some text in the destructors of the Shape, Point and Line classes.
// Then test the following code:
//  Shape* shapes[3];
//  shapes[0]=new Shape;
//  shapes[1]=new Point;
//  shapes[2]=new Line;
//  for (int i=0; i!=3; i++) delete shapes[i];
// Will the proper destructors (including the destructor of the Shape base class) be called?
// In this case, the derived class destructor
//  will only be called when the destructor is declared virtual in the base class.
// Do this in the Shape class and run the code again. Are the proper destructors called now?

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

    // Overloading operator
    Circle& operator = (const Circle& source); // Assignment operator.
};

ostream& operator << (ostream& os, const Circle& c); // Send to ostream.

#endif // Circle_HPP