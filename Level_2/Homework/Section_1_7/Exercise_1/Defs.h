// Type: Lecture
// Level: 1
// Section: 1.7 Pointers and Arrays
// Exercise: 2
// Description: Definition file that include definitions of macros
// Try to create a function Swap().
//  This function must exchange the value of two variables.
//  For example: if i=123 and j=456, then i=456 and j=123 after the Swap() function has been called.
//  The variables i and j are declared, initialised and printed in the function main().
//  This problem can be solved by using pointers as arguments for the Swap()function.

#ifndef DEFS_H
#define DEFS_H

/*---------------------------------*/
// PRINT1 function that prints variable a from main()
#ifndef PRINT1
#define PRINT1(a) printf("a = %d\n", a)
#endif  // end of include guard for PRINT1

/*---------------------------------*/
// PRINT2 function that prints variables a and b from main()
#ifndef PRINT2
#define PRINT2(a,b) printf("(a,b) = (%d,%d)\n", a, b)
#endif  // end of include guard for PRINT2

/*---------------------------------*/
// MAX2 function that returns that maximum value of x and y
#ifndef MAX2
#define MAX2(x,y) (x>y ? x:y)
#endif  // end of include guard for MAX2

/*---------------------------------*/
// MAX3 function that returns the maximum values of x,y and z; while using MAX2
#ifndef MAX3
#define MAX3(x,y,z) (MAX2(x,y) > z ? MAX2(x,y):z)
#endif  // end of include guard for MAX3

/*---------------------------------*/
// Swap function that swap values of 2 variables
void Swap(int* x, int* y)
{
    int swapVal = *x;  // Declare a middle-man variable and pointed to by x
    *x = *y;  // Assign the pointer value of x to be the pointer value of y
    *y = swapVal;  // Assign the middle-man variable that carries x value to pointer value of y
}

#endif  // end of include guard for DEFS_H