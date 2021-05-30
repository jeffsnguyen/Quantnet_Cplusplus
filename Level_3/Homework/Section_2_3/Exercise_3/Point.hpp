// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 3
// Description: Definition file contains class Point()
// Previously you saw that there could be more than one constructor
//  as long as the input arguments are different.
// You can do the same for normal member functions.
// Thus you can rename the DistanceOrigin() function to Distance().
// Also you can rename the SetX() andGetX() functions to just X().
// The same is true for the setter and getter of the y-coordinate.

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