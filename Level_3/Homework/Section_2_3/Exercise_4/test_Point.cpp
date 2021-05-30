// Type: Homework
// Level: 3
// Section: 2.3 Improving Your Classes
// Exercise: 4
// Description: Source file contains functionalities for class Point()
// In the test program create a const point and try to set the x-coordinate:
//      const Point cp(1.5, 3.9);
//      cp.X(0.3);
//  Compile the program. Did you get a compiler error?
//  It should give a compiler error because you try to change a const object.
//
//  Now replace the line that changes the x-coordinate to code that reads the x-coordinate:
//      cout<<cp.X()<<endl;
//  Compile the program again.
//  You will see that is still gives a compiler error
//      even while retrieving the x-coordinate does not change the point object.
//  This is because the compiler does not know that the function does not change anything.
//  So we need to mark the x-coordinate getter as const by making it a const function.
//  Do this also for the y-coordinate getter and the Distance() and ToString() functions
//      because these don’t change the point object as well. Recompile the application.
//  It should now work.

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
    // Test 1: C-Lion compiler
    //  error: "No matching member function for call to 'X'
    //  note: "candidate function not viable: 'this' argument has type 'const Point', but method is not marked const
    //      void Point::X(double newX)"
    //const Point cp(1.5, 3.9);
    //cp.X(0.3);

    /*---------------------------------*/
    // Test 2: C-Lion compiler
    //  error: There is no error here because it's already been coded as const function from previous exercises.
    const Point cp(1.5, 3.9);
    cout << cp.X() << endl;

    return 0;
}



