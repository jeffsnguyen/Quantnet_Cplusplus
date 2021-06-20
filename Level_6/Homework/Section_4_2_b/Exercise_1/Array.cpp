// Type: Homework
// Level: 6
// Section: 4.2a Advanced Templates
// Exercise: 1
// Description: Source file contains functionalities for class Array()
// Static variables, which are shared between all instances of a class,
//  behave slightly different with templates.
// We are going to test this with a static variable in the Array class
//  that indicates the default array size when using the default constructor.
//  •Add a static data member to the Array class indicating the default size.
//  •Initialise this static in the source file to a value.
//  •Also add static functions to set and get the default size.
//  •In the default constructor, use the static default size variable instead of a literal valueto set the array size.
// Test the following code in the main program:
//  Array<int> intArray1;
//  Array<int> intArray2;
//  Array<double> doubleArray;
//
//  cout<<intArray1.DefaultSize()<<endl;
//  cout<<intArray2.DefaultSize()<<endl;
//  cout<<doubleArray.DefaultSize()<<endl;
//
//  intArray1.DefaultSize(15);
//
//  cout<<intArray1.DefaultSize()<<endl;
//  cout<<intArray2.DefaultSize()<<endl;
//  cout<<doubleArray.DefaultSize()<<endl;
//
// What values are printed? Can you explain the result?


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