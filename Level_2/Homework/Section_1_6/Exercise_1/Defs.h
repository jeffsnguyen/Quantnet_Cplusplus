// Type: Homework
// Level: 1
// Section: 1.6 The Preprocessor
// Exercise: 1
// Description: Definition file that include definitions of macros
// Write a C-program that contains two print macro calls.
//  The first prints the variable a, the second prints the variables a and b.
//  Printing happens by the use of the PRINT1 and PRINT2 macros that accept arguments.
//  These macros must be defined in an include-file.
//  The variables a and b gets their value in the function main().
//
//  Name the program “Macro.c” and the include-file “Defs.h”.
//  Don’t forget to implement the mechanism to avoid multiple inclusion of the header file.

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


#endif  // end of include guard for DEFS_H