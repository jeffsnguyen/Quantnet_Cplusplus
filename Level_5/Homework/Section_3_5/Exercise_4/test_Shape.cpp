// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 4
// Description: Test file to test Shape() class.
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
    // Test to see if default Shape's ToString() is called
    //Shape* sDefault = new Shape();  // Create default shape.
    //cout << (*sDefault).ToString() << endl;

    // Test Point::ToString()
    //Shape* sPoint = new Point(1,1);  // Create pointer to a shape variable.
    //cout << (*sPoint).ToString() << endl;

    // Test Line::ToString()
    //Point p1 = Point(1,1);
    //Point p2 = Point(2,2);
    //Shape* sLine = new Line(p1, p2);  // Create pointer to a shape variable.
    //cout << (*sLine).ToString() << endl;

    // Test Circle::ToString()
    //double d = p1.Distance(p2);
    //Shape* sCircle = new Circle(p1, d);
    //cout << (*sCircle).ToString() << endl;

    // Remarks:
    // 1. There is no implementation for Shape::Draw()
    // 2. Creating new instance of Shape() isn't possible:
    //    Error: Allocating an object of abstract class type 'Shape'

    return 0;
}



