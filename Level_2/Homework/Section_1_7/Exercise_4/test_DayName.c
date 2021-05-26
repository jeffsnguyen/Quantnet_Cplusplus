// Type: Homework
// Level: 2
// Section: 1.7 Pointers and Arrays
// Exercise: 4
// Description: Main file to test DayName() and include definition of DayName()
// Create a C-program that has a function DayName()
//  which can print the day of a given day-number.
//  For example:
//      1 gives: Day 1 is a Sunday
//      7 gives: Day 7 is a Saturday.
//  The day-name (1-7) should be written "hard-coded” into the program using an array of strings.

/*---------------------------------*/
#include <stdio.h>

/*---------------------------------*/
void DayName(idx)
{
    // Create a dayname array contains strings value of dates
    char daynameArr[7][10]={
                            "Sunday",
                            "Monday",
                            "Tuesday",
                            "Wednesday",
                            "Thursday",
                            "Friday",
                            "Saturday",
                            };
    printf("Name of the date index %d is %s.", idx, daynameArr[idx-1]);
}

int main()
{
    // Declare parameters dayIdx
    int dayIdx;

    // Input parameters dayIdx
    printf("Input an integer value from 1->7 = ");
    scanf("%d", &dayIdx);

    DayName(dayIdx);  // Run DayName() to output corresponded text value of the day index

    return 0;
}



