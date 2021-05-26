// Type: Homework
// Level: 3
// Section: 2.1 The Class Concept
// Exercise: 1
// Description: Definition file contains class Point()
// First add a header file for the Point class with private members for the x- and y-coordinates.
//  Do not forget to add the #ifndef/#define/#endif statements to avoid multiple inclusion.
//  Also make sure you make to following public functionality (see also Figure 1):
//      • Default constructor.
//      • Destructor.
//      • Getter functions for the x- and y-coordinates (GetX() and GetY() functions).
//      • Settter functions for the x- and y-coordinates (SetX() and SetY() functions).
//      • A ToString() that returns a string description of the point. Use the std::string class as return type.
//  Next create the source file that implements the Point class defined in the header file.
//  The source file must include the header file.
//  Making the string in the ToString() function, requires conversion of the double coordinates to a string.
//  Easiest is to use a std::stringstream object
//      and the standard stream operators (as with iostream) to create the string.
//      This requires the “sstream” header file.
//      Use the str() function to retrieve the string from the string buffer.
//      The output can be like: “Point(1.5, 3.9)”

#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;



class Point
{
private:
	double x;	// X coordinate
	double y;	// Y coordinate

public:
	// Constructors
	Point();								// Default constructor
	Point(double xval, double yval);		// Initialize with x and y value
	
	~Point();

	// Accessing functions
	double X() const ;					// The x-coordinate
	void X(double newX);
	double Y() const;					// The y-coordinate
	void Y(double newY);
};



#endif // Point_HXX

// V2
// Accessing functions
	/*double getX() const;					// The x-coordinate
	void setX(double newX);
	double getY() const;					// The y-coordinate
	void setY(double newY);

	double Distance(const Point& pt) const;
	Point Add(const Point& pt) const;*/