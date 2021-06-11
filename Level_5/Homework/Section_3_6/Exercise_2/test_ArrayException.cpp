// Type: Homework
// Level: 5
// Section: 3.6 Exception Handling
// Exercise: 2
// Description: Test file to test ArrayException() class
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
    // Initialize variables
    Array* arr = new Array(2);
    int idx;
    Point p1 = Point(1,1);

    // Test SetElement & GetElement
    // Error: libc++abi: terminating with uncaught exception of type int
    idx = -1;
    //idx = 3;
    try
    {
        arr->SetElement(idx, p1);
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    try
    {
        cout << "arr[" << idx << "] = " << arr->GetElement(idx) << endl;
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    // Test [] operator
    // Error: libc++abi: terminating with uncaught exception of type int
    try
    {
        cout << (*arr)[3] << endl;
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    try
    {
        cout << (*arr)[-1] << endl;
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    return 0;
}



