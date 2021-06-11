// Type: Homework
// Level: 5
// Section: 3.6 Exception Handling
// Exercise: 1
// Description: Definition file contains class Array()
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
#ifndef Array_HPP
#define Array_HPP

#include <iostream>
using namespace std;

/*---------------------------------*/
class Array
{
private:
    Point* m_data;  // Dynamic array of Point() objects
    int m_size;  // Size of above array

public:
    // Constructors
    Array();  // Default constructor
    Array(int newSize);  // Initialize array with newSize number of elements
    Array(const Array& array);  // Copy constructor

    // Destructor
    ~Array();

    // Accessing functions
    const int& Size() const;  // Returns the size of the array
    void SetElement(int idx, const Point& point);  // Set an element of the array based on the index
    const Point& GetElement(int idx) const;  // Get an element based on its array index

    // Overloading operators
    Array& operator = (const Array& source); // Assignment operator.

    // Return a reference so the [] operator can be used for both reading and writing elements.
    // When the index is out of bounds, return the first element.
    Point& operator [] (int idx);
    const Point& operator [] (int idx) const;

};

#endif // Array_HPP