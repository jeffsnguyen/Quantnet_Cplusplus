// Type: Homework
// Level: 7
// Section: STL Iterators
// Exercise: 2
// Description: Definition file contains Sum() functions
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
#ifndef Sum_HPP
#define Sum_HPP

#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

/*---------------------------------*/
// Sum elements for vector, list container
template <typename T>
double Sum(const T& container);

// Sum elements for vector, list container using a range begin and end iterator
template <typename T>
double Sum(const typename T::const_iterator& iterStart, const typename T::const_iterator& iterEnd);

// Sum elements for map container
template <typename T1, typename T2>
double Sum(const map<T1,T2>& map);

// Sum elements for map container using a range begin and end iterator
template <typename T1, typename T2>
double Sum(const typename map<T1,T2>::const_iterator& iterStart, const typename map<T1,T2>::const_iterator& iterEnd);

#endif // Sum_HPP