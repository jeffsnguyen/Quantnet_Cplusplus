// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 4
// Description: Definition file contains class Shape()
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
#ifndef Shape_HPP
#define Shape_HPP

#include <iostream>

using namespace std;

/*---------------------------------*/
class Shape
{
private:
    int m_id;  // ID of objects in the Shape() class

public:
    // Constructors
    Shape();  // Default constructor
    Shape(int newID);  // Initialize with specific value
    Shape(const Shape &shape);  // Copy constructor

    // Destructor
    virtual ~Shape();
    //~Shape();

    // Accessing functions
    int ID() const;  // Retrieving the ID
    void ID(int newID);  // Setting the ID

    virtual string ToString() const;  // Return string description of the shape
    virtual void Draw() const = 0;  // Abstract function

    // Overloading operators
    Shape &operator=(const Shape &source); // Assignment operator.
    friend ostream &operator<<(ostream &os, const Shape &s); // Send to ostream.
};

#endif // Shape_HPP