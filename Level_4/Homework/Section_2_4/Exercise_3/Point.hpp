// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 3
// Description: Definition file contains class Point()
// In this exercise we are going to do a little experiment.
//
// First add to the Point class a constructor that accepts one double as an argument.
// The implementation should set both the x- and y-coordinate to this value.
// Next try the following code in the test program:
//      Point p(1.0, 1.0);
//      if (p==1.0) cout<<"Equal!"<<endl;
//      else cout<<"Not equal"<<endl;
// Will this code compile and can you explain why?
// It turns out that the Point constructor with the single double argument
//  is implicitly used to convert the number in the if statement to a Point object.
// Thus constructors are used as implicit conversion operators.
//
// To prevent the usage of constructors are implicit conversion operators, declare the constructor as explicit:
//      explicit Point(double value);
// Now try to compile the program again and you will see that now the if statement gives a compiler error.
// You can still use the constructor as conversion operator but then explicitly:
//      if (p==(Point)1.0) cout<<"Equal!"<<endl;

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
    //Point(double value);  // Implicit constructor
    explicit Point(double value);  // Explicit constructor

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

    // Overloading operators
    Point operator - () const; // Negate the coordinates.
    Point operator * (double factor) const; // Scale the coordinates.
    Point operator + (const Point& p) const; // Add coordinates.
    bool operator == (const Point& p) const; // Equally compare operator.
    Point& operator = (const Point& source); // Assignment operator.
    Point& operator *= (double factor); // Scale the coordinates & assign.
};

ostream& operator << (ostream& os, const Point& p); // Send to ostream.

#endif // Point_HPP