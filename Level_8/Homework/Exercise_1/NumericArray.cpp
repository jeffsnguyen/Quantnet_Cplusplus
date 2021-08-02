// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Source file contains functionalities for class NumericArray()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.


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