// Type: Homework
// Level: 4
// Section: 2.5 Namespaces
// Exercise: 1
// Description: Source file contains functionalities for class Circle()
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
#include "Circle.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
namespace Jeff
{
    namespace CAD
    {
        // Initializing Circle(C,r) = ((0,0),0)
        Circle::Circle(): C(0,0), r(0)
        {
            cout << "Default circle created" << endl;
        }

        // Initializing Circle(C,r) = Circle(C(newC), r(new_r))
        Circle::Circle(Point& newC, double new_r): C(newC), r(new_r)
        {
            cout << "Circle created." << endl;
        }

        // Copy Constructor: Initializing Line(line) = Line(point1,point2)
        Circle::Circle(const Circle& circle): C(circle.C), r(circle.r)
        {
            cout << "Circle Copy constructor called." << endl;
        }

        // Destructor
        Circle::~Circle()
        {
            cout << "Circle destroyed.\n";
        }

        // Get center point value
        Point Circle::centerP() const
        {
            return C;
        }

        // Set new value for center point
        void Circle::centerP(const Point& newC)
        {
            C = newC;
        }

        // Get radius value
        double Circle::rad() const
        {
            return r;
        }

        // Set new value for radius
        void Circle::rad(double new_r)
        {
            r = new_r;
        }

        // Return string description of the circle, overloading from Point class
        string Circle::ToString() const
        {
            // Declare stringstream objects
            stringstream rSTR;

            // Insert inputs to stream
            rSTR << r;

            return "Circle(" + C.ToString() + "," + rSTR.str() + ")";
        }

        // Calculate the length of the line
        double Circle::Diameter() const
        {
            return 2*r;
        }

        // Calculate the area of the circle
        double Circle::Area() const
        {
            return M_PI * pow(r,2);
        }

        // Calculate the circumference of the circle
        double Circle::Circumference() const
        {
            return 2 * M_PI * r;
        }

        // Assignment operator.
        Circle& Circle::operator = (const Circle& source)
        {
            // Self-assignment preclusion
            if (this == &source)
            {
                return *this;
            }
            else
            {
                C = source.C;
                r = source.r;

                return *this;  // Assign the result to itself
            }
        }

        // Send to ostream.
        ostream& operator << (ostream& os, const Circle& c)
        {
            os << c.ToString();  // Overloading ToString()

            return os;
        }
    }
}