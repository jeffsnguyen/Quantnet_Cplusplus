// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Definition file contains class PointArray()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.


/*---------------------------------*/
#ifndef PointArray_HPP
#define PointArray_HPP

#include "Array.hpp"
#include "Point.hpp"
#include <iostream>
using namespace std;

/*---------------------------------*/
class PointArray: public Array<Point>
{
private:

public:
    // Constructors
    PointArray();  // Default constructor
    PointArray(int newSize);  // Initialize array with newSize number of elements
    PointArray(const PointArray& pointArray);  // Copy constructor

    // Destructor
    virtual ~PointArray();

    // Accessing functions
    double Length() const;  // Total of length between points in the array

    // Overloading operators
    PointArray& operator = (const PointArray& source); // Assignment operator.

};

#endif // PointArray_HPP