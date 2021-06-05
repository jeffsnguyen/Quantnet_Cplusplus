// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 1
// Description: Source file contains functionalities for class Circle()
// By supporting operators, you can make your classes easier and more natural to use.
// However you must not “overuse” operators. Only use operators
//  if the functionality of the operator is clear without reading documentation.
// Thus adding mathematical operators to a complex number class is good
//  but using a + operator with a double as an argument on a point
//  to increase the x-coordinate is questionable. So use operators with care.
// In this exercise we add a few operators to the Point class.
// Most operators do not change the original objects but return the result as a new object.
// Normally only the = operator and += and variants change the original object. Add the following operators:
//
//  Point operator - () const; // Negate the coordinates.
//  Point operator * (double factor) const; // Scale the coordinates.
//  Point operator + (const Point& p) const; // Add coordinates.
//  bool operator == (const Point& p) const; // Equally compare operator.
//  Point& operator = (const Point& source); // Assignment operator.
//  Point& operator *= (double factor); // Scale the coordinates & assign.
//  Most operators above are self-explanatory.
//  The = and *= operator changes the current object so they can’t be const functions.
//  To make it possible to chain the = and *= operators (E.g.: a=b+=c),
//      it must return the “this” object.
//  Change the main program to test the operators.
//  Since the assignment operator is part of the canonical header file,
//      add this operator also to the Line and, if applicable, theCircle class.
//  Always be sure to preclude self-assignment inside your assignment operator functions.

/*---------------------------------*/
#include "Circle.hpp"
#include "Circle.cpp"
#include "Point.hpp"
#include "Point.cpp"
#include <iostream>
#include <sstream>

using namespace std;

/*---------------------------------*/
int main()
{
    // Testing Points
    /*---------------------------------*/
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

    // Point operator -
    cout << "Test: Testing - operator" << endl;
    Point pMinus = p1 + - p2;  // Expected: pMinus(x1-x2, y1-y2)
    cout << p1.ToString() << " - " << p2.ToString() << " = " << pMinus.ToString() << endl;

    // Point operator *
    cout << "Test: Testing * operator" << endl;
    Point pMultiply = p1 * 2;  // Expected: pMultiply(x1*2, x2*2)
    cout << p1.ToString() << " * " << 2 << " = " << pMultiply.ToString() << endl;

    // Point operator +
    cout << "Test: Testing + operator" << endl;
    Point pAdd = p1 + p2;  // Expected: pMinus(x1+x2, y1+y2)
    cout << p1.ToString() << " - " << p2.ToString() << " = " << pAdd.ToString() << endl;

    // Point operator ==
    cout << "Test: Testing == operator" << endl;
    bool compare = p1 == p2;  // Expected: 0 if different, 1 if similar
    cout << p1.ToString() << " == " << p2.ToString() << " : " << compare << endl;

    // Point operator =
    cout << "Test: Testing = operator" << endl;
    Point pAssign = p1;  // Expected: pAssign(x1, y1)
    cout << p1.ToString() << " = " << pAssign.ToString() << endl;

    // Point operator *=
    cout << "Test: Testing *= operator" << endl;
    pAssign *= 2;  // Expected: pAssign(x1*2, y1*2)
    cout << p1.ToString() << " * 2 = " << pAssign.ToString() << endl;

    return 0;
}



