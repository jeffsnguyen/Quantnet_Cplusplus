// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 5
// Description: Source file contains functionalities for class Point()
// In the final exercise for this chapter we are going to create a Line class.
// The Line class has a start- and an end-point. So the Line class should have two Point objects as data members.
// This mechanism is called “composition”. See also Figure 3. Give the Line class the following functionality:
//  • Default constructor (set the points to 0, 0).
//  • Constructor with a start- and end-point.
//  • Copy constructor.
//  • Destructor.
//  • Overloaded getters for the start- and end-point.
//  • Overloaded setters for the start- and end-point.
//  • A ToString() function that returns a description of the line.
//  • A Length() function that returns the length of the line.
//      Note that you can use the distance function on the embeddedPoint objects to calculate the length.
//      This mechanism is called “delegation”.
//  Use const arguments, const functions and pass objects by reference where applicable.

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

    // Constructors called twice and so were destructors, vs. 3 times before.
    // Not able to change input point in Distance()

    return 0;
}



