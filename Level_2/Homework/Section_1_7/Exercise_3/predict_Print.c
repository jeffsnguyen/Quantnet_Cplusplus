// Type: Homework
// Level: 2
// Section: 1.7 Pointers and Arrays
// Exercise: 3
// Description: Main file to post prediction of what will be printed on the screen


/*---------------------------------*/
/* Predict what will be printed on the screen */
#include <stdio.h>

#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line

// Create and initialize array
int a[]={0, 1, 2, 3, 4};
int main()
{
    int i;
    int* p;

    // Expected result: 01234
    // Why: Loop 5 times from 0->4 and print each index of array a
    //  in increments of 1
    for (i=0; i<=4; i++) PRD(a[i]); // 1
    NL;

    // Expected result: 01234
    // Why: Loop 5 times from pointer value of index starting at 0
    //  of array a to index 4 of the same array in increments of 1.
    //  Print the referenced value which is
    for (p=&a[0]; p<=&a[4]; p++) PRD(*p); // 2
    NL;

    NL;

    // Expected result: 01234
    // Why: Starting with pointer p pointed to array a
    //  and print each value pointed to each index of the array
    //  Each index number is in increments of 1 from the previous.
    for (p=&a[0], i=0; i<=4; i++) PRD(p[i]); // 3
    NL;

    // Expected result: 024
    // Why: Starting with p which is the same as array a and index starting at 0
    //  Each time increment the pointed value by 1 and the index i by 1. Print the referenced value p+1
    //  Loop as long as p+i <= a+4 = 4
    //
    //  First value printed: p=0, i=0: Print 0+0 = 0; check p+i = 1+1=2 <= 4, continue
    //  Second value printed: p=1, i=1: Print 1+1 = 2;  check p+i = 2+2 <= 4, continue
    //  Third value printed: p=2, i=2: Print 2+2 = 4; check p+i = 3+3>4, terminate loop
    for (p=a, i=0; p+i<=a+4; p++, i++) PRD(*(p+i)); // 4
    NL;

    NL;

    // Expected result: 43210
    // Why: Starting with p pointed to a+4
    //  Loop as long as p>=a=0, Each time decrement p by 1. Print the pointed value
    //
    //  First value printed: 4; p=4-1=3>=0, continue
    //  Second value printed: 3; p=3-1=2>=0, continue
    //  Third value printed: 2; p=2-1=1>=0, continue
    //  Fourth value printed: 1; p=1-1=0, continue
    //  Fifth value printed: 0; p=0-1=-1<0, terminate loop
    for (p=a+4; p>=a; p--) PRD(*p); // 5
    NL;

    // Expected Value: 43210
    // Why: Starting with p point to a+4 which is 4
    //  Index start at 0 and incremented by 1 until 4.
    //  Each loop, print the pointed value of index -i, which means the index starts backwards
    //
    //  First value printed: p[-0]=a[4]=4
    //  Second value printed: p[-1]=a[3]=3
    //  Third value printed: p[-2]=a[2]=2
    //  Fourth value printed: p[-3]=a[1]=1
    //  Fifth value printed: p[-4]=a[0]=0
    for (p=a+4, i=0; i<=4; i++) PRD(p[-i]); // 6
    NL;

    // Expected Value: 43210
    // Why: Starting with p point to a+4 which is 4
    //  Loop as long as p>=a, each loop decrement pointed value p by 1
    //  Print a[p-a]
    //
    //  First value printed: p=4, 4>=0. Print a[4-0]=a[4]=4. p=4-1=3
    //  Second value printed: p=3, 3>=0. Print a[3-0]=a[3]=3, p=3-1=2
    //  Third value printed: p=2, 2>=0. Print a[2-0]=a[2]=2, p=2-1=1
    //  Fourth value printed: p=1, 1>=0. Print a[1-0]=a[1]=1, p=1-1=0
    //  Fifth value printed: p=0, 0>=0. Print a[0-0]=a[0]=0, p=0-1=-1<0 terminate loop
    for (p=a+4; p>=a; p--) PRD(a[p-a]); // 7
    NL;

    return 0;
}



