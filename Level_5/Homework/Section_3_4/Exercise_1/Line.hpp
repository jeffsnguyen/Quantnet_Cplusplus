// Type: Homework
// Level: 5
// Section: 3.4 Simple Inheritance
// Exercise: 1
// Description: Definition file contains class Line()
// The colon syntax can improve the performance of constructors.
// To test this, make sure that you print some text in the point’s constructors, destructor
//  and also the assignment operator.
// Now, execute the following code in the test program
//  and count the number of point constructor, destructor and assignment calls:
//      Line l;
// Now, change the constructors in the Line class to use the colon syntax
//  to set the start- and end-point data members and run the test program again.
// Is the number of point constructor, destructor and assignment calls less than before?
// Apply the colon syntax also for the Point class constructors and if applicable also for the Circle class.

/*---------------------------------*/
#ifndef Line_HPP
#define Line_HPP

#include <iostream>
#include <Point.hpp>

using namespace std;

/*---------------------------------*/
class Line {
private:
    Point P1;  // point 1
    Point P2;  // point 2

public:
    // Constructors
    Line();  // Default constructor
    Line(Point &newP1, Point &newP2);  // Initialize with start and end points
    Line(const Line &line);  // Copy constructor

    // Destructor
    ~Line();

    // Accessing functions
    Point point1() const;  // The start point
    void point1(const Point &newP1);

    Point point2() const;  // The end point
    void point2(const Point &newP2);

    string ToString() const;  // Return string description of the line
    double Length() const;  // Calculate the length of the line

    // Overloading Operator
    Line &operator=(const Line &source); // Assignment operator.
    friend ostream &operator<<(ostream &os, const Line &l); // Send to ostream.
};

#endif // Line_HPP