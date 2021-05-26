// Type: Homework
// Level: 2
// Section: 1.9 Input and Output
// Exercise: 2
// Description: Main file to test file input and output
// Create a C-program that reads the characters from the keyboard
//  and shows them on screen
//  (the inputted characters should only be displayed when the user hits 'enter', line by line).
//  When ^A is entered, the program must end properly.
//  Then the following message will appear:
//      “CTRL + A is a correct ending.”
//
//  Tip: getchar() reads and putchar() writes the type int. The value of ^A is 1.
//
//  Alter the last program in such a way that the output doesn’t go to the screen but is written to a file.
//  The file to write to must be specified by the user.

/*---------------------------------*/
#include <stdio.h>
#define FNAME_LENGTH 20

int main()
{
    // Get file name
    char fname[FNAME_LENGTH];  // Declare and initialize filename variable
    printf("Please specify file name to write to: ");
    fgets(fname, FNAME_LENGTH, stdin);  // Get user's input of preferred filename
    printf("Your file name is %s", fname);

    // Open the file
    FILE* f = fopen(fname, "w");  // Open file f in write mode

    // User prompt instruction
    printf("Enter characters below. Press Ctrl+A to end.\n");

    // Declare and initialize variable to store the string
    char charInput;

    // Keep running input loop as long as it's not Ctrl+A
    while ((charInput=getchar()) != 1)
    {
        fputc(charInput, f);
    }

    // Close file and prompt user
    fclose(f);
    printf("File input successful at %s", fname);

    return 0;
}



