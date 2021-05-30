// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 3
// Description: Source file contains functionalities for class Point()
// Previously you saw that there could be more than one constructor
//  as long as the input arguments are different.
// You can do the same for normal member functions.
// Thus you can rename the DistanceOrigin() function to Distance().
// Also you can rename the SetX() andGetX() functions to just X().
// The same is true for the setter and getter of the y-coordinate.

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



