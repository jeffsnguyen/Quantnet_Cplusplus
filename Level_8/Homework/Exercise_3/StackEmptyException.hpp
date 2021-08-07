// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Definition file contains class StackEmptyException()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.

/*---------------------------------*/
#ifndef StackEmptyException_HPP
#define StackEmptyException_HPP

#include <iostream>
#include "StackException.hpp"

using namespace std;

/*---------------------------------*/
class StackEmptyException: public StackException // Override from StackException
{
private:

public:
    // Constructors
    StackEmptyException(): StackException() {}; // Default constructor
    StackEmptyException(const StackEmptyException& stackemptyEx): StackException(stackemptyEx) {};  // Copy constructor

    // Destructor
    virtual ~StackEmptyException() {};

    // Accessing functions
    string GetMessage() const
    {
        return "Failed. Stack is empty.";
    }

};

#endif // StackEmptyException_HPP