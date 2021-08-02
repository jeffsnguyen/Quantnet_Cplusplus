// Type: Homework
// Level: 8
// Section: Tuple
// Exercise: 1
// Description: Test features of STL containers
// Boost tuples can be used to store different kinds of data as one entity. It can be used if we need to combine data without the need to create a separate class.
//In this exercise, create a typedef for a Person tuple that contains a name, age and length. Also create a function that prints the person tuple. Use the get<T>() member functions the retrieve the data. Create a few person tuple instances and print them.
//Also increment the age of one of the persons. Note that to change a value of one of the tuple elements, you can also use the get<T>() function since it returns a reference to the value.

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



