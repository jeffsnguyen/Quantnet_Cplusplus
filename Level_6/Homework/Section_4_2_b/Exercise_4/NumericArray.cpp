// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 4
// Description: Source file contains functionalities for class NumericArray()
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