// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 1
// Description: Definition file contains class Shape()
// The ToString() functions of Point and Line override the ToString() from the Shape base class.
// We saw that we could put a Point in a Shape* variable.
// But when calling the ToString() method on the Shape* variable,
//  the function in Shape was called instead the one in Point.
//
//  To make the compiler generate the required code to find out
//      what type of object the Shape*variable is actually pointing to so it can call the right version;
//      we need to declare the function as virtual.
//  Thus declare the ToString() function in the Shape class as virtual
//      and test the program again.
//  Is the ToString() function of Point called when you use a Shape* that contains a Point now?

/*---------------------------------*/
#ifndef Shape_HPP
#define Shape_HPP

#include <iostream>

using namespace std;

/*---------------------------------*/
class Shape
{
private:
    int m_id;  // ID of objects in the Shape() class

public:
    // Constructors
    Shape();  // Default constructor
    Shape(int newID);  // Initialize with specific value
    Shape(const Shape &shape);  // Copy constructor

    // Destructor
    virtual ~Shape();

    // Accessing functions
    int ID() const;  // Retrieving the ID
    void ID(int newID);  // Setting the ID

    virtual string ToString() const;  // Return string description of the shape

    // Overloading operators
    Shape &operator=(const Shape &source); // Assignment operator.
    friend ostream &operator<<(ostream &os, const Shape &s); // Send to ostream.
};

#endif // Shape_HPP