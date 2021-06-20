// Type: Homework
// Level: 6
// Section: 4.2a Introduction to Templates
// Exercise: 1
// Description: Test file to test Array() class with template
// In a previous exercise we created an Array class that stores Point objects.
// The disadvantage of this class was that it only stores Point objects.
// If we want to have an array class for Lines,
//  we need to copy the code and replace references to Point to Line.
// This is a lot of work and makes maintenance more difficult.
// A bug in one version has to be fixed in the other versions as well.
// Better is to use the same code for different data types.
// This is possible using templates as shown in Figure 1.
//
// Thus transform the Array class for points created earlier into a template class:
//  •In the header file, declare the Array class as a template of type T.
//  •Replace all references to Point with T.
//  •Where an array is used as input or output, replace Array by Array<T>.
//  •In the source file, every function must be declared as a template of type T.
//  •The functions are now not a member of Array anymore but a member of Array<T>.
//  •Further replace all references to Point with T.
//  •Finally where an array is used as input or output, replace Array by Array<T>.
//  •Don’t forget that the test program should now include the source file instead of the header file.
//  Therefore, the source file should now also include#ifndef/#define/#endif statements.
//
//  In the test program create an array of points and test it:
//      Array<Point> points(size);
//  Tip: by placing the following code at the end of the array header file,
//  but before the header file’s #endif, the client can keep including the header file
//  for template classes instead of the source file. Can you explain how this works?:
//      #ifndef Array_cpp // Must be the same name as in source file #define
//      #include "Array.cpp"
//      #endif

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
    /*---------------------------------*/
    // Test template with Point
    // Initialize variables
    Array<Point>* arrP = new Array<Point>(2);
    int idx;
    Point p1 = Point(1,1);

    // Test SetElement & GetElement
    idx = -1;

    try
    {
        arrP->SetElement(idx, p1);
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    try
    {
        cout << "arrP[" << idx << "] = " << arrP->GetElement(idx) << endl;
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    // Test [] operator
    try
    {
        cout << (*arrP)[3] << endl;
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    try
    {
        cout << (*arrP)[-1] << endl;
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    /*---------------------------------*/
    // Test template with Line
    // Initialize variables
    Array<Line>* arrL = new Array<Line>(2);
    Point p2 = Point(1,1);
    Line l1 = Line(p1, p2);

    // Test SetElement & GetElement
    idx = -1;

    try
    {
        arrL->SetElement(idx, l1);
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    try
    {
        cout << "arrL[" << idx << "] = " << arrL->GetElement(idx) << endl;
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    // Test [] operator
    try
    {
        cout << (*arrL)[3] << endl;
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    try
    {
        cout << (*arrL)[-1] << endl;
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    /*---------------------------------*/
    // Test template with Circle
    // Initialize variables
    Array<Circle>* arrC = new Array<Circle>(2);
    double r = p1.Distance(p2);
    Circle c1 = Circle(p1, r);

    // Test SetElement & GetElement
    idx = -1;

    try
    {
        arrC->SetElement(idx, c1);
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    try
    {
        cout << "arrC[" << idx << "] = " << arrC->GetElement(idx) << endl;
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    // Test [] operator
    try
    {
        cout << (*arrC)[3] << endl;
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }

    try
    {
        cout << (*arrC)[-1] << endl;
    }
    catch (ArrayException& arrEx)
    {
        cout << arrEx.GetMessage() << endl;
    }
    return 0;
}



