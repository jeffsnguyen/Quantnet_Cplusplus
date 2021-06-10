// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 2
// Description: Test file to test Shape() class.
// The ToString() function of the Shape class is overridden in the derived classes.
// But for the derived class it is still possible to use the base class functionality.
// In the ToString() function of Point and Line we also want to incorporate the ID from theShape base class.
//  •In the ToString() method of Point,
//      call the ToString() method of the Shape base class:std::string s=Shape::ToString();
//  •Append the shape description string to the point description string before returning.
//  •Do this also for the ToString() function in the Line class (and Circle class).
//  •Test the application again. Is now the ID printed when printing a point or line?

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

    // Test Point::ToString()
    Shape* sPoint = new Point(1,1);  // Create pointer to a shape variable.
    cout << (*sPoint).ToString() << endl;

    // Test Line::ToString()
    Point p1 = Point(1,1);
    Point p2 = Point(2,2);
    Shape* sLine = new Line(p1, p2);  // Create pointer to a shape variable.
    cout << (*sLine).ToString() << endl;

    // Test Circle::ToString()
    double d = p1.Distance(p2);
    Shape* sCircle = new Circle(p1, d);
    cout << (*sCircle).ToString() << endl;

    return 0;
}



