// Type: Homework
// Level: 4
// Section: 2.5 Namespaces
// Exercise: 1
// Description: Source file contains functionalities for class Line()
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
#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
namespace Jeff {
    namespace CAD {
        // Initializing (x,y) = (0,0)
        Line::Line() : P1(0, 0), P2(0, 0) {
            cout << "Default line created" << endl;
        }

        // Initializing Line(p1,p2) = Line(Point(newX1, newY1), Point(newX2, newY2))
        Line::Line(Point &newP1, Point &newP2) : P1(newP1), P2(newP2) {
            cout << "Line created." << endl;
        }

        // Copy Constructor: Initializing Line(line) = Line(point1,point2)
        Line::Line(const Line &line) : P1(line.P1), P2(line.P2) {
            cout << "Line Copy constructor called." << endl;
        }

        // Destructor
        Line::~Line() {
            cout << "Line destroyed.\n";
        }

        // Get P1 value
        Point Line::point1() const {
            return P1;
        }

        // Set new value for P1
        void Line::point1(const Point &newP1) {
            P1 = newP1;
        }

        // Get P2 value
        Point Line::point2() const {
            return P2;
        }

        // Set new value for P2
        void Line::point2(const Point &newP2) {
            P2 = newP2;
        }

        // Return string description of the line, overloading from Point class
        string Line::ToString() const {
            return "Line(" + P1.ToString() + "," + P2.ToString() + ")";
        }

        // Calculate the length of the line
        double Line::Length() const {
            return P1.Distance(P2);
        }

        // Assignment operator.
        Line &Line::operator=(const Line &source) {
            // Self-assignment preclusion
            if (this == &source) {
                return *this;
            } else {
                P1 = source.P1;
                P2 = source.P2;

                return *this;
            }
        }

        // Send to ostream.
        ostream &operator<<(ostream &os, const Line &l) {
            os << "Line(" << l.P1 << "," << l.P2 << ")";  // // Access private members

            return os;
        }
    }
}