// Type: Homework
// Level: 4
// Section: 2.5 Namespaces
// Exercise: 1
// Description: Definition file contains class Line()
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
#ifndef Line_HPP
#define Line_HPP

#include <iostream>
#include <Point.hpp>

using namespace std;

/*---------------------------------*/
namespace Jeff {
    namespace CAD {
        class Line {
        private:
            Point P1;  // point 1
            Point P2;  // point 2

        public:
            // Constructors
            Line();  // Default constructor
            Line(Point &newP1, Point &newP2);  // Initialize with start and end points
            Line(const Line &line);  // Copy constructor

            // Destructor
            ~Line();

            // Accessing functions
            Point point1() const;  // The start point
            void point1(const Point &newP1);

            Point point2() const;  // The end point
            void point2(const Point &newP2);

            string ToString() const;  // Return string description of the line
            double Length() const;  // Calculate the length of the line

            // Overloading Operator
            Line &operator=(const Line &source); // Assignment operator.
            friend ostream &operator<<(ostream &os, const Line &l); // Send to ostream.
        };
    }
}


#endif // Line_HPP