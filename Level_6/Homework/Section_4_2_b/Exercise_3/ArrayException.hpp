// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 3
// Description: Definition file contains class ArrayException()
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