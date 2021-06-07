// Type: Homework
// Level: 4
// Section: 2.5 The Free Store
// Exercise: 2
// Description: Test file to test objects
// In this exercise we make it a little more complex.
// With an array of Points, all points are created with the default constructor.
// When creating an array of pointers,
//  each element in the array must be created separately
//  but can be created with other constructors than the default constructor.
// Thus creating an array of pointers is a two step process:
//  • Create an array of Point pointers with 3 elements on the heap.
//  • Create for each element in the array a point on the heap.
//  • Iterate the array and print each point in the array.
//  • Iterate the array again and delete each point in the array.
//  • Delete the array itself.
// Also make a drawing of the memory layout.

/*---------------------------------*/
#include "Point.hpp"
#include "Point.cpp"
#include <iostream>
#include <sstream>

using namespace std;

/*---------------------------------*/
int main()
{
    // Create an array of Point pointers with 3 elements on the heap.
    Point** pArr = new Point*[3];

    // Create for each element in the array a point on the heap.
    // Iterate the array and print each point in the array.
    for (int idx=0; idx<3; idx++)
    {
        pArr[idx] = new Point(1,1);
        cout << "pArr[" << idx << "] = " << *pArr[idx] << " created at location " << pArr[idx] << endl;
    }

    // Iterate the array again and delete each point in the array.
    for (int idx=0; idx<3; idx++)
    {
        cout << "Deleting " << *pArr[idx] << " at location " << pArr[idx] << endl;
        delete pArr[idx];
    }

    delete[] pArr; // Delete array of pointers

    return 0;
}



