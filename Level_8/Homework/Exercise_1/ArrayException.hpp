// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Definition file contains class ArrayException()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.


/*---------------------------------*/
#ifndef ArrayException_HPP
#define ArrayException_HPP

#include <iostream>
using namespace std;

/*---------------------------------*/
class ArrayException
{
private:

public:
    // Constructors
    ArrayException() {}; // Default constructor
    ArrayException(const ArrayException& arrEx) {};  // Copy constructor

    // Destructor
    virtual ~ArrayException() {};

    // Accessing functions
    virtual string GetMessage() const = 0;

};

#endif // ArrayException_HPP