// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 1
// Description: Test file to test Shape() class.
// The ToString() functions of Point and Line override the ToString() from the Shape base class.
// We saw that we could put a Point in a Shape* variable.
// But when calling the ToString() method on the Shape* variable,
//  the function in Shape was called instead the one in Point.
//
//  To make the compiler generate the required code to find out
//      what type of object the Shape*variable is actually pointing to so it can call the right version;
//      we need to declare the function as virtual.
//  Thus declare the ToString() function in the Shape class as virtual
//      and test the program again.
//  Is the ToString() function of Point called when you use a Shape* that contains a Point now?

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
    Shape* sDefault = new Shape();  // Create default shape.
    cout << (*sDefault).ToString() << endl;

    // Test to see if Point's ToString is called
    Shape* sPoint = new Point(1,1);  // Create pointer to a shape variable.
    cout<< (*sPoint).ToString() << endl;

    // Test to see if Line's ToString is called
    Point p1 = Point(1,1);
    Point p2 = Point(2,2);
    Shape* sLine = new Line(p1, p2);  // Create pointer to a shape variable.
    cout<< (*sLine).ToString() << endl;

    // Conclusion: ToString() of Point still called.

    return 0;
}



