// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 4
// Description: Definition file contains class OutOfBoundsException()
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
#ifndef OutOfBoundsException_HPP
#define OutOfBoundsException_HPP

#include <iostream>
#include "ArrayException.hpp"

using namespace std;

/*---------------------------------*/
class OutOfBoundsException: public ArrayException // Override from ArrayException
{
private:
    int m_index;  // error index

public:
    // Constructors
    OutOfBoundsException(): m_index(0) {}; // Default constructor
    OutOfBoundsException(int new_m_idx): m_index(new_m_idx) {};
    OutOfBoundsException(const OutOfBoundsException& oobEx): m_index(oobEx.m_index) {};  // Copy constructor

    // Destructor
    virtual ~OutOfBoundsException() {};

    // Accessing functions
    string GetMessage() const
    {
        stringstream m_idxSTR;  // Declare stringstream objects
        m_idxSTR << m_index;  // Insert inputs to stream

        return "Index " + m_idxSTR.str() + " is out of bounds.";
    }

};

#endif // ArrayException_HPP