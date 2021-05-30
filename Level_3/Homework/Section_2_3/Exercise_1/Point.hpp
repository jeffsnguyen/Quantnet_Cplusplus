// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 1
// Description: Definition file contains class Point()
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
    double GetX() const;  // The x-coordinate
    void SetX(double newX);
    double GetY() const;  // The y-coordinate
    void SetY(double newY);
    string ToString() const;  // Return string description of the point
    double DistanceOrigin() const; // Calculate the distance to the origin (0, 0).
    double Distance(Point p) const; // Calculate the distance between two points.
};



#endif // Point_PP