// Type: Homework
// Level: 2
// Section: 1.8 Structures
// Exercise: 1
// Description: Main file to test Print() and struct Article
// Write a C-program that prints the contents of a struct called Article.
//  An Article has the following characteristics:
//  • Article number
//  • Quantity
//  • Description (20 characters)
//
//  The test program must create an Article of which the contents are assigned at initialization level.
//  Printing the Article is done with a Print() function.
//  This function gets the address of the structure as a parameter.
//
//  Tip: Suppose that p is the pointer to the structure.
//  It will allow the fields to be printed by (*p).fieldname or p->fieldname.

/*---------------------------------*/
#include <stdio.h>
#include "Article.h"

int main()
{
    // Declare and initialize Article data
    Article myArticle = {0001234, 1000, "Nike Pro Shirt"};

    Print(&myArticle);  // Print the content of Article data

    return 0;
}



