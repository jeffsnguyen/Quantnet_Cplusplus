// Type: Homework
// Level: 8
// Section: Smart Pointers
// Exercise: 3
// Description: Test features of Boost library's variants
// In contrast to tuple, a boost::variant stores one value that can be of one of the specified types. It is thus similar to a C union but it is type-safe.
//In this exercise we want to create a function that ask the user what kind of shape to create and returns that. In this case we can return the created shape as Shape* because all shapes have a common base class but that involves creating the shapes with new. Instead we can return the created shape a boost::variant which would also be needed if the shapes did not have a common base class.
//Thus create a typedef for a ShapeType variant that can contain a Point, Line or Circle. Next create a function that returns the variant. Within this function ask the user for the shape type to create. Then create the requested shape and assign it to the variant and return it.
//In the main program, call the function and print the result by sending it to cout. Next try to assign the variant to a Line variable by using the global boost:get<T>() function. This will throw a boost::bad_get exception when the variant didn’t contain a line.
//Test the application.
//Checking what kind a type is stored in the variant is cumbersome. Therefore the boost::variant supports visitors. A visitor is a class derived from boost::static_visitor<T> that has for each type that can be stored an operator () with the type as argument. The template argument is the return type of the operators ().
//Now create a variant visitor that moves the shapes. The visitor is derived from boost::static_visitor<void> and must have members for the x- and y-offset that are set in the constructor. For each shape, create an operator () that changes the coordinates of the shape. For example the function for Point is defined as:
//// Visit a point.
//void operator () (Point& p) const
//{
//p.X(p.X()+m_dx);
//p.Y(p.Y()+m_dy);
//}
//In the main program, create an instance of the visitor and use the boost::apply_visitor(visitor, variant) global function to move the shape. Print the shape afterwards to check if the visitor indeed changed the coordinates.

/*---------------------------------*/

#include "boost/shared_ptr.hpp"
#include <iostream>
#include "Array.hpp"
#include "ArrayException.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "NumericArray.hpp"
#include "Point.hpp"
#include "Shape.hpp"


using namespace std;

typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

/*---------------------------------*/
int main()
{
    /*---------------------------------*/
    // Initialize array with 3 shapes
    ShapeArray shapeArr(3);

    // Test creation of different shapes
    // Point
    shapeArr[0] = ShapePtr(new Point(1,1));
    shapeArr[0]->Print();

    // Line
    shapeArr[1] = ShapePtr(new Line(Point(1,1), Point(2,2)));
    shapeArr[1]->Print();

    // Circle
    shapeArr[2] = ShapePtr(new Circle(Point(1,1), 1));
    shapeArr[2]->Print();

    /*---------------------------------*/
    // Check reference count
    cout << shapeArr[0].use_count() << endl;
    cout << shapeArr[1].use_count() << endl;
    cout << shapeArr[2].use_count() << endl;

    return 0;
}



