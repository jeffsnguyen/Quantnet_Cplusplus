// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 4
// Description: Definition file contains class Line()
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