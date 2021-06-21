// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 3
// Description: Source file contains functionalities for class PointArray()
// You can create an array of points by directly instantiating the Array class for the Point class.
// This works well but we can’t add points specific functionality to the Array class in this way.
// A solution is to create a derived class
//  of which the template argument is fixed to a specific type (concrete inheritance) as shown in Figure 3.
// In this exercise we will create a PointArray which is derived from Array with the template argument set to Point.
//  •Add a new source- and header file for the PointArray class to your project.
//  •Create a regular class called PointArray which is derived from Array.
//      The template argument given to Array is Point.
//  •Since they are not inherited, create proper constructors, destructor
//      and assignment operator and call the base class where appropriate.
//  •Now we can add functionality specific for a point array.
//      For example add a Length()function that returns the total length between the points in the array.
//  •Change the main program to test the point array.


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