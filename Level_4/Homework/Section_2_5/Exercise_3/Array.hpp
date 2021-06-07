// Type: Homework
// Level: 4
// Section: 2.5 The Free Store
// Exercise: 3
// Description: Definition file contains class Array()
// It is easy to forget to delete memory created with new.
// A good practice is to let a class manage memory.
// Then the client of that class does not have to manage memory and can’t forget to delete memory.
// So instead of creating a C array with new, you can use an array class that handle memory for you.
// In this exercise we are going to create an array class for Point objects (see Figure 5):
//  • Add a source- and header file for the Array class to your current project.
//  • Add a data member for a dynamic C array of Point objects (Point* m_data).
//  • Add a data member for the size of the array.
//  • Add a default constructor that allocates for example 10 elements.
//  • Add a constructor with a size argument. The implementation should allocate
//      the number of elements specified by thesize input argument.
//  • Add a copy constructor. Keep in mind that just copying the C array pointer
//      will create an Array object that shares the data with the original Array object.
//      Thus you need to allocate a new C array with the same size and copy each element separately.
//  • Add a destructor. It should delete the internal C array. Don’t forget the square brackets.
//  • Add an assignment operator.
//      Keep in mind you can’t copy only the C array pointers just as in the case of the copy constructor.
//  • Also don’t forget to delete the old C array and
//      allocate new memory before copying the elements. This is because C arrays can’t grow.
//
//  Further check if the source object is not the same as the this object.
//  If you don’t check it, then a statement like arr1=arr1 will go wrong.
//  The internal C array will then be deleted before it is copied.
//  • Add a Size() function that returns the size of the array.
//  • Add a SetElement() function that sets an element.
//      When the index is out of bounds, ignore the “set”. We will add better error handling later.
//  • Add a GetElement() function.
//      You can return the element by reference since the returned element
//      has a longer lifetime than the GetElement() function.
//      When the index is out of bounds, return the first element.
//      We will add better error handling later.
//  • You can also add a square bracket operator.
//      Return a reference so the [] operator can be used for both reading and writing elements.
//      When the index is out of bounds, return the first element. We will add better error handling later.
//          Point& operator [] (int index);
//  • In the main program, test the Array class.

/*---------------------------------*/
#ifndef Array_HPP
#define Array_HPP

#include <iostream>
using namespace std;

/*---------------------------------*/
class Array
{
private:
	Point* m_data;  // Dynamic array of Point() objects
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
    void SetElement(int idx, const Point& point);  // Set an element of the array based on the index
    const Point& GetElement(int idx) const;  // Get an element based on its array index

    // Overloading operators
    Array& operator = (const Array& source); // Assignment operator.

    // Return a reference so the [] operator can be used for both reading and writing elements.
    // When the index is out of bounds, return the first element.
    Point& operator [] (int idx);
    const Point& operator [] (int idx) const;

};

#endif // Array_HPP