// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 3
// Description: Definition file contains class OutOfBoundsException()
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