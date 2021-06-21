// Type: Homework
// Level: 6
// Section: 4.2a Advanced Templates
// Exercise: 2
// Description: Test file to test Array() class with template
// With templates it is possible to call functionality on the template argument.
// But when you do this, you limit the types you can use as the template argument
//  because they have to support that functionality.
// Thus when adding numeric functionality to the Array class like calculating the sum,
//  you would limit the types possible as the template argument to types that support numeric operations.
//  It is better to leave the Array class as generic as possible so it can be used in various situations.
//  Numeric functionality can then be put in a derived class
//      which itself is also a template (generic inheritance) as shown in Figure 2.
// In this exercise we are going to create a NumericArray derived from Array.
//  •Add a new source- and header file for a NumericArray class to your project.
//  •Create a template class called NumericArray and derive it from the Array class using generic inheritance.
//  •Since they are not inherited, create proper constructors, destructor and
//      assignment operator and call the base class where appropriate.
//  •Add the following numeric functionality:
//      o An operator * to scale the elements of the numeric array by a factor.
//      o An operator + to add the elements of two numeric arrays.
//          Throw an exception if the two arrays have not the same size.
//      o A function to calculate the dot product. The dot product is defined as:
// Change the main program to test the numeric array.
// What assumptions do you make about the type used as template argument?
// Can you create a numeric array with Point objects?

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
#include "NumericArray.hpp"
#include "NumericArray.cpp"
#include <iostream>

using namespace std;

/*---------------------------------*/
int main()
{
    NumericArray<int> intArr1(5);
    intArr1[0] = 0;
    intArr1[1] = 1;
    intArr1[2] = 2;
    intArr1[3] = 3;
    intArr1[4] = 4;

    NumericArray<int> intArr2(5);
    intArr2[0] = 1;
    intArr2[1] = 2;
    intArr2[2] = 3;
    intArr2[3] = 4;
    intArr2[4] = 5;

    NumericArray<int> intArr3(4);
    intArr2[0] = 1;
    intArr2[1] = 2;
    intArr2[2] = 3;
    intArr2[3] = 4;

    NumericArray<int> intAddArr(5);
    NumericArray<int> intAssignArr(5);
    NumericArray<int> intScaleArr(5);

    /*---------------------------------*/
    // Test Access functions
    cout << "intArr1 = {" << intArr1[0] << ", "
                          << intArr1[1] << ", "
                          << intArr1[2] << ", "
                          << intArr1[3] << ", "
                          << intArr1[4] << "}"
                          << endl;

    cout << "intArr2 = {" << intArr2[0] << ", "
                          << intArr2[1] << ", "
                          << intArr2[2] << ", "
                          << intArr2[3] << ", "
                          << intArr2[4] << "}"
                          << endl;

    /*---------------------------------*/
    // Test overriden function Size()
    cout << "intArr1.Size() = " << intArr1.Size() << endl;
    cout << "intArr2.Size() = " << intArr2.Size() << endl;

    /*---------------------------------*/
    // Test DotProduct of 2 arrays
    cout << "intArr1.DotProduct(intArr2) = " << intArr1.DotProduct(intArr2) << endl;

    /*---------------------------------*/
    // Test = operator of 2 arrays
    intAssignArr = intArr1;
    cout << "intAssignArr = {" << intAssignArr[0] << ", "
                               << intAssignArr[1] << ", "
                               << intAssignArr[2] << ", "
                               << intAssignArr[3] << ", "
                               << intAssignArr[4] << "}"
                               << endl;

    /*---------------------------------*/
    // Test + operator of 2 arrays
    // Same shape
    intAddArr = intArr1 + intArr2;
    cout << "intArr1{" << intArr1[0] << ", "
                       << intArr1[1] << ", "
                       << intArr1[2] << ", "
                       << intArr1[3] << ", "
                       << intArr1[4] << "} + "
         << "intArr2{" << intArr2[0] << ", "
                       << intArr2[1] << ", "
                       << intArr2[2] << ", "
                       << intArr2[3] << ", "
                       << intArr2[4] << "} = "
         << "intAddArr{" << intAddArr[0] << ", "
                         << intAddArr[1] << ", "
                         << intAddArr[2] << ", "
                         << intAddArr[3] << ", "
                         << intAddArr[4] << "}"
                         << endl;

    // Different shape
    try 
    {
        intAddArr = intArr1 + intArr3;
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    /*---------------------------------*/
    // Test * operator of 2 arrays
    intScaleArr = intArr1 * 2;
    cout << "intArr1{" << intArr1[0] << ", "
                       << intArr1[1] << ", "
                       << intArr1[2] << ", "
                       << intArr1[3] << ", "
                       << intArr1[4] << "} * 2 = "
                       << "intScaleArr{" << intScaleArr[0] << ", "
                       << intScaleArr[1] << ", "
                       << intScaleArr[2] << ", "
                       << intScaleArr[3] << ", "
                       << intScaleArr[4] << "}"
                       << endl;

    /*---------------------------------*/
    // Create numeric array with Point objects
    NumericArray<Point> pointArr1(5);
    pointArr1[0] = Point(1,1);
    pointArr1[1] = Point(2,2);
    pointArr1[2] = Point(3,3);
    pointArr1[3] = Point(4,4);
    pointArr1[4] = Point(5,5);

    cout << "pointArr1 = {" << pointArr1[0] << ", "
                            << pointArr1[1] << ", "
                            << pointArr1[2] << ", "
                            << pointArr1[3] << ", "
                            << pointArr1[4] << "}"
                            << endl;

    // Can create numeric array with Point objects but cannot apply Point specific functionalities.

    return 0;
}



