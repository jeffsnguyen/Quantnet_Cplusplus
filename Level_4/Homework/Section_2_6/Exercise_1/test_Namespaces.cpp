// Type: Homework
// Level: 4
// Section: 2.5 Namespaces
// Exercise: 1
// Description: Test file to test Array() class
// To avoid name conflicts, programmers can place their classes in a namespace.
// For example the standard library is placed in a namespace called std.
// You should put your classes in your own namespace.
// Thus place the CAD classes (Shape,Point, Line, etc) in the namespace:
//  YourName::CAD
// Place the container classes (Array) in the namespace:
//  YourName::Containers Now access the classes in your own namespace using:
//  • Full class name including namespace for the Point used in the Array class.
//      Note that you can use only the CAD part of the namespace
//      without the YourName part because the Point is also in the YourName namespace.
//  • In the main program, the full namespace for Point class.
//  • In the main program, using declaration for using a single class (Line).
//  • In the main program, using declaration for a complete namespace (Containers).
//  • In the main program, using the Circle class by creating a shorter alias for the YourName::CAD namespace.

/*---------------------------------*/
#include "Point.hpp"
#include "Point.cpp"
#include "Line.hpp"
#include "Line.cpp"
#include "Circle.hpp"
#include "Circle.cpp"
#include "Array.hpp"
#include "Array.cpp"
#include <iostream>

using namespace std;

/*---------------------------------*/
int main()
{
    /*---------------------------------*/
    // Using full namespace for Point class
    Jeff::CAD::Point p1(1,1);
    Jeff::CAD::Point p2(2,2);
    cout << p1 << endl;
    cout << p2 << endl;

    /*---------------------------------*/
    // Using declaration for a single class Line()
    using namespace Jeff::CAD;
    Line l1(p1, p2);
    cout << l1 << endl;

    /*---------------------------------*/
    // Using declaration for a complete namespace Containers()
    using namespace Jeff::Containers;
    Array* arr1 = new Array(3);  // Initiate array with 3 elements
    cout << "Size of arr1 = " << arr1->Size() << endl;  // arr created manually

    // SetElement() for arr1 to have the same Point(1,1)
    // Also use GetElement() to display screen output
    for (int idx=0; idx<arr1->Size(); idx++)
    {
        arr1->SetElement(idx, p1);
        cout << "arr1[" << idx << "] = " << arr1->GetElement(idx) << endl;
    }

    /*---------------------------------*/
    // Using the Circle class by creating a shorter alias for the YourName::CAD namespace.
    namespace JeffCAD = Jeff::CAD;

    // Initializing Circle with center point p1 and radius r
    Circle c1(p1, l1.Length());

    // Test overloaded ToString()
    cout << "Circle 1 = " << c1 << endl;

    return 0;
}



