// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Definition file contains class NumericArray()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.


/*---------------------------------*/
#ifndef NumericArray_HPP
#define NumericArray_HPP

#include "Array.hpp"
#include <iostream>
using namespace std;

/*---------------------------------*/
template <typename T>
class NumericArray: public Array<T>
{
private:

public:
    // Constructors
    NumericArray();  // Default constructor
    NumericArray(int newSize);  // Initialize array with newSize number of elements
    NumericArray(const NumericArray<T>& numArray);  // Copy constructor

    // Destructor
    virtual ~NumericArray();

    // Accessing functions
    T DotProduct(const NumericArray<T>& numArray) const;  // Dot product of 2 numeric arrays

    // Overloading operators
    NumericArray<T>& operator = (const NumericArray& source); // Assignment operator.
    NumericArray<T> operator + (const NumericArray& numArray) const; // Addition operator.
    NumericArray<T> operator * (double factor) const; // Scale operator.

};

#endif // NumericArray_HPP