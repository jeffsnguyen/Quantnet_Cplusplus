// Type: Homework
// Level: 8
// Section: Variants
// Exercise: 3
// Description: Test features of Boost library's variants
// In contrast to tuple, a boost::variant stores one value that can be of one of the specified types.
//  It is thus similar to a C union but it is type-safe.
// In this exercise we want to create a function that ask the user what kind of shape
//  to create and returns that. In this case we can return the created shape as Shape*
//  because all shapes have a common base class but that involves creating the shapes with new.
// Instead we can return the created shape a boost::variant which would also be needed
//  if the shapes did not have a common base class.
// Thus create a typedef for a ShapeType variant that can contain a Point, Line or Circle.
//  Next create a function that returns the variant. Within this function ask the user
//      for the shape type to create.
//  Then create the requested shape and assign it to the variant and return it.
// In the main program, call the function and print the result by sending it to cout.
// Next try to assign the variant to a Line variable by using the global boost:get<T>() function.
// This will throw a boost::bad_get exception when the variant didn’t contain a line.
// Test the application.
// Checking what kind a type is stored in the variant is cumbersome.
// Therefore the boost::variant supports visitors.
// A visitor is a class derived from boost::static_visitor<T>
//  that has for each type that can be stored an operator () with the type as argument.
// The template argument is the return type of the operators ().
// Now create a variant visitor that moves the shapes.
// The visitor is derived from boost::static_visitor<void>
//  and must have members for the x- and y-offset that are set in the constructor.
// For each shape, create an operator () that changes the coordinates of the shape.
// For example the function for Point is defined as:
// Visit a point.
//  void operator () (Point& p) const
//  {
//  p.X(p.X()+m_dx);
//  p.Y(p.Y()+m_dy);
//  }
// In the main program, create an instance of the visitor and use the boost::apply_visitor(visitor, variant)
//  global function to move the shape.
// Print the shape afterwards to check if the visitor indeed changed the coordinates.

/*---------------------------------*/

#include "boost/variant.hpp"
#include <iostream>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Visitor.hpp"


using namespace std;

typedef boost::variant<Point, Line, Circle> ShapeType;

/*---------------------------------*/
ShapeType shapeSelect()
{
    // Initialize
    ShapeType shape;
    char shapeSelectstr;  // To receive user answer

    cout << "Please choose the shape: (p)Point (l)Line (c)Circle" << endl;
    cin >> shapeSelectstr;

    // Assign correct variant based on user choice
    switch (shapeSelectstr)
    {
        // Default
        default:
        {
            shape = Point();
            cout << "Default Point selected." << endl;  // User prompt message
            break;
        }

        // Point
        case 'p':
        {
            shape = Point();
            cout << "Point selected." << endl;  // User prompt message
            break;
        }

        // Line
        case 'l':
        {
            shape = Line();
            cout << "Line selected." << endl;  // User prompt message
            break;
        }

        // Point
        case 'c':
        {
            shape = Circle();
            cout << "Circle selected." << endl;  // User prompt message
            break;
        }
    }

    return shape;
}

/*---------------------------------*/
int main()
{
    /*---------------------------------*/
    // User prompt to select shape and out put result
    ShapeType shape=shapeSelect();
    cout << "You selected: " << shape << endl;

    /*---------------------------------*/
    // Assign variant to line variable
    try
    {
        Line line = boost::get<Line>(shape);
    }
    catch (boost::bad_get& error)
    {
        cout << "Error: " << error.what() << " Variant did not contain a line. "<< endl;
    }

    /*---------------------------------*/
    // Test visitor

    // Init
    Visitor visitor(1, 1);
    ShapeType shape1 = Point();
    ShapeType shape2 = Line();
    ShapeType shape3 = Circle();

    // Move the shapes and print
    boost::apply_visitor(visitor, shape1);
    boost::apply_visitor(visitor, shape2);
    boost::apply_visitor(visitor, shape3);

    cout << "Shape1: " << shape1 << endl;
    cout << "Shape2: " << shape2 << endl;
    cout << "Shape3: " << shape3 << endl;

    return 0;
}



