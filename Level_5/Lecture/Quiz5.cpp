	// TestPayoff.cpp
//
// Testing the one-factor payoff classes
//
// (C) Datasim Education BV 1998 - 2005
//

#include <iostream>

    class A
    {
    public:
        std::string F() { return "A"; }
    };

    class B: public A
    {
    public:
        std::string F() { return "B"; }
    };

    int main()
    {
        A a; B b;
        A* ap;

        std::cout<<a.F()<<", ";
        std::cout<<b.F()<<", ";

        ap=&a; std::cout<<ap->F()<<", ";
        ap=&b; std::cout<<ap->F()<<std::endl;

        return 0;
    }
