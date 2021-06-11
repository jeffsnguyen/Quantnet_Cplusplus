// Type: Homework
// Level: 5
// Section: 3.6 Exception Handling
// Exercise: 2
// Description: Definition file contains class Shape()
// Throwing an int is an easy solution.
// But exception handling is also object oriented and allows us to throw an object.
// In this exercise we will create an exception hierarchy
//  with an ArrayException base class and an OutOfBoundsExceptionderived class as shown in Figure 3:
//      •You can implement both exception classes in the header file for simplicity.
//      •Give the ArrayException an abstract GetMessage() function that returns a std::string.
//      •Give the OutOfBoundsException class a constructor with an int as argument
//          that indicates the erroneous array index and store it in a data member.
//      •Override the GetMessage() function
//          and let the implementation return a message string saying the given index is out of bounds.
//      •In the Array class, throw now a OutOfBoundsException object instead of an integer.
//      •Change the main program so that it catches the ArrayException base class
//          and uses the GetMessage() function to display an error message.

/*---------------------------------*/
#ifndef Shape_HPP
#define Shape_HPP

#include <iostream>

using namespace std;

/*---------------------------------*/
class Shape
{
private:
    int m_id;  // ID of objects in the Shape() class

public:
    // Constructors
    Shape();  // Default constructor
    Shape(int newID);  // Initialize with specific value
    Shape(const Shape &shape);  // Copy constructor

    // Destructor
    virtual ~Shape();
    //~Shape();

    // Accessing functions
    int ID() const;  // Retrieving the ID
    void ID(int newID);  // Setting the ID

    virtual string ToString() const;  // Return string description of the shape
    virtual void Draw() const = 0;  // Abstract function
    void Print() const;  // Template Method Pattern to Print derived class description via ToString()

    // Overloading operators
    Shape &operator=(const Shape &source); // Assignment operator.
    friend ostream &operator<<(ostream &os, const Shape &s); // Send to ostream.
};

#endif // Shape_HPP