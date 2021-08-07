// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 6
// Description: Definition file contains class Array()
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.


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
    virtual ~Array();

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