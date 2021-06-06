// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 3
// Description: Source file contains functionalities for class Circle()
// In this exercise we are going to do a little experiment.
//
// First add to the Point class a constructor that accepts one double as an argument.
// The implementation should set both the x- and y-coordinate to this value.
// Next try the following code in the test program:
//      Point p(1.0, 1.0);
//      if (p==1.0) cout<<"Equal!"<<endl;
//      else cout<<"Not equal"<<endl;
// Will this code compile and can you explain why?
// It turns out that the Point constructor with the single double argument
//  is implicitly used to convert the number in the if statement to a Point object.
// Thus constructors are used as implicit conversion operators.
//
// To prevent the usage of constructors are implicit conversion operators, declare the constructor as explicit:
//      explicit Point(double value);
// Now try to compile the program again and you will see that now the if statement gives a compiler error.
// You can still use the constructor as conversion operator but then explicitly:
//      if (p==(Point)1.0) cout<<"Equal!"<<endl;

/*---------------------------------*/
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

    //Point p(1.0, 1.0);
    //if (p==1.0) cout<<"Equal!"<<endl;
    //else cout<<"Not equal"<<endl;
    // Test 1: Implicit constructor
    // This code compile because it implicitly assume m_x=m_y=value

    //Point p(1.0, 1.0);
    //if (p==1.0) cout<<"Equal!"<<endl;
    //else cout<<"Not equal"<<endl;
    // Test 2: Explicit constructor
    // This code does not compiles: invalid operands to binary expression ("Point" and "double")

    Point p(1.0, 1.0);
    if (p==(Point)1.0) cout<<"Equal!"<<endl;
    else cout<<"Not equal"<<endl;
    // Test 3: Explicit constructor
    // This code does compiles.

    return 0;
}



