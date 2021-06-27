// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 4
// Description: Source file contains functionalities for class Stack()
// In this exercise we will make a Stack class. For the data storage we can use the Array class.
// Deriving from Array is not a good idea because there is no relation between Array and Stack.
// The stack would then inherit indexed operations which should not be a functionality of a stack.
// But we can use the Array class as a data member as shown in Figure 4:
//  •Add a new source and header file for the Stack class to your project.
//  •Create a template class called Stack.
//      It is not a derived class but it uses an Array as data member.
//      You also need a data member for the current index in the array.
//  •Create the regular constructors, destructor and assignment operator.
//  •Add a Push() function.
//      It should store the element at the current position in the embedded array.
//      Increment the current position afterwards.
//      There is no need for checking the current index because the array
//          will throw an exception when the stack is full.
//      Make sure the current index is not changed when the Array class threw an exception.
//  •Add a Pop() function that decrements the current position
//      and then returns the element at that position.
//      Make sure the current index is not changed when the Array class throws an exception.
//  •Change the main function to test the stack.
// Using another class as data member is called composition.
// In this case the Stack class uses internally an Array class.
// Forwarding functionality to another class is called delegation.
// Here the Stack class delegates the storage of elements to the Array class.


/*---------------------------------*/
#ifndef Stack_CPP
#define Stack_CPP

#include "Array.hpp"
#include "Stack.hpp"
#include "OutOfBoundsException.hpp"
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
    // If arr is full through out of bounds exception, otherwise proceed
    if (m_current == (*this).arr.Size())
    {
        throw OutOfBoundsException(m_current);
    }
    else
    {
        arr[m_current] = element;
        m_current += 1;
    }
}

// Decrement current position and returns element at this position
template <typename T>
T& Stack<T>::Pop()
{
    // Check if current index is 0, then cannot decrement and throw exception
    if (m_current ==0)
    {
        throw OutOfBoundsException(m_current);
    }
    else
    {
        m_current -= 1;
        return arr[m_current];
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