// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 3
// Description: Definition file contains class Shape()
// When objects are removed from memory, the destructor is called.
// When a derived class destructor is called,
//  it will automatically call the base class destructor.
// But when you have pointers to a base class, deleting objects might not be done correctly.
// If not done already, print some text in the destructors of the Shape, Point and Line classes.
// Then test the following code:
//  Shape* shapes[3];
//  shapes[0]=new Shape;
//  shapes[1]=new Point;
//  shapes[2]=new Line;
//  for (int i=0; i!=3; i++) delete shapes[i];
// Will the proper destructors (including the destructor of the Shape base class) be called?
// In this case, the derived class destructor
//  will only be called when the destructor is declared virtual in the base class.
// Do this in the Shape class and run the code again. Are the proper destructors called now?

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

    // Overloading operators
    Shape &operator=(const Shape &source); // Assignment operator.
    friend ostream &operator<<(ostream &os, const Shape &s); // Send to ostream.
};

#endif // Shape_HPP