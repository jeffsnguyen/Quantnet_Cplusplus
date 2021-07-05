// Type: Homework
// Level: 7
// Section: STL Iterators
// Exercise: 2
// Description: Test features of STL algos
// Using iterators you can iterate a STL container without knowing which container it is.
// In this exercise you create a function that calculates the sum of a container with doubles.
//  • Create a template function called Sum() that accepts the template argument T as input
//      and returns a double. The template argument will be a container.
//  • In the implementation get an iterator (T::const_iterator) for the end.
//      Then create a loop that iterates the container T and adds all values. Finally return the sum.
//  • In the main program, call the Sum() function for the different container from the previous exercise.
// The Sum() function created calculates the sum of the complete container.
// Also create a Sum() function that calculates the sum between two iterators.
// The function then uses the template argument for the iterator type and accepts two iterators,
//  the start and end iterator.

/*---------------------------------*/

#include <iostream>
#include "Functor.hpp"
#include "Functor.cpp"
#include <list>


using namespace std;

// Check if a value is less than 3
bool lessThanThree(const double val)
{
    return val < 3;
}

/*---------------------------------*/
int main()
{
    /*---------------------------------*/
    // Create list and add some data
    list<double> list1;
    int a[10] = {12, 3, 25, 7, 11, 213, 7, 123, 29, -31};

    // List iterator
    for (int i = 0; i < 10; i++)
    {
        list1.push_back(a[i]);  // Adding elements from a to the back of the list container
    }

    // Test countif() for list using global function
    // Returns the number of element that is less than 3
    // Expect: 1 (from -31)
    cout << count_if(list1.begin(), list1.end(), lessThanThree) << endl;

    // Test countif() using Functor
    // Expect: 0
    Functor functor1(-31);
    cout << count_if(list1.begin(), list1.end(), functor1) << endl;

    return 0;
}



