// Type: Homework
// Level: 4
// Section: 2.5 Namespaces
// Exercise: 1
// Description: Definition file contains class Circle()
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
#ifndef Circle_HPP
#define Circle_HPP

#define _USE_MATH_DEFINES

#include <iostream>
#include <Point.hpp>
#include <cmath>

using namespace std;

/*---------------------------------*/
namespace Jeff
{
    namespace CAD
    {
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

            // Overloading operator
            Circle& operator = (const Circle& source); // Assignment operator.
        };

        ostream& operator << (ostream& os, const Circle& c); // Send to ostream.
    }
}

#endif // Circle_HPP