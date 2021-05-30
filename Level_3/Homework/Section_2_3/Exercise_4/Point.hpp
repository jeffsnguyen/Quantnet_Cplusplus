// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 4
// Description: Definition file contains class Point()
// In the test program create a const point and try to set the x-coordinate:
//      const Point cp(1.5, 3.9);
//      cp.X(0.3);
//  Compile the program. Did you get a compiler error?
//  It should give a compiler error because you try to change a const object.
//
//  Now replace the line that changes the x-coordinate to code that reads the x-coordinate:
//      cout<<cp.X()<<endl;
//  Compile the program again.
//  You will see that is still gives a compiler error
//      even while retrieving the x-coordinate does not change the point object.
//  This is because the compiler does not know that the function does not change anything.
//  So we need to mark the x-coordinate getter as const by making it a const function.
//  Do this also for the y-coordinate getter and the Distance() and ToString() functions
//      because these don’t change the point object as well. Recompile the application.
//  It should now work.

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



#endif // Point_HPP