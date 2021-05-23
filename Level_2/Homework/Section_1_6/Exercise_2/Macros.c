// Type: Homework
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
    // Declare parameters x,y,z
    int x,y,z;

    // Input parameters x,y,z
    printf("Input an integer value of x = ");
    scanf("%d", &x);

    printf("Input an integer value of y = ");
    scanf("%d", &y);

    printf("Input an integer value of z = ");
    scanf("%d", &z);

    // Running the macros
    printf("max(x,y) = %d\n", MAX2(x,y));
    printf("max(x,y,z) = %d\n", MAX3(x,y,z));

    return 0;
}



