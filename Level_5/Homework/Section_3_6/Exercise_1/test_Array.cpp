// Type: Homework
// Level: 5
// Section: 3.6 Exception Handling
// Exercise: 1
// Description: Test file to test Array() class
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
    catch (int error)
    {
        cout << "Index out of bound" << endl;
    }

    try
    {
        cout << "arr[" << idx << "] = " << arr->GetElement(idx) << endl;
    }
    catch (int error)
    {
        cout << "Index out of bound" << endl;
    }

    // Test [] operator
    // Error: libc++abi: terminating with uncaught exception of type int
    try
    {
        cout << (*arr)[3] << endl;
    }
    catch (int error)
    {
        cout << "Index out of bound" << endl;
    }

    try
    {
        cout << (*arr)[-1] << endl;
    }
    catch (int error)
    {
        cout << "Index out of bound" << endl;
    }

    return 0;
}



