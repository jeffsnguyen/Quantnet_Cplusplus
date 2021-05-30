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
    double x1,y1,x2,y2;

    // Prompt user input for point1
    cout << "Enter point1(x,y) coordinate. For example 1 3 for (1,3): ";
    cin >> x1 >> y1;

    // Prompt user input for point2
    cout << "Enter point2(x,y) coordinate. For example 1 3 for (1,3): ";
    cin >> x2 >> y2;

    // Create points and line object using default constructor
    Point startPoint(x1,y1);
    Point endPoint(x2,y2);
    Line line1(startPoint, endPoint);

    // Setting point1 based on user input using setter
    line1.point1(startPoint);
    line1.point2(endPoint);

    // Print description of the line using ToString()
    cout << "[ToString] User entered: " << line1.ToString() << endl;

    // Print description of the line using getters point1 and point2
    cout << "[Get] User entered: Line(" << line1.point1().ToString()
        << "," << line1.point2().ToString() << ")" << endl;

    // Print length of line
    cout << "Length[" << line1.ToString() << "] = " << line1.Length() << endl;


    return 0;
}



