// Type: Lecture
// Level: 1
// Section: 1.6 The Preprocessor
// Exercise: 2
// Description: Main file to test the macros.
// Create the two macros MAX2(x,y) and MAX3(x,y,z).
//  These macros must return the maximum value of the given arguments.
//  Let the macro MAX3 make use of the macro MAX2.
//
//  Add these macros to the file “Defs.h”.

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



