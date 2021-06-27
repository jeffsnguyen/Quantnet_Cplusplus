// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Source file contains functionalities for class Stack()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.

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
template <typename T, int size>
Stack<T, size>::Stack(): m_current(0), arr(size)
{
}

// Copy Constructor
template <typename T, int size>
Stack<T, size>::Stack(const Stack<T, size>& stack): m_current(stack.m_current), arr(stack.arr)
{
}

// Destructor
template <typename T, int size>
Stack<T, size>::~Stack()
{
}

// Store element at current position in the array and increment m_current
template <typename T, int size>
void Stack<T, size>::Push(const T& element)
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
template <typename T, int size>
T& Stack<T, size>::Pop()
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
template <typename T, int size>
Stack<T, size>& Stack<T, size>::operator = (const Stack& source)
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