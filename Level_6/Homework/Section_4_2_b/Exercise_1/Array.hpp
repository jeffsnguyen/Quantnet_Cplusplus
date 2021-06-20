// Type: Homework
// Level: 6
// Section: 4.2a Advanced Templates
// Exercise: 1
// Description: Definition file contains class Array()
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