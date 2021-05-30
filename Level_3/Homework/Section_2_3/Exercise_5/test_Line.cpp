// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 5
// Description: Source file contains functionalities for class Line()
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



