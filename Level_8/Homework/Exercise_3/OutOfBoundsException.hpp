// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Definition file contains class OutOfBoundsException()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.

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