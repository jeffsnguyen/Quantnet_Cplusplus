// Type: Homework
// Level: 1
// Section: 1.6 The Preprocessor
// Exercise: 2
// Description: Definition file that include definitions of macros
// Create the two macros MAX2(x,y) and MAX3(x,y,z).
//  These macros must return the maximum value of the given arguments.
//  Let the macro MAX3 make use of the macro MAX2.
//
//  Add these macros to the file “Defs.h”.

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

#endif  // end of include guard for DEFS_H