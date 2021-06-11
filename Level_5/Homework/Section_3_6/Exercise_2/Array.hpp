// Type: Homework
// Level: 5
// Section: 3.6 Exception Handling
// Exercise: 2
// Description: Definition file contains class Array()
// Throwing an int is an easy solution.
// But exception handling is also object oriented and allows us to throw an object.
// In this exercise we will create an exception hierarchy
//  with an ArrayException base class and an OutOfBoundsExceptionderived class as shown in Figure 3:
//      •You can implement both exception classes in the header file for simplicity.
//      •Give the ArrayException an abstract GetMessage() function that returns a std::string.
//      •Give the OutOfBoundsException class a constructor with an int as argument
//          that indicates the erroneous array index and store it in a data member.
//      •Override the GetMessage() function
//          and let the implementation return a message string saying the given index is out of bounds.
//      •In the Array class, throw now a OutOfBoundsException object instead of an integer.
//      •Change the main program so that it catches the ArrayException base class
//          and uses the GetMessage() function to display an error message.

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