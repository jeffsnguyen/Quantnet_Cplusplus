// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 5
// Description: Definition file contains class Stack()
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
#ifndef Stack_HPP
#define Stack_HPP

#include <iostream>
using namespace std;

/*---------------------------------*/
template <typename T>
class Stack
{
private:
    int m_current;  // Current index in the array
    Array<T> arr;  // Array object from Array class

public:
    // Constructors
    Stack();  // Default constructor
    Stack(int newSize);  // Initialize array with newSize number of elements
    Stack(const Stack<T>& array);  // Copy constructor

    // Destructor
    virtual ~Stack();

    // Accessing functions
    void Push(const T& element);  // Store element at current position in the array and increment m_current
    T& Pop(); // Decrement current position and returns element at this position

    // Overloading operators
    Stack<T>& operator = (const Stack& source); // Assignment operator.

};

#endif // Stack_HPP