// Type: Homework
// Level: 6
// Section: 4.2a Advanced Templates
// Exercise: 3
// Description: Test file to test PointArray() class with template
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
#include "PointArray.hpp"
#include "PointArray.cpp"
#include <iostream>

using namespace std;

/*---------------------------------*/
int main()
{
    PointArray pointArr1(5);
    Point p0 = Point(0,0);
    Point p1 = Point(1,1);
    Point p2 = Point(2,2);
    Point p3 = Point(3,3);
    Point p4 = Point(4,4);

    pointArr1[0] = p0;
    pointArr1[1] = p1;
    pointArr1[2] = p2;
    pointArr1[3] = p3;
    pointArr1[4] = p4;

    cout << "Type is " << typeid(pointArr1[4]).name() << endl;
    cout << "Type is " << typeid(p4).name() << endl;
    cout << pointArr1.GetElement(4) << endl;

    /*---------------------------------*/
    // Test Access functions
    cout << "pointArr1 = {" << pointArr1[0] << ", "
                            << pointArr1[1] << ", "
                            << pointArr1[2] << ", "
                            << pointArr1[3] << ", "
                            << pointArr1[4] << "}"
                            << endl;

    /*---------------------------------*/
    // Test overriden function Size()
    cout << "pointArr1.Size() = " << pointArr1.Size() << endl;

    /*---------------------------------*/
    // Test Length()
    cout << "pointArr1.Length() = " << pointArr1.Length() << endl;

    /*---------------------------------*/
    // Test = operator of 2 arrays
    PointArray pointAssignArr;
    pointAssignArr = pointArr1;
    cout << "pointAssignArr = {" << pointAssignArr[0] << ", "
                                 << pointAssignArr[1] << ", "
                                 << pointAssignArr[2] << ", "
                                 << pointAssignArr[3] << ", "
                                 << pointAssignArr[4] << "}"
                                 << endl;

    return 0;
}



