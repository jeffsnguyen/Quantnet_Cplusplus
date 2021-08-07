// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Source file contains functionalities for class PointArray()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.

/*---------------------------------*/
#ifndef PointArray_CPP
#define PointArray_CPP

#include "Array.hpp"
#include "PointArray.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing a default array derived from Array class
PointArray::PointArray(): Array<Point>()
{
}

// Initialize array with newSize number of elements, derived from Array class
PointArray::PointArray(int newSize): Array<Point>(newSize)
{
}

// Copy Constructor, derived from Array class
PointArray::PointArray(const PointArray& pointArray): Array<Point>(pointArray)
{
}

// Destructor
PointArray::~PointArray()
{
}

// Calculate total of length between points in the array
// Using 2 for loops to iterate through points corresponded to array index to select 2 points of reference
//  for length calculate using Point class distance function
double PointArray::Length() const
{
    double res = 0;

    // Outer loop iterate through each index in the array and use them as 1st point of reference
    for (int idxOuter=0; idxOuter<(*this).Size(); idxOuter++)
    {
        // Inner loop iterate through the next index in the array and use them as 2nd point of reference
        for (int idxInner=idxOuter+1; idxInner<(*this).Size(); idxInner++)
        {
            res += (*this)[idxOuter].Distance((*this)[idxInner]);
        }
    }

    return res;
}

// Assignment operator.
PointArray& PointArray::operator = (const PointArray& source)
{
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        Array<Point>::operator= (source);  // Call base class assignment

        return *this;  // Assign the result to itself
    }
}

#endif // PointArray_CPP