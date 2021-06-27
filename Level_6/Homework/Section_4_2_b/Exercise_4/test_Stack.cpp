// Type: Homework
// Level: 6
// Section: 4.2a Advanced Templates
// Exercise: 4
// Description: Test file to test Stack() class with template
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
#include "Point.hpp"
#include "Point.cpp"
#include "Line.hpp"
#include "Line.cpp"
#include "Circle.hpp"
#include "Circle.cpp"
#include "Array.hpp"
#include "Array.cpp"
#include "Shape.hpp"
#include "Shape.cpp"
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
#include "NumericArray.hpp"
#include "NumericArray.cpp"
#include "PointArray.hpp"
#include "PointArray.cpp"
#include "Stack.hpp"
#include "Stack.cpp"
#include <iostream>

using namespace std;

/*---------------------------------*/
int main()
{
    Stack<int> stack1(2);  // Initialize stack of 2 integer elements

    /*---------------------------------*/
    // Test Push function
    stack1.Push(10);
    stack1.Push(11);

    // Push out of bound, this is expected throw an exception of index 2
    try
    {
        stack1.Push(12);
    }
    catch (ArrayException& oobEx)
    {
        cout << oobEx.GetMessage() << endl;
    }

    /*---------------------------------*/
    // Test assignment function
    Stack<int> stack2(2);
    stack2 = stack1;

    /*---------------------------------*/
    // Test Pop function
    stack1.Pop();
    stack1.Pop();

    // Pop out of bound, this is expected to throw an exception of index 0
    try
    {
        stack1.Pop();
    }
    catch (ArrayException& oobEx)
    {
        cout << oobEx.GetMessage() << endl;
    }

    return 0;
}



