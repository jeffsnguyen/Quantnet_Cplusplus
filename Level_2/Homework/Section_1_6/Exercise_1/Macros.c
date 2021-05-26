// Type: Homework
// Level: 2
// Section: 1.6 The Preprocessor
// Exercise: 1
// Description: Main file to test the macros.
// Write a C-program that contains two print macro calls.
//  The first prints the variable a, the second prints the variables a and b.
//  Printing happens by the use of the PRINT1 and PRINT2 macros that accept arguments.
//  These macros must be defined in an include-file.
//  The variables a and b gets their value in the function main().
//
//  Name the program “Macro.c” and the include-file “Defs.h”.
//  Don’t forget to implement the mechanism to avoid multiple inclusion of the header file.

/*---------------------------------*/
#include <stdio.h>
#include "Defs.h"

int main()
{
    // Declare parameters a,b
    int a,b;

    // Input parameters a,b
    printf("Input an integer value of a = ");
    scanf("%d", &a);

    printf("Input an integer value of b = ");
    scanf("%d", &b);

    // Running the macros
    PRINT1(a);
    PRINT2(a,b);

    return 0;
}



