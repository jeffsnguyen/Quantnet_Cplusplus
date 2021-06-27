// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 5
// Description: Source file contains functionalities for class PointArray()
// When you use the Stack class and the stack is full or empty
//  when pushing or popping an element you get an exception from the Array class.
// Since the user of the Stack class does not know that an Array class is used internally,
//  you don’t want that the client must know about the array exceptions.
// Thus the array exception must be translated to a stack exception.
//  •The stack exception classes can be implemented in a header file only for simplicity.
//  •Create a StackException base class anda StackFullException and StackEmptyException derived class.
//  •In the Push() function of stack, place the code in a try ... catch block and catch the array exception.
//      In the catch handler, throw a StackFullException exception.
//  •In the Pop() function of stack, place the code in a try ... catch block and catch the array exception.
//      In the catch handler, throw a StackEmptyException exception.
//      Also set the current index back to 0.
//  •Change the test program so it catches the stack exception.

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