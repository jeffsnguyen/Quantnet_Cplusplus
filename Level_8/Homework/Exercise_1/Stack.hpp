// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Definition file contains class Stack()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.


/*---------------------------------*/
#ifndef Stack_HPP
#define Stack_HPP

#include <iostream>
using namespace std;

/*---------------------------------*/
template <typename T, int size>
class Stack
{
private:
    int m_current;  // Current index in the array
    Array<T> arr;  // Array object from Array class

public:
    // Constructors
    Stack();  // Default constructor
    Stack(const Stack<T, size>& array);  // Copy constructor

    // Destructor
    virtual ~Stack();

    // Accessing functions
    void Push(const T& element);  // Store element at current position in the array and increment m_current
    T& Pop(); // Decrement current position and returns element at this position

    // Overloading operators
    Stack<T, size>& operator = (const Stack& source); // Assignment operator.

};

#endif // Stack_HPP