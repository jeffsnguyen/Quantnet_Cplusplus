// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 6
// Description: Definition file contains class Circle()
// Create a Circle class.
// It has a center point and radius.
// Create the proper constructors, destructor, selector and modifier functions.
// Also add functions for getting the diameter, area and circumference.
// Don’t forget a ToString() function.
// In further exercises, all optimizations requested for Line
//  should also be implemented for Circle. See also Figure 4.
// Note that instead of using your own PI value,
//  Microsoft’s version of the math library defines a constant for PI named M_PI.
// But because it is not standard you need to enable that define
//  by setting the _USE_MATH_DEFINES symbol in the project settings or add before including “cmath”:
//  #define _USE_MATH_DEFINES

/*---------------------------------*/
#ifndef Circle_HPP
#define Circle_HPP

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES

#include <iostream>
#include <Point.hpp>
#include <cmath>

using namespace std;

/*---------------------------------*/
class Circle
{
private:
	Point C;  // point 1
	double r;  // point 2

public:
	// Constructors
	Circle();  // Default constructor
	Circle(Point& newC, double new_r);  // Initialize with center point and radius
    Circle(const Circle& circle);  // Copy constructor

    // Destructor
	~Circle();

	// Accessing functions
    Point centerP() const;  // The center point of the circle
    void centerP(const Point& newC);
    double rad() const;  // The radius
    void rad(const double new_r);
    string ToString() const;  // Return string description of the circle
    double Diameter() const;  // Calculate the diameter of the circle
    double Area() const;  // Calculate the area of the circle
    double Circumference() const;  // Calculate the circumference of the circle
};



#endif // Circle_HPP