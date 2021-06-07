// Type: Homework
// Level: 4
// Section: 2.5 The Free Store
// Exercise: 1
// Description: Test file to test objects
// Until now, we created objects on the stack.
// The stack is limited in size thus when creating many objects,
//  the stack will overflow.
// Also arrays created on the stack can only have a fixed size determined at compile time.
//
// To overcome these problems we have to create objects on the heap using new.
// In the main program, create Point objects on the heap with new using the default constructor,
//  constructor with coordinates and the copy constructor
//  and assign it to pointer (Point*) variables.
// Note that you can’t directly pass a pointer variable as argument to the copy constructor.
// The pointer must first be dereferenced when passing it to the copy constructor.
//  (Point* p2=new Point(*p1)).
// Next call the Distance() function on the pointers and try to send the Point pointers to cout.
// You need to dereference the pointer when passing it as argument.
// Don’t forget to delete the object created with new.
// Test the main program.
//
// Next, we will create an array of points.
// First ask the user for the size of the array and read it using cin.
// Then try to create an array on the stack using the entered size.
// You will see a compiler error.
// Arrays on the stack must have the size set at compile time.
// Now create the array on the heap using new.
// Can you use other constructors than the default constructor for the objects created in the array?
// Don’t forget to delete the array after use.
// Don’t forget the square brackets when deleting arrays!
//
// Some C++ compilers (e.g. GCC) support variable length arrays (VLA)
//  where the size can be determined at run-time.
// However this is a C99 feature that is not in the C++ standard.
// Because VLA is not in the C++ standard you should avoid its usage since it will lead to less portable code.

/*---------------------------------*/
#include "Point.hpp"
#include "Point.cpp"
#include <iostream>
#include <sstream>

using namespace std;

/*---------------------------------*/
int main()
{
    /*---------------------------------*/
    // Create Point objects on the heap with new using the default constructor
    Point* pDefault = new Point();
    // Create Point objects on the heap with new using constructor with coordinates
    Point* pWCoord = new Point(1,1);
    // Create Point objects on the heap with new using copy constructor
    //  and assign it to pointer variable
    Point* pCopy = new Point(*pWCoord);

    // Call Distance() member function using -> and send pointers to cout
    double dist;
    dist = pDefault->Distance(*pWCoord);
    cout << "D[" << *pDefault << "," << *pWCoord << "] = " << dist << endl;
    cout << "Copied point = " << *pCopy << endl;

    // Delete objects
    delete pDefault;
    delete pWCoord;
    delete pCopy;

    /*---------------------------------*/
    int sizeArr;  // Initialize array size var

    // User input prompt for array size
    cout << "Enter array size = ";
    cin >> sizeArr;

    // Error: This is supposed to throw an error per the assignment
    // But it compiled fine under C-Lion. Create arr of 10 points and destroyed all 10 afterwards
    //Point pArr[sizeArr];

    // Initialize array on the heap using new
    Point* pArr = new Point[sizeArr];

    // Use default constructor for objects in array
    for (int idx=0; idx<sizeArr; idx++)
    {
        pArr[idx] = Point();
        cout << "pArr[" << idx << "] = " << pArr[idx] << endl;
    }

    // Using constructor with coordinate for objects in array
    for (int idx=0; idx<sizeArr; idx++)
    {
        pArr[idx] = Point(1,1);
        cout << "pArr[" << idx << "] = " << pArr[idx] << endl;
    }

    delete[] pArr; // Delete arrays

    return 0;
}



