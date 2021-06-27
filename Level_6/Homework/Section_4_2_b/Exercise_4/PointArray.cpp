// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 4
// Description: Source file contains functionalities for class PointArray()
// In this exercise we will make a Stack class. For the data storage we can use the Array class.
// Deriving from Array is not a good idea because there is no relation between Array and Stack.
// The stack would then inherit indexed operations which should not be a functionality of a stack.
// But we can use the Array class as a data member as shown in Figure 4:
//  •Add a new source and header file for the Stack class to your project.
//  •Create a template class called Stack.
//      It is not a derived class but it uses an Array as data member.
//      You also need a data member for the current index in the array.
//  •Create the regular constructors, destructor and assignment operator.
//  •Add a Push() function.
//      It should store the element at the current position in the embedded array.
//      Increment the current position afterwards.
//      There is no need for checking the current index because the array
//          will throw an exception when the stack is full.
//      Make sure the current index is not changed when the Array class threw an exception.
//  •Add a Pop() function that decrements the current position
//      and then returns the element at that position.
//      Make sure the current index is not changed when the Array class throws an exception.
//  •Change the main function to test the stack.
// Using another class as data member is called composition.
// In this case the Stack class uses internally an Array class.
// Forwarding functionality to another class is called delegation.
// Here the Stack class delegates the storage of elements to the Array class.


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