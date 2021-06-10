// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 2
// Description: Definition file contains class Line()
// The ToString() function of the Shape class is overridden in the derived classes.
// But for the derived class it is still possible to use the base class functionality.
// In the ToString() function of Point and Line we also want to incorporate the ID from theShape base class.
//  •In the ToString() method of Point,
//      call the ToString() method of the Shape base class:std::string s=Shape::ToString();
//  •Append the shape description string to the point description string before returning.
//  •Do this also for the ToString() function in the Line class (and Circle class).
//  •Test the application again. Is now the ID printed when printing a point or line?

/*---------------------------------*/
#ifndef Line_HPP
#define Line_HPP

#include <iostream>
#include <Point.hpp>
#include <Shape.hpp>

using namespace std;

/*---------------------------------*/
class Line : public Shape
{
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

#endif // Line_HPP