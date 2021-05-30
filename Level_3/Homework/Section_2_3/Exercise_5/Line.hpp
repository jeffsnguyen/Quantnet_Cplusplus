// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 5
// Description: Definition file contains class Line()
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
#ifndef Line_HPP
#define Line_HPP

#include <iostream>
#include <Point.hpp>

using namespace std;

/*---------------------------------*/
class Line
{
private:
	Point P1;  // point 1
	Point P2;  // point 2

public:
	// Constructors
	Line();  // Default constructor
	Line(Point& newP1, Point& newP2);  // Initialize with start and end points
    Line(const Line& line);  // Copy constructor

    // Destructor
	~Line();

	// Accessing functions
    Point point1() const;  // The start point
    void point1(const Point& newP1);
    Point point2() const;  // The end point
    void point2(const Point& newP2);
    string ToString() const;  // Return string description of the line
    double Length() const;  // Calculate the length of the line
};



#endif // Line_HPP