// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 5
// Description: Source file contains functionalities for class Stack()
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
#ifndef Stack_CPP
#define Stack_CPP
#include "Array.hpp"
#include "Stack.hpp"
#include "ArrayException.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing a default stack
template <typename T>
Stack<T>::Stack(): m_current(0), arr()
{
}

// Initialize stack with newSize number of elements
template <typename T>
Stack<T>::Stack(int newSize): m_current(0), arr(newSize)
{
}

// Copy Constructor
template <typename T>
Stack<T>::Stack(const Stack<T>& stack): m_current(stack.m_current), arr(stack.arr)
{
}

// Destructor
template <typename T>
Stack<T>::~Stack()
{
}

// Store element at current position in the array and increment m_current
template <typename T>
void Stack<T>::Push(const T& element)
{
    try
    {
        arr[m_current] = element;
        m_current += 1;
    }
    catch (const ArrayException& arrEx)
    {
        throw StackFullException();
        m_current -= 1;
    }
}

// Decrement current position and returns element at this position
template <typename T>
T& Stack<T>::Pop()
{
    try
    {
        m_current -= 1;
        return arr[m_current];
    }
    catch (const ArrayException& arrEx)
    {
        throw StackEmptyException();
        m_current = 0;
    }
}

// Assignment operator.
template <typename T>
Stack<T>& Stack<T>::operator = (const Stack& source)
{
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        m_current = source.m_current;
        arr = source.arr;

        return *this;  // Assign the result to itself
    }
}

#endif // Stack_CPP