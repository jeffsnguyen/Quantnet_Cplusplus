// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 2
// Description: Definition file contains class Point()
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
    double Distance(const Point& p) const; // Calculate the distance between two points.
};



#endif // Point_HPP