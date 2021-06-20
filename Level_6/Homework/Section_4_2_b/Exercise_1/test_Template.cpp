// Type: Homework
// Level: 6
// Section: 4.2a Advanced Templates
// Exercise: 1
// Description: Test file to test Array() class with template
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
#include "Point.hpp"
#include "Point.cpp"
#include "Line.hpp"
#include "Line.cpp"
#include "Circle.hpp"
#include "Circle.cpp"
#include "Array.hpp"
#include "Array.cpp"
#include "Shape.hpp"
#include "Shape.cpp"
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>

using namespace std;

/*---------------------------------*/
int main()
{
    Array<int> intArray1;  // initialize array of default size 10
    Array<int> intArray2;  // initialize array of default size 10
    Array<double> doubleArray;  // initialize array of default size 10

    cout<<intArray1.DefaultSize()<<endl;  // Print default size 10 of intArray1
    cout<<intArray2.DefaultSize()<<endl;  // Print default size 10 of intArray2
    cout<<doubleArray.DefaultSize()<<endl;  // Print default size 10 of doubleArray

    intArray1.DefaultSize(15);  // Set default size 15 of intArray1, also all Array<int> class

    cout<<intArray1.DefaultSize()<<endl;  // Print default size (now 15) of intArray1
    cout<<intArray2.DefaultSize()<<endl;  // Print default size (now 15) of intArray2
    cout<<doubleArray.DefaultSize()<<endl;  // Print default size (still 10) of doubleArray

    return 0;
}



