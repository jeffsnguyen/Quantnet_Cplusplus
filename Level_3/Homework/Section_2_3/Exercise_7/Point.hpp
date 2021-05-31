// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 7
// Description: Definition file contains class Point()
// Inline functions can speed up the execution of short functions
//  because the code of such function will be copied in place instead of calling that function.
// Make the setters and getters of the Point class inline functions.
// Use normal inline (outside the class declaration) for the getters
//  and default inline (inside the class declaration) for the setters.
// Note that the implementation of the normal inline functions must be in the header file;
//  else they will not be inlined.

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

    // Default inline function for getters for X
    void X(const double& newX)
    {
        m_x = newX;
    };

    double Y() const;  // The y-coordinate

    // Default inline function for getters for Y
    void Y(const double& newY)
    {
        m_y = newY;
    };

    string ToString() const;  // Return string description of the point
    double Distance() const; // Calculate the distance to the origin (0, 0).
    double Distance(const Point& p) const; // Calculate the distance between two points.
};

/*---------------------------------*/
// Normal inline function for getters for X
inline double Point::X() const
{
    return m_x;
}

// Normal inline function for getters for Y
inline double Point::Y() const
{
    return m_y;
}

#endif // Point_HPP