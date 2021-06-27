// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 5
// Description: Definition file contains class OutOfBoundsException()
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