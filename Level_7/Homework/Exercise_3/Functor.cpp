// Type: Homework
// Level: 7
// Section: STL Iterators
// Exercise: 3
// Description: Description file contains Functor() function
// STL already contains many algorithms that work with containers.
// Use the count_if algorithm to count the number of elements smaller than a certain number.
// The count_if function accepts a functor.
// Thus pass it a global function that checks the double input is smaller than a certain value.
// Replace the global checking function, by a function object.
// This is a class that overload the round bracket operator
//  that in this case has the same signature and functionality as the global function you created previously.
// Only in this case the value to check for should not be a ‘literal’ value,
//  but taken from a data member that was set in the constructor of the function object.


/*---------------------------------*/
#ifndef Functor_CPP
#define Functor_CPP

#include "Functor.hpp"
#include <iostream>

using namespace std;

/*---------------------------------*/
// Default constructor
Functor::Functor(): flag(0)
{
    cout << "Default functor created" << endl;
}

// Initialize functor with newFlag value
Functor::Functor(double newFlag): flag(newFlag)
{
    cout << "Functor created." << endl;
}

// Copy constructor
Functor::Functor(const Functor& functor): flag(functor.flag)
{
    cout << "Copy constructor called." << endl;
}

// Destructor
Functor::~Functor()
{
    cout << "Functor destroyed." << endl;
}

// Overloading operators
// Assignment operator.
Functor& Functor::operator = (const Functor& source)
{
// Self-assignment preclusion
    if (this == &source)
    {
        return *this;
    }
    else
    {
        flag = source.flag;

        return *this;  // Assign the result to itself
    }
}

bool Functor::operator () (const double newFlag)
{
    return newFlag < flag;  // check if newFlag is less than flag
}



#endif // Functor_CPP