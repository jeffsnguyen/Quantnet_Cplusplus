// Type: Homework
// Level: 4
// Section: 2.4 Basic Operators Overloading
// Exercise: 3
// Description: Source file contains functionalities for class Array()
// It is easy to forget to delete memory created with new.
// A good practice is to let a class manage memory.
// Then the client of that class does not have to manage memory and can’t forget to delete memory.
// So instead of creating a C array with new, you can use an array class that handle memory for you.
// In this exercise we are going to create an array class for Point objects (see Figure 5):
//  • Add a source- and header file for the Array class to your current project.
//  • Add a data member for a dynamic C array of Point objects (Point* m_data).
//  • Add a data member for the size of the array.
//  • Add a default constructor that allocates for example 10 elements.
//  • Add a constructor with a size argument. The implementation should allocate
//      the number of elements specified by thesize input argument.
//  • Add a copy constructor. Keep in mind that just copying the C array pointer
//      will create an Array object that shares the data with the original Array object.
//      Thus you need to allocate a new C array with the same size and copy each element separately.
//  • Add a destructor. It should delete the internal C array. Don’t forget the square brackets.
//  • Add an assignment operator.
//      Keep in mind you can’t copy only the C array pointers just as in the case of the copy constructor.
//  • Also don’t forget to delete the old C array and
//      allocate new memory before copying the elements. This is because C arrays can’t grow.
//
//  Further check if the source object is not the same as the this object.
//  If you don’t check it, then a statement like arr1=arr1 will go wrong.
//  The internal C array will then be deleted before it is copied.
//  • Add a Size() function that returns the size of the array.
//  • Add a SetElement() function that sets an element.
//      When the index is out of bounds, ignore the “set”. We will add better error handling later.
//  • Add a GetElement() function.
//      You can return the element by reference since the returned element
//      has a longer lifetime than the GetElement() function.
//      When the index is out of bounds, return the first element.
//      We will add better error handling later.
//  • You can also add a square bracket operator.
//      Return a reference so the [] operator can be used for both reading and writing elements.
//      When the index is out of bounds, return the first element. We will add better error handling later.
//          Point& operator [] (int index);
//  • In the main program, test the Array class.

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
        cout << "Index out-of-bound. Nothing done." << endl;
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
        cout << "Index out-of-bound. Returning the first element." << endl;
        return m_data[0];
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
        cout << "Index out-of-bound. Returning the first element." << endl;
        return m_data[0];
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
        cout << "Index out-of-bound. Returning the first element." << endl;
        return m_data[0];
    }
}