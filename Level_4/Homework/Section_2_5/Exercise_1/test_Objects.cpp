// Type: Homework
// Level: 4
// Section: 2.5 The Free Store
// Exercise: 1
// Description: Test file to test objects
// Normally, only member functions of a class can access the private members of that class.
// Global functions and other classes can’t access the private members of that class.
// You can make an exception on that rule by declaring certain functions or classes as friend.
//
// For example the << operator for sending the point or line to the std::ostream class
//  had to be a global function and thus can’t access the private members.
// Move the << operator of Point and Line inside the class definition and declare it as friend.
// The function remains a global function but it can now access the data members directly
//  without the need for calling the getters or ToString() function.
//
//  Normally, friends are to be avoided because it violates the data hiding principle.
//  But in case of global operator functions it makes sense
//      because you would actually want to make those global operator functions as member function
//      but this was not possible.

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
    double x1, y1, x2, y2;

    // Prompt user input for points
    cout << "Enter first Point(x1,y1) coordinate. For example 1 3 for (1,3): ";
    cin >> x1 >> y1;
    cout << "Enter second Point(x2,y2) coordinate. For example 1 3 for (1,3): ";
    cin >> x2 >> y2;

    // Initialize points
    Point p1(x1,y1);
    Point p2(x2,y2);

    // Test overloaded friend function
    cout << "Point 1 = " << p1 << endl;

    //Initializing Line
    Line l1(p1, p2);

    // Test overloaded friend function
    cout << "Line 1 = " << l1 << endl;


    return 0;
}



