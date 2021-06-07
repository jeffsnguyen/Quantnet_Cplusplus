// Type: Homework
// Level: 4
// Section: 2.5 Namespaces
// Exercise: 1
// Description: Definition file contains class Point()
// To avoid name conflicts, programmers can place their classes in a namespace.
// For example the standard library is placed in a namespace called std.
// You should put your classes in your own namespace.
// Thus place the CAD classes (Shape,Point, Line, etc) in the namespace:
//  YourName::CAD
// Place the container classes (Array) in the namespace:
//  YourName::Containers Now access the classes in your own namespace using:
//  • Full class name including namespace for the Point used in the Array class.
//      Note that you can use only the CAD part of the namespace
//      without the YourName part because the Point is also in the YourName namespace.
//  • In the main program, the full namespace for Point class.
//  • In the main program, using declaration for using a single class (Line).
//  • In the main program, using declaration for a complete namespace (Containers).
//  • In the main program, using the Circle class by creating a shorter alias for the YourName::CAD namespace.

/*---------------------------------*/
#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;

/*---------------------------------*/
namespace Jeff {
    namespace CAD {
        class Point {
        private:
            double m_x;  // X coordinate
            double m_y;  // Y coordinate

        public:
            // Constructors
            Point();  // Default constructor
            Point(double newX, double newY);  // Initialize with x and y value
            Point(const Point &point);  // Copy constructor

            // Destructor
            ~Point();

            // Accessing functions
            double X() const;  // The x-coordinate
            void X(double newX);

            double Y() const;  // The y-coordinate
            void Y(double newY);

            string ToString() const;  // Return string description of the point
            double Distance() const; // Calculate the distance to the origin (0, 0).
            double Distance(const Point &p) const; // Calculate the distance between two points.

            // Overloading operators
            Point operator-() const; // Negate the coordinates.
            Point operator*(double factor) const; // Scale the coordinates.
            Point operator+(const Point &p) const; // Add coordinates.
            bool operator==(const Point &p) const; // Equally compare operator.
            Point &operator=(const Point &source); // Assignment operator.
            Point &operator*=(double factor); // Scale the coordinates & assign.
            friend ostream &operator<<(ostream &os, const Point &p); // Send to ostream.
        };
    }
}

#endif // Point_HPP