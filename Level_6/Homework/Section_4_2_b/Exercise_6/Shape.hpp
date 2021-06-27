// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Definition file contains class Shape()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.


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
    //~Shape();

    // Accessing functions
    int ID() const;  // Retrieving the ID
    void ID(int newID);  // Setting the ID

    virtual string ToString() const;  // Return string description of the shape
    virtual void Draw() const = 0;  // Abstract function
    void Print() const;  // Template Method Pattern to Print derived class description via ToString()

    // Overloading operators
    Shape &operator=(const Shape &source); // Assignment operator.
    friend ostream &operator<<(ostream &os, const Shape &s); // Send to ostream.
};

#endif // Shape_HPP