// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 6
// Description: Source file contains functionalities for class Circle()
// Create a Circle class.
// It has a center point and radius.
// Create the proper constructors, destructor, selector and modifier functions.
// Also add functions for getting the diameter, area and circumference.
// Don’t forget a ToString() function.
// In further exercises, all optimizations requested for Line
//  should also be implemented for Circle. See also Figure 4.
// Note that instead of using your own PI value,
//  Microsoft’s version of the math library defines a constant for PI named M_PI.
// But because it is not standard you need to enable that define
//  by setting the _USE_MATH_DEFINES symbol in the project settings or add before including “cmath”:
//  #define _USE_MATH_DEFINES

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
    // Declaring variables
    double x, y, r;

    // Prompt user input for center point of the circle
    cout << "Enter centerPoint(x,y) coordinate. For example 1 3 for (1,3): ";
    cin >> x >> y;

    // Prompt user input for radius of the circle
    cout << "Enter radius: ";
    cin >> r;

    // Create circle object using default constructor
    Point centerPoint(x,y);
    Circle circle1(centerPoint, r);

    // Print description of the circle using ToString()
    cout << "[ToString] User entered: " << circle1.ToString() << endl;

    // Print Diameter of circle
    cout << "Diameter[" << circle1.ToString() << "] = " << circle1.Diameter() << endl;

    // Print Diameter of circle
    cout << "Area[" << circle1.ToString() << "] = " << circle1.Area() << endl;

    // Print Diameter of circle
    cout << "Circumference[" << circle1.ToString() << "] = " << circle1.Circumference() << endl;

    return 0;
}



