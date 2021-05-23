// Type: Homework
// Level: 1
// Section: 1.7 Pointers and Arrays
// Exercise: 2
// Description: Main file to test Swap()
// Try to create a function Swap().
//  This function must exchange the value of two variables.
//  For example: if i=123 and j=456, then i=456 and j=123 after the Swap() function has been called.
//  The variables i and j are declared, initialised and printed in the function main().
//  This problem can be solved by using pointers as arguments for the Swap()function.

/*---------------------------------*/
#include <stdio.h>
#include "Defs.h"

int main()
{
    // Declare parameters i,j
    int i,j;

    // Input parameters x,y,z
    printf("Input an integer value of i = ");
    scanf("%d", &i);

    printf("Input an integer value of j = ");
    scanf("%d", &j);

    printf("Pre-swap (i,j) = (%d,%d)\n", i,j);  // Display values of vars pre-swap

    Swap(&i,&j);  // Running the Swap function
    printf("Post-swap (i,j) = (%d,%d)\n", i,j);  // Display values of vars post-swap


    return 0;
}



