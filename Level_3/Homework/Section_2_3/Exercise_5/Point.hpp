// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 5
// Description: Definition file contains class Point()
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
#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;

/*---------------------------------*/
class Point
{
private:
	double m_x;  // X coordinate
	double m_y;  // Y coordinate

public:
	// Constructors
	Point();  // Default constructor
	Point(double newX, double newY);  // Initialize with x and y value
    Point(const Point& point);  // Copy constructor

    // Destructor
	~Point();

	// Accessing functions
    double X() const;  // The x-coordinate
    void X(double newX);
    double Y() const;  // The y-coordinate
    void Y(double newY);
    string ToString() const;  // Return string description of the point
    double Distance() const; // Calculate the distance to the origin (0, 0).
    double Distance(const Point& p) const; // Calculate the distance between two points.
};



#endif // Point_PP