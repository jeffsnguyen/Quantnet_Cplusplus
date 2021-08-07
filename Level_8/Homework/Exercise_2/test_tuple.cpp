// Type: Homework
// Level: 8
// Section: Tuple
// Exercise: 2
// Description: Test features of Boost's library tuple
// Boost tuples can be used to store different kinds of data as one entity.
// It can be used if we need to combine data without the need to create a separate class.
// In this exercise, create a typedef for a Person tuple that contains a name, age and length.
// Also create a function that prints the person tuple.
// Use the get<T>() member functions the retrieve the data.
// Create a few person tuple instances and print them.
// Also increment the age of one of the persons.
// Note that to change a value of one of the tuple elements,
//  you can also use the get<T>() function since it returns a reference to the value.

/*---------------------------------*/

#include "boost//tuple/tuple.hpp"
#include "boost/tuple/tuple_io.hpp"
#include <iostream>
#include <string>

using namespace std;

typedef boost::tuple<string, int, double> Person;

/*---------------------------------*/
int main()
{
    /*---------------------------------*/
    // Initialize different persons
    Person ppl1 = boost::make_tuple(string("Person 1"), 67, 200);
    Person ppl2 = boost::make_tuple(string("Person 2"), 77, 20);
    Person ppl3 = boost::make_tuple(string("Person 3"), 76, 2);

    // Display persons info
    cout << "Name: " << ppl1.get<0>() << ", age: " << ppl1.get<1>() << ", length: " << ppl1.get<2>() << endl;
    cout << "Name: " << ppl2.get<0>() << ", age: " << ppl2.get<1>() << ", length: " << ppl2.get<2>() << endl;
    cout << "Name: " << ppl3.get<0>() << ", age: " << ppl3.get<1>() << ", length: " << ppl3.get<2>() << endl;

    // Increment length of person 2 and reprint
    ppl2.get<2>() = 2000;
    cout << "Name: " << ppl2.get<0>() << ", age: " << ppl2.get<1>() << ", length: " << ppl2.get<2>() << endl;
    return 0;
}



