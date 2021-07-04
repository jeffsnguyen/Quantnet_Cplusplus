// Type: Homework
// Level: 7
// Section: STL Containers
// Exercise: 1
// Description: Test features of STL containers
// One of the features of STL are the containers.
// In this exercise you will practice with the different STL containers. In the main program:
//  • Create a list of doubles and add some data.
//      Use the front() and back() functions to access the first and last element.
//  • Create a vector of doubles and add some data.
//      Then use the index operator to access some elements. Also make the vector grow.
//  • Create a map that maps strings to doubles.
//      Fill the map and access elements using the square bracket operator.

/*---------------------------------*/

#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

/*---------------------------------*/
int main()
{
    // Test list container functionality
    /*---------------------------------*/
    // Create list and add some data
    list<double> list1;
    int a[10] = {12, 3, 25, 7, 11, 213, 7, 123, 29, -31};

    // List iterator
    for (int i = 0; i < 10; i++)
    {
        list1.push_back(a[i]);  // Adding elements from a to the back of the list container
    }

    // Print first element of list
    // Expect: 12
    cout << "First element of container = " << list1.front() << endl;

    // Print last element of list
    // Expect: -31
    cout << "Last element of container = " << list1.back() << endl;

    // Test vector container functionalities
    /*---------------------------------*/
    vector<double> vector1;

    // Adding data to the vector
    for (int i = 0; i < 4; ++i)
    {
        vector1.push_back(i+1.3);
        cout << "Added vector[" << i << "] = " << i+1.3 << endl;
    }

    // Access elements of vector using index operator
    cout << "vector[1] = " << vector1[1] << endl;

    // Test map container functionalities
    /*---------------------------------*/
    map<string, double> map1;

    // Adding data to the map
    map1["hello"] = 0.1234;
    map1["world"] = 1.2345;

    // Accessing map
    cout << "map1[hello] = " << map1["hello"] << endl;

    return 0;
}



