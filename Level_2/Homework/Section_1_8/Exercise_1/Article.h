// Type: Homework
// Level: 1
// Section: 1.8 Structures
// Exercise: 1
// Description: Definition file contains struct Article and PrintArticle()
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

#ifndef ARTICLES_H
#define ARTICLES_H

/*---------------------------------*/
// Define Article structure
typedef struct Article Article;

struct Article
{
    int articleNum;  // Article Number
    int articleQty;  // Article Quantity
    char articleDesc[20];  // Article Description, 20 character maximum
};

// Printing contents of Article
void Print(Article* data)
{
    printf("Article Number = %d\n", (*data).articleNum);
    printf("Article Quantity = %d\n", (*data).articleQty);
    printf("Article Description = %s\n", (*data).articleDesc);
}

#endif  // end of include guard for ARTICLES_H