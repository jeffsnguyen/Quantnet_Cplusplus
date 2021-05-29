// Type: Homework
// Level: 3
// Section: 2.2 The Class Concept
// Exercise: 1
// Description: Source file contains functionalities for class Point()
// First add a header file for the Point class with private members for the x- and y-coordinates.
//  Do not forget to add the #ifndef/#define/#endif statements to avoid multiple inclusion.
//  Also make sure you make to following public functionality (see also Figure 1):
//      • Default constructor.
//      • Destructor.
//      • Getter functions for the x- and y-coordinates (GetX() and GetY() functions).
//      • Setter functions for the x- and y-coordinates (SetX() and SetY() functions).
//      • A ToString() that returns a string description of the point. Use the std::string class as return type.
//  Next create the source file that implements the Point class defined in the header file.
//  The source file must include the header file.
//  Making the string in the ToString() function, requires conversion of the double coordinates to a string.
//  Easiest is to use a std::stringstream object
//      and the standard stream operators (as with iostream) to create the string.
//      This requires the “sstream” header file.
//      Use the str() function to retrieve the string from the string buffer.
//      The output can be like: “Point(1.5, 3.9)”

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
    double x,y;

    // Prompt user input
    cout << "Enter (x,y) coordinate. For example 1 3 for (1,3): ";
    cin >> x >> y;

    // Create point1 object using default constructor
    Point point1(x,y);

    // Setting x,y coordinates of point1 based on user input
    point1.SetX(x);
    point1.SetY(y);

    // Print description of the point using ToString()
    cout << "[ToString] User entered: " << point1.ToString() << endl;

    // Print description of the point using GetX and GetY
    cout << "[Get] User entered: Point(" << point1.GetX() << "," << point1.GetY() << ")" << endl;

    return 0;
}



