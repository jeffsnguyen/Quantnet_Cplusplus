// Type: Homework
// Level: 4
// Section: 2.5 Namespaces
// Exercise: 1
// Description: Definition file contains class Array()
// To avoid name conflicts, programmers can place their classes in a namespace.
// For example the standard library is placed in a namespace called std.
// You should put your classes in your own namespace.
// Thus place the CAD classes (Shape,Point, Line, etc) in the namespace:
//  YourName::CAD
// Place the container classes (Array) in the namespace:
//  YourName::Containers Now access the classes in your own namespace using:
//  • Full class name including namespace for the Point used in the Array class.
//      Note that you can use only the CAD part of the namespace
//      without the YourName part because the Point is also in the YourName namespace.
//  • In the main program, the full namespace for Point class.
//  • In the main program, using declaration for using a single class (Line).
//  • In the main program, using declaration for a complete namespace (Containers).
//  • In the main program, using the Circle class by creating a shorter alias for the YourName::CAD namespace.

/*---------------------------------*/
#ifndef Array_HPP
#define Array_HPP

#include <iostream>
using namespace std;

/*---------------------------------*/
namespace Jeff
{
    namespace Containers
    {
        class Array
        {
        private:
            CAD::Point* m_data;  // Dynamic array of Point() objects
            int m_size;  // Size of above array

        public:
            // Constructors
            Array();  // Default constructor
            Array(int newSize);  // Initialize array with newSize number of elements
            Array(const Array& array);  // Copy constructor

            // Destructor
            ~Array();

            // Accessing functions
            const int& Size() const;  // Returns the size of the array
            void SetElement(int idx, const CAD::Point& point);  // Set an element of the array based on the index
            const CAD::Point& GetElement(int idx) const;  // Get an element based on its array index

            // Overloading operators
            Array& operator = (const Array& source); // Assignment operator.

            // Return a reference so the [] operator can be used for both reading and writing elements.
            // When the index is out of bounds, return the first element.
            CAD::Point& operator [] (int idx);
            const CAD::Point& operator [] (int idx) const;

        };
    }
}

#endif // Array_HPP