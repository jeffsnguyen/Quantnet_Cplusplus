// Type: Homework
// Level: 8
// Section: Smart Pointers
// Exercise: 1
// Description: Test features of STL containers
// When we want to store different kind of shapes in the Array<T> class we created earlier,
//  we need to store Shape* in the array.
//  But when we are finished, we need to delete all shapes in the array explicitly which is easy to forget.
//  The boost::shared_ptr<T> class stores a pointer and will delete the object automatically
//  when nobody is referencing the object anymore.
//  Thus instead of creating an array of Shape* we can create an array with boost::shared_ptr<Shape>
//      and the deletion of the shapes will be done automatically.
//  Thus create a program that creates an array with shared pointers for shapes
//      (The template array class and shape hierarchy was created in earlier exercises).
//  Fill it with various shapes and print them. Check if the shapes are automatically deleted.
//  Tip:
//      Use the following typedefs to simplify the code:
//        // Typedef for a shared pointer to shape and
//        // a typedef for an array with shapes stored as shared pointers.
//          typedef boost::shared_ptr<Shape> ShapePtr;
//          typedef Array<ShapePtr> ShapeArray;

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



