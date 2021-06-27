// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 5
// Description: Definition file contains class StackException()
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