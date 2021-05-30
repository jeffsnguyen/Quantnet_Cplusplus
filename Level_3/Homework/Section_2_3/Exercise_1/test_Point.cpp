// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 1
// Description: Source file contains functionalities for class Point()
// In this exercise we are going to add extra constructors.
//  But first we do a little experiment.
//      In the Point class constructor and destructor, add some code that displays some text.
//      In the main program, make sure you use the Distance() function to calculate
//          the distance between two points. Run the program
//          and count how many times the constructor and destructor are called.
//  Are they the same?
//
//  Now add a copy constructor to the Point class that also displays some text.
//      Also add a constructor that accepts x- and y-coordinates so you
//          can create a point with the right values without using the set functions.
//      Use this constructor to create the point from the user input.
//      Run the program again and count the number of times the constructors and destructor are called.
//  Is the copy constructor called and is the number of constructor calls now the same
//      as the number of destructor calls?
//  We can derive two things from these results:
//      1. When calling the Distance() function, the input point is copied (call by value).
//      2. You will get the copy constructor 'for free' when you do not create one yourself.

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

    // FIRST QUESTION: Default Constructors were called twice, destructor three times.
    // SECOND QUESTION: Default Constructors called twice. Copy constructors called once. Destructors three times.
    //  The number of constructors called is now the same as that of destructors.

    return 0;
}



