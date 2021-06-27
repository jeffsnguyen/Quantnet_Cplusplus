// Type: Homework
// Level: 6
// Section: 4.2a Advanced Templates
// Exercise: 6
// Description: Test file to test StackException() class with template
// Not only generic types can act as template variable.
// You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument
//  to set the stack size (remove the constructor with size):
//      template <typename T, int size> class Stack {};
//  Note that now only stacks with the same size template argument can be copied/assigned.

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
#include "StackException.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"
#include <iostream>

using namespace std;

/*---------------------------------*/
int main()
{
    Stack<int, 2> stack1;  // Initialize stack of 2 integer elements

    /*---------------------------------*/
    // Test Push function
    stack1.Push(10);
    stack1.Push(11);

    // Push out of bound, this is expected throw a stack full exception
    try
    {
        stack1.Push(12);
    }
    catch (StackException& stackEx)
    {
        cout << stackEx.GetMessage() << endl;
    }

    /*---------------------------------*/
    // Test assignment function
    Stack<int, 2> stack2;
    stack2 = stack1;

    Stack<int, 3> stack3;
    //stack3 = stack1;  // Error because not the same size

    /*---------------------------------*/
    // Test Pop function
    stack1.Pop();
    stack1.Pop();

    // Pop out of bound, this is expected to throw a stack empty exception
    try
    {
        stack1.Pop();
    }
    catch (StackException& stackEx)
    {
        cout << stackEx.GetMessage() << endl;
    }

    return 0;
}



