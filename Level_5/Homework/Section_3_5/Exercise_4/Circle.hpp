// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 4
// Description: Definition file contains class Circle()
// Sometimes functions in the base class are only there to be overridden in the derived class.
// Assume that you want to draw all the shapes using the following code:
//      Shape* shapes[10];
//      shapes[0]=new Line;
//      shapes[1]=new Point;
//      ...
//      shapes[9]=new Line(Point(1.0, 2.5), Point(3.4, 5.2));
//      for (int i=0; i!=10; i++) shapes[i]->Draw();
//      for (int i=0; i!=10; i++) delete shapes[i];
//
// Create the Draw() function in the Shape base class
//  and override it in the derived classes (point, line and if present the circle class).
// Simulate drawing by just printing some text.
// What implementation did you give the Draw() function in Shape?
// Shape is just an abstraction to work with various kinds of shapes like lines and circles.
// Shapes don’t have a physical appearance.
// Therefore its Draw() function will have an empty implementation.
// But better is to give it no implementation at all by making it a pure virtual member function:
//      virtual void Draw()=0;
// Do this in your code.
// Try to create an instance of the Shape class.
// Is this possible? Now the Shape class is really an abstraction.
// You don’t make shape instances but you can still create shape pointers
//  that point to concrete shapes like point and line.
// The Shape class is now an abstract base class.

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