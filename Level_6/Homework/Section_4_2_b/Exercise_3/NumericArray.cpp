// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 3
// Description: Source file contains functionalities for class NumericArray()
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
#ifndef NumericArray_CPP
#define NumericArray_CPP

#include "Array.hpp"
#include "NumericArray.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing a default array derived from Array class
template <typename T>
NumericArray<T>::NumericArray(): Array<T>()
{
}

// Initialize array with newSize number of elements, derived from Array class
template <typename T>
NumericArray<T>::NumericArray(int newSize): Array<T>(newSize)
{
}

// Copy Constructor, derived from Array class
template <typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& numArray): Array<T>(numArray)
{
}

// Destructor
template <typename T>
NumericArray<T>::~NumericArray()
{
}

// Calculate the dot products of 2 numeric arrays
template <typename T>
T NumericArray<T>::DotProduct(const NumericArray<T>& numArray) const
{
    // Do the calculation only with same size arrays, else throw exception
    if ((*this).Size() == numArray.Size())
    {
        double res = 0;

        for (int idx=0; idx<(*this).Size(); idx++)  // Iterate through each index and add the products of each
        {
            res += (*this)[idx] * numArray[idx];
        }

        return res;
    }
    else
    {
        throw OutOfBoundsException();
    }
}

// Assignment operator.
template <typename T>
NumericArray<T>& NumericArray<T>::operator = (const NumericArray& source)
{
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        Array<T>::operator= (source);  // Call base class assignment

        return *this;  // Assign the result to itself
    }
}

// Add the array
template <typename T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray& numArray) const
{
    // Do the calculation only with same size arrays, else throw exception
    if ((*this).Size() == numArray.Size())
    {
        NumericArray<T> resArr = (*this);

        for (int idx=0; idx<resArr.Size(); idx++)  // Iterate through each index and add the products of each
        {
            resArr[idx] += numArray[idx];
        }

        return resArr;
    }
    else
    {
        throw OutOfBoundsException();
    }
}

// Scale the array
template <typename T>
NumericArray<T> NumericArray<T>::operator * (double factor) const
{
    NumericArray<T> resArr = (*this);  // Copy a temporary resArr to do computations

    // Iterate through the copied arr and multiply each index value  by factor
    for (int idx=0; idx<resArr.Size(); idx++)
    {
        resArr[idx] *= factor;
    }

    return resArr;
}

#endif // NumericArray_CPP