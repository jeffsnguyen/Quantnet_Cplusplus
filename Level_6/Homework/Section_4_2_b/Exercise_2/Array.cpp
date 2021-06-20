// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 2
// Description: Source file contains functionalities for class Array()
// With templates it is possible to call functionality on the template argument.
// But when you do this, you limit the types you can use as the template argument
//  because they have to support that functionality.
// Thus when adding numeric functionality to the Array class like calculating the sum,
//  you would limit the types possible as the template argument to types that support numeric operations.
//  It is better to leave the Array class as generic as possible so it can be used in various situations.
//  Numeric functionality can then be put in a derived class
//      which itself is also a template (generic inheritance) as shown in Figure 2.
// In this exercise we are going to create a NumericArray derived from Array.
//  •Add a new source- and header file for a NumericArray class to your project.
//  •Create a template class called NumericArray and derive it from the Array class using generic inheritance.
//  •Since they are not inherited, create proper constructors, destructor and
//      assignment operator and call the base class where appropriate.
//  •Add the following numeric functionality:
//      o An operator * to scale the elements of the numeric array by a factor.
//      o An operator + to add the elements of two numeric arrays.
//          Throw an exception if the two arrays have not the same size.
//      o A function to calculate the dot product. The dot product is defined as:
// Change the main program to test the numeric array.
// What assumptions do you make about the type used as template argument?
// Can you create a numeric array with Point objects?


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