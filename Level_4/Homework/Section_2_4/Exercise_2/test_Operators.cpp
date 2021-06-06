// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 2
// Description: Source file contains functionalities for class Circle()
// It would be nice if you could send a point or a line directly
//  to the cout object without calling the ToString() method,
//  just as with the primitive types.
// This is possible by adding a << operator function that has on the left an std::ostream
//  and on the right the point or line object.
// Since you can’t add a member function to the std::ostream class,
//  you have to create it as a global function
//  (outside the class definition, but inside the class header file):
//
//  ostream& operator << (ostream& os, const Point& p); // Send to ostream.
// The implementation uses the << operator to send data to the os input argument.
// Since it is a global function, you can’t access the private members of Point.
// To simplify things, you can use the ToString() method of Point to get the string to send to the os argument.
// Also create a similar << operator for printing lines (and circles if you made a circle class).
// Adapt the test program to test the << operator for points and lines.

/*---------------------------------*/
#include "Circle.hpp"
#include "Circle.cpp"
#include "Line.hpp"
#include "Line.cpp"
#include "Point.hpp"
#include "Point.cpp"
#include <iostream>
#include <sstream>

using namespace std;

/*---------------------------------*/
int main()
{
    // Declaring variables
    double x1, y1, x2, y2;

    // Prompt user input for points
    cout << "Enter first Point(x1,y1) coordinate. For example 1 3 for (1,3): ";
    cin >> x1 >> y1;
    cout << "Enter second Point(x2,y2) coordinate. For example 1 3 for (1,3): ";
    cin >> x2 >> y2;

    // Initialize points
    Point p1(x1,y1);
    Point p2(x2,y2);

    // Test overloaded ToString()
    cout << "Point 1 = " << p1 << endl;

    //Initializing Line
    Line l1(p1, p2);

    // Test overloaded ToString()
    cout << "Line 1 = " << l1 << endl;

    // Declaring radius variable and initialize it to be the length of l1
    double r = l1.Length();

    //Initializing Circle with center point p1 and radius r
    Circle c1(p1, r);

    // Test overloaded ToString()
    cout << "Circle 1 = " << c1 << endl;

    return 0;
}



