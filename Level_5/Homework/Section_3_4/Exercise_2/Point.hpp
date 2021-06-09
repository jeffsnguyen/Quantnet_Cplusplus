// Type: Homework
// Level: 5
// Section: 3.4 Simple Inheritance
// Exercise: 2
// Description: Definition file contains class Point()
// It can be useful to create a hierarchy of related classes using base- and derived classes.
//  •Classes are related (same family)
//  •Common data and functionality can be put in a base class.
//  •You can work with derived classes as if it is the base class.
// In this exercise we are going to transform the Point and Line class into a Shape hierarchy as shown in Figure 1.
// First create a Shape base class.
//  •Add a source- and header file for a Shape class.
//  •Add a data member for an id number of type int.
//  •Add a default constructor that initializes the id using a random number.
//      You can usethe rand() function from the “stdlib.h” header file.
//  •Add a copy constructor that copies the id member.
//  •Add an assignment operator that copies the id member.
//  •Add a ToString() function that returns the id as string e.g. “ID: 123”.
//  •Add an ID() function the retrieve the id of the shape.
// Next the Point and Line classes (and the Circle class if applicable) must derive from Shape.
//  •Add the Shape class in the inheritance list of the Point, Line and optionallythe Circle class.
//  •The constructors of the Point, Line and optionally the Circle class
//      should call theappropriate constructor in the Shapebase class.
//  •The assignment operator should call the assignment operator of the Shape baseclass.
//      Otherwise the shape data will not be copied.
//  •Finally add code to the main program to test inheritance:
//      Shape s;// Create shape.
//      Point p(10, 20);// Create point.
//      Line l(Point(1,2), Point(3, 4)); // Create line.
//
//      cout<<s.ToString()<<endl;// Print shape.
//      cout<<p.ToString()<<endl;// Print point.
//      cout<<l.ToString()<<endl;// Print line
//
//      cout<<"Shape ID: "<<s.ID()<<endl; // ID of the shape.
//      cout<<"Point ID: "<<p.ID()<<endl; // ID of the point. Does this work?
//      cout<<"Line ID: "<<l.ID()<<endl; // ID of the line. Does this work?
//
//      Shape* sp; // Create pointer to a shape variable.
//      sp=&p; // Point in a shape variable. Possible?
//      cout<<sp->ToString()<<endl;// What is printed?
//
//      //Create and copy Point p to new point.
//      Point p2;
//      p2=p;
//      cout<<p2<<", "<<p2.ID()<<endl; // Is the ID copied if you do not call
//      //the base class assignment in point?
//      Answer the questions in the comments of the code above.

/*---------------------------------*/
#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;

/*---------------------------------*/
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

#endif // Point_HPP