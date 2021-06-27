// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 4
// Description: Source file contains functionalities for class Array()
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
#ifndef Array_CPP
#define Array_CPP

#include "Point.hpp"
#include "Array.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing a default array of 10 elements
template <typename T>
int Array<T>::m_DefaultSize = 10;

// Initializing a dynamic array of 10 elements
template <typename T>
Array<T>::Array(): m_data(new T[m_DefaultSize]), m_size(m_DefaultSize)
{
    cout << "Default array created" << endl;
}

// Initialize array with newSize number of elements
template <typename T>
Array<T>::Array(int newSize): m_data(new T[newSize]), m_size(newSize)
{
    cout << "Array created." << endl;
}

// Copy Constructor
template <typename T>
Array<T>::Array(const Array<T>& array): m_data(new T[array.m_size]), m_size(array.m_size)
{
    cout << "Copy constructor called." << endl;
    for (int idx=0; idx<m_size; idx++)
    {
        m_data[idx] = array.m_data[idx];
        cout << "arr[" << idx << "] = " << m_data[idx] << endl;
    }
}

// Destructor
template <typename T>
Array<T>::~Array()
{
    delete[] m_data;
    cout << "Array destroyed.\n";
}

// Returns the size of the array
template <typename T>
const int& Array<T>::Size() const
{
    return m_size;
}

// Set an element of the array based on the index
// Check if idx is out-of-bound, if so, display on-screen notification
template <typename T>
void Array<T>::SetElement(int idx, const T& type)
{

    if (idx < m_size && !(idx < 0))
    {
        m_data[idx] = type;
    }
    else
    {
        throw OutOfBoundsException(idx);
    }

}

// Get an element based on its array index
template <typename T>
const T& Array<T>::GetElement(int idx) const
{
    if (idx < m_size && !(idx < 0))
    {
        return m_data[idx];
    }
    else
    {
        throw OutOfBoundsException(idx);
    }
}

// Set array default size
template <typename T>
static void Array<T>::DefaultSize(int size)
{
    m_DefaultSize = size;
}

// Get array default size
template <typename T>
static const int& Array<T>::DefaultSize()
{
    return m_DefaultSize;
}

// Assignment operator.
template <typename T>
Array<T>& Array<T>::operator = (const Array& source)
{
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        delete[] m_data;  // Clean up old array before assignment

        m_data = new T[source.m_size];
        m_size = source.m_size;
        for (int idx=0; idx<m_size; idx++)
        {
            m_data[idx] = source.m_data[idx];
        }

        return *this;  // Assign the result to itself
    }
}

// Return a reference so the [] operator can be used for both reading and writing elements.
// When the index is out of bounds, return the first element.
template <typename T>
T& Array<T>::operator [] (int idx)
{
    if (idx < m_size && !(idx <0))
    {
        return m_data[idx];
    }
    else
    {
        throw OutOfBoundsException(idx);
    }
}

// Return a reference so the [] operator can be used for both reading and writing elements.
// When the index is out of bounds, return the first element.
// Necessary when you want to read-only
template <typename T>
const T& Array<T>::operator [] (int idx) const
{
    if (idx < m_size && !(idx <0))
    {
        return m_data[idx];
    }
    else
    {
        throw OutOfBoundsException(idx);
    }
}

#endif // Array_CPP