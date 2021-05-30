// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 2
// Description: Source file contains functionalities for class Point()
// In the previous exercise, you saw that the point passed to the Distance() method was copied.
//  Since creating a copy is unnecessary in this case,
//      change this function so that it passes the input point “by reference”
//      so that no copy is made.
//      Pass it as “const reference” to make it impossible to change the input point
//      from within the Distance() function.
//  Run the program again.
//  It should call the copy constructor fewer times than before.
//  Also test if you can change the input point in the Distance() function.
//  This should result in a compiler error.

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
    cout << "D[" << point1.ToString() << ", (0,0)] = " << point1.DistanceOrigin() << endl;

    // Print distance between point1 and point2
    cout << "D[" << point1.ToString() << ", " << point2.ToString() << "] = " << point1.Distance(point2) << endl;

    // Constructors called twice and so were destructors, vs. 3 times before.
    // Not able to change input point in Distance()

    return 0;
}



