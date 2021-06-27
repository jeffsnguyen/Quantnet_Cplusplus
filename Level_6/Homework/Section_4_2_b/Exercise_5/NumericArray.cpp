// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 5
// Description: Source file contains functionalities for class NumericArray()
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