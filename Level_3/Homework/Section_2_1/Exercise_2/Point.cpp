// Type: Homework
// Level: 3
// Section: 2.2 The Class Concept
// Exercise: 2
// Description: Source file contains functionalities for class Point()
// In this exercise we are going to add distance functions to the Point class.
//  The distance functions have the following signature:
//      double DistanceOrigin(); // Calculate the distance to the origin (0, 0).
//      double Distance(Point p); // Calculate the distance between two points.
//  Add the definitions to the header file and implement the functions in the source file.
//  Use the std::sqrt() function from the “cmath” header file to implement the Pythagoras algorithm.
//  Extend the main program to print the distance between the origin and another point and test it.

/*---------------------------------*/
#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*---------------------------------*/
// Initializing (x,y) = (newX,newY)
Point::Point(double newX, double newY) : x(newX), y(newY)
{
}

// Destructor
Point::~Point()
{
	cout << "Point destroyed.\n";
}

// Get x value
double Point::GetX() const
{
	return x;
}

// Set new value for x
void Point::SetX(double newX)
{ 
	x = newX;
}

// Get y value
double Point::GetY() const
{
	return y;
}

// Set new value for y
void Point::SetY(double newY)
{ 
	y = newY;
}

// Return string description of the point
string Point::ToString() const
{
    // Declare stringstream objects
    stringstream xSTR, ySTR;

    // Insert inputs to stream
    xSTR << x;
    ySTR << y;

    return "Point(" + xSTR.str() + "," + ySTR.str() + ")";
}

// Calculate the distance to the origin (0, 0).
double DistanceOrigin()
{
    return sqrt(pow(x,2) + pow(y,2));
}

// Calculate the distance between two points.
double Distance(Point p)
{
    return sqrt(pow(x-p.GetX(),2) + pow(y-p.GetY(),2));
}
