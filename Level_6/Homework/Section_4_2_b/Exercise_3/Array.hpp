// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 3
// Description: Definition file contains class Array()
// You can create an array of points by directly instantiating the Array class for the Point class.
// This works well but we can’t add points specific functionality to the Array class in this way.
// A solution is to create a derived class
//  of which the template argument is fixed to a specific type (concrete inheritance) as shown in Figure 3.
// In this exercise we will create a PointArray which is derived from Array with the template argument set to Point.
//  •Add a new source- and header file for the PointArray class to your project.
//  •Create a regular class called PointArray which is derived from Array.
//      The template argument given to Array is Point.
//  •Since they are not inherited, create proper constructors, destructor
//      and assignment operator and call the base class where appropriate.
//  •Now we can add functionality specific for a point array.
//      For example add a Length()function that returns the total length between the points in the array.
//  •Change the main program to test the point array.


/*---------------------------------*/
#ifndef Array_HPP
#define Array_HPP

#include <iostream>
using namespace std;

/*---------------------------------*/
template <typename T>
class Array
{
private:
    T* m_data;  // Dynamic array of Point() objects
    int m_size;  // Size of above array
    static int m_DefaultSize;  // Default size of array

public:
    // Constructors
    Array();  // Default constructor
    Array(int newSize);  // Initialize array with newSize number of elements
    Array(const Array<T>& array);  // Copy constructor

    // Destructor
    ~Array();

    // Accessing functions
    const int& Size() const;  // Returns the size of the array
    void SetElement(int idx, const T& type);  // Set an element of the array based on the index
    const T& GetElement(int idx) const;  // Get an element based on its array index
    static void DefaultSize(int size);  // Set array default size
    static const int& DefaultSize();  // Get array default size

    // Overloading operators
    Array<T>& operator = (const Array& source); // Assignment operator.

    // Return a reference so the [] operator can be used for both reading and writing elements.
    // When the index is out of bounds, return the first element.
    T& operator [] (int idx);
    const T& operator [] (int idx) const;

};

#endif // Array_HPP