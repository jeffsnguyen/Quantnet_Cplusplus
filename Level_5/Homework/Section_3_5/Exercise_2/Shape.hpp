// Type: Homework
// Level: 5
// Section: 3.5 Polymorphism
// Exercise: 2
// Description: Definition file contains class Shape()
// The ToString() function of the Shape class is overridden in the derived classes.
// But for the derived class it is still possible to use the base class functionality.
// In the ToString() function of Point and Line we also want to incorporate the ID from theShape base class.
//  •In the ToString() method of Point,
//      call the ToString() method of the Shape base class:std::string s=Shape::ToString();
//  •Append the shape description string to the point description string before returning.
//  •Do this also for the ToString() function in the Line class (and Circle class).
//  •Test the application again. Is now the ID printed when printing a point or line?

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

    // Accessing functions
    int ID() const;  // Retrieving the ID
    void ID(int newID);  // Setting the ID

    virtual string ToString() const;  // Return string description of the shape

    // Overloading operators
    Shape &operator=(const Shape &source); // Assignment operator.
    friend ostream &operator<<(ostream &os, const Shape &s); // Send to ostream.
};

#endif // Shape_HPP