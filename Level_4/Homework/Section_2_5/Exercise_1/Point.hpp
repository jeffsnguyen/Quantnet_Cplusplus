// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 4
// Description: Definition file contains class Point()
// Normally, only member functions of a class can access the private members of that class.
// Global functions and other classes can’t access the private members of that class.
// You can make an exception on that rule by declaring certain functions or classes as friend.
//
// For example the << operator for sending the point or line to the std::ostream class
//  had to be a global function and thus can’t access the private members.
// Move the << operator of Point and Line inside the class definition and declare it as friend.
// The function remains a global function but it can now access the data members directly
//  without the need for calling the getters or ToString() function.
//
//  Normally, friends are to be avoided because it violates the data hiding principle.
//  But in case of global operator functions it makes sense
//      because you would actually want to make those global operator functions as member function
//      but this was not possible.

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

    // Overloading operators
    Point operator - () const; // Negate the coordinates.
    Point operator * (double factor) const; // Scale the coordinates.
    Point operator + (const Point& p) const; // Add coordinates.
    bool operator == (const Point& p) const; // Equally compare operator.
    Point& operator = (const Point& source); // Assignment operator.
    Point& operator *= (double factor); // Scale the coordinates & assign.
    friend ostream& operator << (ostream& os, const Point& p); // Send to ostream.
};

#endif // Point_HPP