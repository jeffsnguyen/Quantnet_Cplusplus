// Type: Homework
// Level: 6
// Section: 4.2a Advanced Templates
// Exercise: 1
// Description: Definition file contains class ArrayException()
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