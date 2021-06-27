// Type: Homework
// Level: 6
// Section: 4.2a Advanced Templates
// Exercise: 5
// Description: Test file to test StackException() class with template
// When you use the Stack class and the stack is full or empty
//  when pushing or popping an element you get an exception from the Array class.
// Since the user of the Stack class does not know that an Array class is used internally,
//  you don’t want that the client must know about the array exceptions.
// Thus the array exception must be translated to a stack exception.
//  •The stack exception classes can be implemented in a header file only for simplicity.
//  •Create a StackException base class anda StackFullException and StackEmptyException derived class.
//  •In the Push() function of stack, place the code in a try ... catch block and catch the array exception.
//      In the catch handler, throw a StackFullException exception.
//  •In the Pop() function of stack, place the code in a try ... catch block and catch the array exception.
//      In the catch handler, throw a StackEmptyException exception.
//      Also set the current index back to 0.
//  •Change the test program so it catches the stack exception.

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
    Stack<int> stack1(2);  // Initialize stack of 2 integer elements

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
    Stack<int> stack2(2);
    stack2 = stack1;

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



