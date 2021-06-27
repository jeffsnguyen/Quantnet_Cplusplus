// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 5
// Description: Definition file contains class Array()
// When you use the Stack class and the stack is full or empty
//  when pushing or popping an element you get an exception from the Array class.
// Since the user of the Stack class does not know that an Array class is used internally,
//  you don’t want that the client must know about the array exceptions.
// Thus the array exception must be translated to a stack exception.
//  •The stack exception classes can be implemented in a header file only for simplicity.
//  •Create a StackException base class anda StackFullException and StackEmptyException derived class.
//  •In the Push() function of stack, place the code in a try ... catch block and catch the array exception.
//      In the catch handler, throw a StackFullException exception.
//  •In the Pop() function of stack, place the code in a try ... catch block and catch the array exception.
//      In the catch handler, throw a StackEmptyException exception.
//      Also set the current index back to 0.
//  •Change the test program so it catches the stack exception.


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