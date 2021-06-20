// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 2
// Description: Source file contains functionalities for class NumericArray()
// With templates it is possible to call functionality on the template argument.
// But when you do this, you limit the types you can use as the template argument
//  because they have to support that functionality.
// Thus when adding numeric functionality to the Array class like calculating the sum,
//  you would limit the types possible as the template argument to types that support numeric operations.
//  It is better to leave the Array class as generic as possible so it can be used in various situations.
//  Numeric functionality can then be put in a derived class
//      which itself is also a template (generic inheritance) as shown in Figure 2.
// In this exercise we are going to create a NumericArray derived from Array.
//  •Add a new source- and header file for a NumericArray class to your project.
//  •Create a template class called NumericArray and derive it from the Array class using generic inheritance.
//  •Since they are not inherited, create proper constructors, destructor and
//      assignment operator and call the base class where appropriate.
//  •Add the following numeric functionality:
//      o An operator * to scale the elements of the numeric array by a factor.
//      o An operator + to add the elements of two numeric arrays.
//          Throw an exception if the two arrays have not the same size.
//      o A function to calculate the dot product. The dot product is defined as:
// Change the main program to test the numeric array.
// What assumptions do you make about the type used as template argument?
// Can you create a numeric array with Point objects?


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