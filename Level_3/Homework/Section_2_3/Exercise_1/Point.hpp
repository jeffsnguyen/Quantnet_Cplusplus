// Type: Homework
// Level: 3
// Section: 2.2 The Class Concept
// Exercise: 2
// Description: Definition file contains class Point()
// In this exercise we are going to add distance functions to the Point class.
// The distance functions have the following signature:
//      double DistanceOrigin(); // Calculate the distance to the origin (0, 0).
//      double Distance(Point p); // Calculate the distance between two points.
//  Add the definitions to the header file and implement the functions in the source file.
//  Use the std::sqrt() function from the “cmath” header file to implement the Pythagoras algorithm.
//  Extend the main program to print the distance between the origin and another point and test it.

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
    Point(const Point& point);

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