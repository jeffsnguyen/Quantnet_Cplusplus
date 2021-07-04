// Type: Homework
// Level: 7
// Section: STL Iterators
// Exercise: 2
// Description: Test features of STL containers
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
#include "Sum.hpp"
#include "Sum.cpp"


using namespace std;

/*---------------------------------*/
int main()
{
    // Test Sum() for list
    /*---------------------------------*/
    // Create list and add some data
    list<double> list1;
    int a[10] = {12, 3, 25, 7, 11, 213, 7, 123, 29, -31};

    // List iterator
    for (int i = 0; i < 10; i++)
    {
        list1.push_back(a[i]);  // Adding elements from a to the back of the list container
    }

    // Print sum of elements of list using container param
    cout << "Sum of list container = " << Sum(list1) << endl;

    // Test Sum() for vector
    /*---------------------------------*/
    vector<double> vector1;

    // Adding data to the vector
    for (int i = 0; i < 4; ++i)
    {
        vector1.push_back(i+1.3);
        cout << "Added vector[" << i << "] = " << i+1.3 << endl;
    }

    // Declare start and end of vector
    vector<double>::const_iterator iterStart = vector1.begin();
    vector<double>::const_iterator iterEnd = vector1.end();

    // Print sum of elements of vector using begin and end iterator params
    cout << "Sum of vector container = " << Sum<vector<double>>(iterStart, iterEnd) << endl;

    // Test map container functionalities
    /*---------------------------------*/
    map<string, double> map1;

    // Adding data to the map
    map1["hello"] = 0.1234;
    map1["world"] = 1.2345;

    // Print sum of elements of map using container param
    cout << "Sum of map container = " << Sum(map1) << endl;

    // Declare start and end of vector
    map<string, double>::const_iterator iterStart_map = map1.begin();
    map<string, double>::const_iterator iterEnd_map = map1.end();

    // Print sum of elements of map using begin and end iterator params
    cout << "Sum of map container = " << Sum<string, double>(iterStart_map, iterEnd_map) << endl;

    return 0;
}



