// Type: Homework
// Level: 9
// Section: 9A Exact Solutions of One-Factor Plain Options
// Description: Source file contains functionalities for class Option()

/*---------------------------------*/
#include "Option.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

// Initialize default values
void Option::Init()
{
    optionType = "Call";
}

// Copy all values
void Option::Copy(const Option& source)
{
    optionType = source.optionType;
}

// Default constructor
Option::Option()
{
    Init();
}

// Copy constructor
Option::Option(const Option& source)
{
    optionType = source.optionType;
}

// Constructor with option type
Option::Option(const string& newOptionType)
{
    optionType = newOptionType;
}

// Destructor
Option::~Option()
{
}

// Assignment operator
Option& Option::operator = (const Option& source)
{
    if (this == &source)  // check if source  is the same as this object
        {
        return *this;  // if similar, return directly
        }
    optionType = source.optionType;  // assign option type of source

    return *this;
}

// Functions that calculate option prices
double Option::Price() const
{
    if (optionType == "Call")  // if the option type is "Call"
        {
        return CallPrice();  // call function CallPrice to get the result
        }
    else  // if the option type is "Put"
    {
        return PutPrice();  // call function PutPrice to get the result
    }
}

// Functions that calculate delta sensitivities
double Option::Delta() const
{
    if (optionType == "Call")  // if the option type is "Call"
    {
        return CallDelta();  // call function CallDelta to get the result
    }
    else  // if the option type is "Put"
    {
        return PutDelta();  // call function PutDelta to get the result
    }
}

// Functions that calculate gamma sensitivities
double Option::Gamma() const
{
    if (optionType == "Call")  // if the option type is "Call"
    {
        return CallGamma();  // call function CallGamma to get the result
    }
    else  // if the option type is "Put"
    {
        return PutGamma();  // call function PutGamma to get the result
    }
}

// Functions that calculate vega sensitivities
double Option::Vega() const
{
    if (optionType == "Call")  // if the option type is "Call"
    {
        return CallVega();  // call function CallVega to get the result
    }
    else  // if the option type is "Put"
    {
        return PutVega();  // call function PutVega to get the result
    }
}

// Functions that calculate theta sensitivities
double Option::Theta() const
{
    if (optionType == "Call")  // if the option type is "Call"
    {
        return CallTheta();  // call function CallTheta to get the result
    }
    else  // if the option type is "Put"
    {
        return PutTheta();  // call function PutTheta to get the result
    }
}

// Modifier functions to change option type
void Option::toggle()
{
    optionType = ((optionType == "Call") ? "Put" : "Call");
}

double Option::CallDelta() const  // Delta of call
{
    cout << "Not define " << endl;
    return 0;
}

double Option::PutDelta() const  // Delta of put
{
    cout << "Not define " << endl;
    return 0;
}

double Option::CallGamma() const  // Gamma of call
{
    cout << "Not define " << endl;
    return 0;
}

double Option::PutGamma() const  // Gamma of put
{
    cout << "Not define " << endl;
    return 0;
}

double Option::CallVega() const  // Vega of call
{
    cout << "Not define " << endl;
    return 0;
}

double Option::PutVega()const  // Vega of put
{
    cout << "Not define " << endl;
    return 0;
}

double Option::CallTheta() const  // Theta of call
{
    cout << "Not define " << endl;
    return 0;
}

double Option::PutTheta() const  // Theta of put
{
    cout << "Not define " << endl;
    return 0;
}