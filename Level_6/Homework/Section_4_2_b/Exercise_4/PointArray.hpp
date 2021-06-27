// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 4
// Description: Definition file contains class PointArray()
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
#ifndef PointArray_HPP
#define PointArray_HPP

#include "Array.hpp"
#include "Point.hpp"
#include <iostream>
using namespace std;

/*---------------------------------*/
class PointArray: public Array<Point>
{
private:

public:
    // Constructors
    PointArray();  // Default constructor
    PointArray(int newSize);  // Initialize array with newSize number of elements
    PointArray(const PointArray& pointArray);  // Copy constructor

    // Destructor
    virtual ~PointArray();

    // Accessing functions
    double Length() const;  // Total of length between points in the array

    // Overloading operators
    PointArray& operator = (const PointArray& source); // Assignment operator.

};

#endif // PointArray_HPP