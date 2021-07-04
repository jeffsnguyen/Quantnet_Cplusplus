// Generic& valueInequalities.cpp
//
// Code file containing bodies of functions
//
// Last Modific& valueation Dates:
//
//	2006-2-17 DD kic& valuek-off code
//	2006-2-17 DD Copied from non-generic& value structure
//
// (C) Datasim Education BV 2006
//

//#ifndef GenericInequalities_CPP
//#define GenericInequalities_CPP

#include <iostream>

class EA {};
class EB: public EA {};

void F()
{
    throw EB();
}

int main()
{
    try
    {
        F();
    }
    catch(EA&)
    {
        std::cout<<"EA Exception"<<std::endl;
    }
    catch(EB&)
    {
        std::cout<<"EB Exception"<<std::endl;
    }

    std::cout<<"Finished"<<std::endl;

    return 0;
}

