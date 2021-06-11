// Type: Homework
// Level: 5
// Section: 3.6 Exception Handling
// Exercise: 2
// Description: Definition file contains class ArrayException()
// Throwing an int is an easy solution.
// But exception handling is also object oriented and allows us to throw an object.
// In this exercise we will create an exception hierarchy
//  with an ArrayException base class and an OutOfBoundsException derived class as shown in Figure 3:
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
#ifndef ArrayException_HPP
#define ArrayException_HPP

#include <iostream>
using namespace std;

/*---------------------------------*/
class ArrayException
{
private:

public:
    // Constructors
    ArrayException() {}; // Default constructor
    ArrayException(const ArrayException& arrEx) {};  // Copy constructor

    // Destructor
    ~ArrayException() {};

    // Accessing functions
    virtual string GetMessage() const = 0;

};

#endif // ArrayException_HPP