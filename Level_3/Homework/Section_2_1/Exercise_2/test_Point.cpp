// Type: Homework
// Level: 3
// Section: 2.2 The Class Concept
// Exercise: 2
// Description: Source file contains functionalities for class Point()
// In this exercise we are going to add distance functions to the Point class.
//  The distance functions have the following signature:
//      double DistanceOrigin(); // Calculate the distance to the origin (0, 0).
//      double Distance(Point p); // Calculate the distance between two points.
//  Add the definitions to the header file and implement the functions in the source file.
//  Use the std::sqrt() function from the “cmath” header file to implement the Pythagoras algorithm.
//  Extend the main program to print the distance between the origin and another point and test it.

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
    point1.SetX(x1);
    point1.SetY(y1);

    // Print description of the point using ToString()
    cout << "[ToString] User entered: " << point1.ToString() << endl;

    // Print description of the point using GetX and GetY
    cout << "[Get] User entered: Point(" << point1.GetX() << "," << point1.GetY() << ")" << endl;

    // Print distance between point1 and the origin
    cout << "D[Point(" << point1.GetX() << "," << point1.GetY() << "), (0,0)] = "
        << point1.DistanceOrigin() << endl;

    // Print distance between point1 and point2
    cout << "D[Point(" << point1.GetX() << "," << point1.GetY() <<
        "), Point(" <<point2.GetX() << "," << point2.GetY() << ") = " << point1.Distance(point2) << endl;

    return 0;
}



