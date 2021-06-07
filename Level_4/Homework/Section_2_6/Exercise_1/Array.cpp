// Type: Homework
// Level: 4
// Section: 2.5 Namespaces
// Exercise: 1
// Description: Source file contains functionalities for class Array()
// To avoid name conflicts, programmers can place their classes in a namespace.
// For example the standard library is placed in a namespace called std.
// You should put your classes in your own namespace.
// Thus place the CAD classes (Shape,Point, Line, etc) in the namespace:
//  YourName::CAD
// Place the container classes (Array) in the namespace:
//  YourName::Containers Now access the classes in your own namespace using:
//  • Full class name including namespace for the Point used in the Array class.
//      Note that you can use only the CAD part of the namespace
//      without the YourName part because the Point is also in the YourName namespace.
//  • In the main program, the full namespace for Point class.
//  • In the main program, using declaration for using a single class (Line).
//  • In the main program, using declaration for a complete namespace (Containers).
//  • In the main program, using the Circle class by creating a shorter alias for the YourName::CAD namespace.

/*---------------------------------*/
#include "Point.hpp"
#include "Array.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
namespace Jeff
{
    namespace Containers
    {
        // Initializing a dynamic array of 10 elements
        Array::Array(): m_data(new CAD::Point[10]), m_size(10)
        {
            cout << "Default array created" << endl;
        }

        // Initialize array with newSize number of elements
        Array::Array(int newSize): m_data(new CAD::Point[newSize]), m_size(newSize)
        {
            cout << "Array created." << endl;
        }

        // Copy Constructor
        Array::Array(const Array& array): m_data(new CAD::Point[array.m_size]), m_size(array.m_size)
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
        void Array::SetElement(int idx, const CAD::Point& point)
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
        const CAD::Point& Array::GetElement(int idx) const
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

                m_data = new CAD::Point[source.m_size];
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
        CAD::Point& Array::operator [] (int idx)
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
        const CAD::Point& Array::operator [] (int idx) const
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
    }
}