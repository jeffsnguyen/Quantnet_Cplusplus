// Type: Homework
// Level: 5
// Section: 3.6 Exception Handling
// Exercise: 1
// Description: Source file contains functionalities for class Array()
// In the array class we created previously, the bounds checking was very basic.
// There was no error generated, but setting an element was ignored or the first element was returned.
// Obviously you want to know if there was an out of bounds error.
// This is possible by exception handling. Change the Array class to throw exceptions:
//  •In the GetElement(), SetElement() and index operator throw -1 if the index was too small or too big.
//  •In the main program, create an Array object and access an element that does not exist.
//      Run the program. What happens?
//  •The exception must be caught, so place the code inside a try ... catch block that catches an int.
//  •In the catch handler, print an error message.

/*---------------------------------*/
#include "Point.hpp"
#include "Array.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing a dynamic array of 10 elements
Array::Array(): m_data(new Point[10]), m_size(10)
{
    cout << "Default array created" << endl;
}

// Initialize array with newSize number of elements
Array::Array(int newSize): m_data(new Point[newSize]), m_size(newSize)
{
    cout << "Array created." << endl;
}

// Copy Constructor
Array::Array(const Array& array): m_data(new Point[array.m_size]), m_size(array.m_size)
{
    cout << "Copy constructor called." << endl;
    for (int idx=0; idx<m_size; idx++)
    {
        m_data[idx] = array.m_data[idx];
        cout << "arr[" << idx << "] = " << m_data[idx] << endl;
    }
}

// Destructor
Array::~Array()
{
    delete[] m_data;
    cout << "Array destroyed.\n";
}

// Returns the size of the array
const int& Array::Size() const
{
    return m_size;
}

// Set an element of the array based on the index
// Check if idx is out-of-bound, if so, display on-screen notification
void Array::SetElement(int idx, const Point& point)
{

    if (idx < m_size && !(idx < 0))
    {
        m_data[idx] = point;
    }
    else
    {
        throw -1;
    }

}

// Get an element based on its array index
const Point& Array::GetElement(int idx) const
{
    if (idx < m_size && !(idx < 0))
    {
        return m_data[idx];
    }
    else
    {
        throw -1;
    }
}

// Assignment operator.
Array& Array::operator = (const Array& source)
{
    // Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        delete[] m_data;  // Clean up old array before assignment

        m_data = new Point[source.m_size];
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
Point& Array::operator [] (int idx)
{
    if (idx < m_size && !(idx <0))
    {
        return m_data[idx];
    }
    else
    {
        throw -1;
    }
}

// Return a reference so the [] operator can be used for both reading and writing elements.
// When the index is out of bounds, return the first element.
// Necessary when you want to read-only
const Point& Array::operator [] (int idx) const
{
    if (idx < m_size && !(idx <0))
    {
        return m_data[idx];
    }
    else
    {
        throw -1;
    }
}