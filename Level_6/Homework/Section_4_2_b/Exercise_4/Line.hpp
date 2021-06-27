// Type: Homework
// Level: 6
// Section: 4.2b Advanced Templates
// Exercise: 4
// Description: Definition file contains class Line()
// In this exercise we will make a Stack class. For the data storage we can use the Array class.
// Deriving from Array is not a good idea because there is no relation between Array and Stack.
// The stack would then inherit indexed operations which should not be a functionality of a stack.
// But we can use the Array class as a data member as shown in Figure 4:
//  •Add a new source and header file for the Stack class to your project.
//  •Create a template class called Stack.
//      It is not a derived class but it uses an Array as data member.
//      You also need a data member for the current index in the array.
//  •Create the regular constructors, destructor and assignment operator.
//  •Add a Push() function.
//      It should store the element at the current position in the embedded array.
//      Increment the current position afterwards.
//      There is no need for checking the current index because the array
//          will throw an exception when the stack is full.
//      Make sure the current index is not changed when the Array class threw an exception.
//  •Add a Pop() function that decrements the current position
//      and then returns the element at that position.
//      Make sure the current index is not changed when the Array class throws an exception.
//  •Change the main function to test the stack.
// Using another class as data member is called composition.
// In this case the Stack class uses internally an Array class.
// Forwarding functionality to another class is called delegation.
// Here the Stack class delegates the storage of elements to the Array class.


/*---------------------------------*/
#ifndef Line_HPP
#define Line_HPP

#include <iostream>
#include "Point.hpp"
#include "Shape.hpp"

using namespace std;

/*---------------------------------*/
class Line : public Shape
{
private:
    Point P1;  // point 1
    Point P2;  // point 2

public:
    // Constructors
    Line();  // Default constructor
    Line(Point &newP1, Point &newP2);  // Initialize with start and end points
    Line(const Line &line);  // Copy constructor

    // Destructor
    virtual ~Line();

    // Accessing functions
    Point point1() const;  // The start point
    void point1(const Point &newP1);

    Point point2() const;  // The end point
    void point2(const Point &newP2);

    string ToString() const;  // Return string description of the line
    double Length() const;  // Calculate the length of the line
    void Draw() const;  // Overidden function from Shape() simulating drawing by printing some text

    // Overloading Operator
    Line &operator=(const Line &source); // Assignment operator.
    friend ostream &operator<<(ostream &os, const Line &l); // Send to ostream.
};

#endif // Line_HPP