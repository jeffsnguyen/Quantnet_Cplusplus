// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Definition file contains class StackException()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.


/*---------------------------------*/
#ifndef StackException_HPP
#define StackException_HPP

#include <iostream>
using namespace std;

/*---------------------------------*/
class StackException
{
private:

public:
    // Constructors
    StackException() {}; // Default constructor
    StackException(const StackException& stackEx) {};  // Copy constructor

    // Destructor
    virtual ~StackException() {};

    // Accessing functions
    virtual string GetMessage() const = 0;

};

#endif // StackException_HPP