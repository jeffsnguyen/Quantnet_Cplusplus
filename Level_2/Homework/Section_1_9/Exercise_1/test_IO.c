// Type: Homework
// Level: 2
// Section: 1.9 Input and Output
// Exercise: 1
// Description: Main file to test onscreen input and output
// Create a C-program that reads the characters from the keyboard
//  and shows them on screen
//  (the inputted characters should only be displayed when the user hits 'enter', line by line).
//  When ^A is entered, the program must end properly.
//  Then the following message will appear:
//      “CTRL + A is a correct ending.”
//
//  Tip: getchar() reads and putchar() writes the type int. The value of ^A is 1.

/*---------------------------------*/
#include <stdio.h>

int main()
{
    // User prompt instruction
    printf("Enter characters below. Press 'Enter' to display and Ctrl+A to end.\n");

    // Declare and initialize variable to store the string
    char charInput;

    // Keep running input loop as long as it's not Ctrl+A
    while ((charInput=getchar()) != 1)
    {
        // if the input character is not "Enter", display it, else, go to the new line
        if (charInput != '\n')
        {
            putchar(charInput);
        }
        else
        {
            printf("\n");
        }
    }

    return 0;
}



