// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 5
// Description: Definition file contains class NumericArray()
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