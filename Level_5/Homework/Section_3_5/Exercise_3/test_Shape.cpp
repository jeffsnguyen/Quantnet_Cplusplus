// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 3
// Description: Test file to test Shape() class.
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
    Shape* shapes[3];
    shapes[0]=new Shape;
    shapes[1]=new Point;
    shapes[2]=new Line;
    for (int i=0; i!=3; i++) delete shapes[i];

    // Result:
    // Non virtual destructor in Shape()
    // Shape constructors called 5 times, destroyed 3 times.
    // Point constructors called twice, destroyed 0 times.
    // Line constructors called once, destroyed 0 times.

    // Virtual destructor in Shape()
    // Shape constructors called 5 times, destroyed 5 times.
    // Point constructors called 3 times, destroyed 3 times.
    // Line constructors called once, destroyed once.
    // Corect number of constructors and destructors were called using virtual destructor.

    return 0;
}



