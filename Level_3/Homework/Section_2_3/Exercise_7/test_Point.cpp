// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 7
// Description: Source file contains functionalities for class Point()
// Inline functions can speed up the execution of short functions
//  because the code of such function will be copied in place instead of calling that function.
// Make the setters and getters of the Point class inline functions.
// Use normal inline (outside the class declaration) for the getters
//  and default inline (inside the class declaration) for the setters.
// Note that the implementation of the normal inline functions must be in the header file;
//  else they will not be inlined.

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
    double x1,y1,x2,y2;

    // Prompt user input for point1
    cout << "Enter point1(x,y) coordinate. For example 1 3 for (1,3): ";
    cin >> x1 >> y1;

    // Prompt user input for point2
    cout << "Enter point2(x,y) coordinate. For example 1 3 for (1,3): ";
    cin >> x2 >> y2;

    // Create point1 object using default constructor
    Point point1(x1,y1);
    Point point2(x2,y2);

    // Setting x,y coordinates of point1 based on user input
    point1.X(x1);
    point1.Y(y1);

    // Print description of the point using ToString()
    cout << "[ToString] User entered: " << point1.ToString() << endl;

    // Print description of the point using GetX and GetY
    cout << "[Get] User entered: Point(" << point1.X() << "," << point1.Y() << ")" << endl;

    // Print distance between point1 and the origin
    cout << "D[" << point1.ToString() << ", (0,0)] = " << point1.Distance() << endl;

    // Print distance between point1 and point2
    cout << "D[" << point1.ToString() << ", " << point2.ToString() << "] = " << point1.Distance(point2) << endl;

    return 0;
}



