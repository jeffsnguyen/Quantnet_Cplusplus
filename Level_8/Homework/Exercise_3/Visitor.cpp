// Type: Homework
// Level: 8
// Section: Smart Pointers
// Exercise: 3
// Description: Source file contains functionalities for class Visitor()
// In contrast to tuple, a boost::variant stores one value that can be of one of the specified types.
//  It is thus similar to a C union but it is type-safe.
// In this exercise we want to create a function that ask the user what kind of shape
//  to create and returns that. In this case we can return the created shape as Shape*
//  because all shapes have a common base class but that involves creating the shapes with new.
// Instead we can return the created shape a boost::variant which would also be needed
//  if the shapes did not have a common base class.
// Thus create a typedef for a ShapeType variant that can contain a Point, Line or Circle.
//  Next create a function that returns the variant. Within this function ask the user
//      for the shape type to create.
//  Then create the requested shape and assign it to the variant and return it.
// In the main program, call the function and print the result by sending it to cout.
// Next try to assign the variant to a Line variable by using the global boost:get<T>() function.
// This will throw a boost::bad_get exception when the variant didn’t contain a line.
// Test the application.
// Checking what kind a type is stored in the variant is cumbersome.
// Therefore the boost::variant supports visitors.
// A visitor is a class derived from boost::static_visitor<T>
//  that has for each type that can be stored an operator () with the type as argument.
// The template argument is the return type of the operators ().
// Now create a variant visitor that moves the shapes.
// The visitor is derived from boost::static_visitor<void>
//  and must have members for the x- and y-offset that are set in the constructor.
// For each shape, create an operator () that changes the coordinates of the shape.
// For example the function for Point is defined as:
// Visit a point.
//  void operator () (Point& p) const
//  {
//  p.X(p.X()+m_dx);
//  p.Y(p.Y()+m_dy);
//  }
// In the main program, create an instance of the visitor and use the boost::apply_visitor(visitor, variant)
//  global function to move the shape.
// Print the shape afterwards to check if the visitor indeed changed the coordinates.


/*---------------------------------*/
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Visitor.hpp"
#include <iostream>
#include <boost/variant/static_visitor.hpp>

using namespace std;

/*---------------------------------*/
// Initializing (x,y) = (0,0)
Visitor::Visitor() : boost::static_visitor<void>(), m_dx(0), m_dy(0)
{
    cout << "Default visitor created" << endl;
}

// Initializing (x,y) = (newX,newY)
Visitor::Visitor(double newX, double newY) : boost::static_visitor<void>(), m_dx(newX), m_dy(newY)
{
    cout << "Visitor created." << endl;
}

// Copy Constructor: Initializing (x,y) = (newX,newY)
Visitor::Visitor(const Visitor& visitor) : boost::static_visitor<void>(), m_dx(visitor.m_dx), m_dy(visitor.m_dy)
{
    cout << "Copy constructor called." << endl;
}

// Destructor
Visitor::~Visitor()
{
    cout << "Visitor destroyed.\n";
}

// Assignment operator.
Visitor& Visitor::operator = (const Visitor& source)
{
    cout << "Assignment operator" << endl;
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }

    {
        // Call base class assignment
        Shape::operator= (source);

        m_dx = source.m_dx;
        m_dy = source.m_dy;

        return *this;  // Assign the result to itself
    }
}

// Overloading operators for point
void Visitor::operator() (Point& p) const
{
    // Accessing and assign coordinate of point p
    p.X(p.X() + m_dx);
    p.Y(p.Y() + m_dy);
}

// Overloading operators for line
void Visitor::operator() (Line& l) const
{

    Point p1 = l.P1();
    Point p2 = l.P2();

    // Accessing and assign coordinate of points
    p1.X(p1.X() + m_dx);
    p1.Y(p1.Y() + m_dy);

    p2.X(p2.X() + m_dx);
    p2.Y(p2.Y() + m_dy);

    // Assign line's start and end points
    l.P1(p1);
    l.P2(p2);
}

// Overloading operators for circle
void Visitor::operator() (Circle& c) const
{

    Point p = c.C();

    // Accessing and assign coordinate of points
    p.X(p.X() + m_dx);
    p.Y(p.Y() + m_dy);

    // Assign circle's center point
    c.C(p);
}