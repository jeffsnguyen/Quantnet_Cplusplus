// Type: Homework
// Level: 5
// Section: 3.6 Exception Handling
// Exercise: 2
// Description: Definition file contains class OutOfBoundsException()
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
#ifndef OutOfBoundsException_HPP
#define OutOfBoundsException_HPP

#include <iostream>
#include "ArrayException.hpp"

using namespace std;

/*---------------------------------*/
class OutOfBoundsException: public ArrayException // Override from ArrayException
{
private:
    int m_index;  // error index

public:
    // Constructors
    OutOfBoundsException(): m_index(0) {}; // Default constructor
    OutOfBoundsException(int new_m_idx): m_index(new_m_idx) {};
    OutOfBoundsException(const OutOfBoundsException& oobEx): m_index(oobEx.m_index) {};  // Copy constructor

    // Destructor
    ~OutOfBoundsException() {};

    // Accessing functions
    string GetMessage() const
    {
        stringstream m_idxSTR;  // Declare stringstream objects
        m_idxSTR << m_index;  // Insert inputs to stream

        return "Index " + m_idxSTR.str() + " is out of bounds.";
    }

};

#endif // ArrayException_HPP