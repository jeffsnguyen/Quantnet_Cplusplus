// TestAggregates.cpp
//
// Defining aggregate structures. We model data that pertains to
// plain options. The struct can be used in pricing algorithms as a 
// simple data store.
//
// DJD
//

#include <iostream>

void Swap(int& a, int& b)
{
int tmp=a;
a=b;
b=tmp;
}

int main()
{
    int i1=10;
    int i2=20;

    Swap(i1, i2);

    std::cout<<"i1="<<i1<<", i2="<<i2<<std::endl;
}
