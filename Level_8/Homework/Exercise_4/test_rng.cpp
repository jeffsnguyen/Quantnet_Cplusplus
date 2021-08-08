// Type: Homework
// Level: 8
// Section: Random
// Exercise: 4
// Description: Test features of Boost library's random
// In this example we simulate dice throwing.
// We use functionality in Random library by creating
//  a discrete uniform random number generator whose outcomes are in the closed range [1,6]:
//      //Throwing dice.
//      //Mersenne Twister.
//      boost::random::mt19937 myRng;
//      // Set the seed.
//      myRng.seed(static_cast<boost::uint32_t> (std::time(0)));
//      // Uniform in range [1,6]
//      boost::random::uniform_int_distribution<int> six(1,6);
//
// We now create a map that holds the frequency of each outcome:
//      map<int, long> statistics; // Structure to hold outcome + frequencies
//      int outcome; // Current outcome
//
// A typical outcome is generated as follows:
//      outcome = six(myRng);
// This will generate a number in the range [1,6].
// Answer the following questions:
//  a) Generate a large number of trials and place their frequencies in map.
//  b) Produce the following kind of output:
//      How many trials? 1000000
//      Trial 1 has 16.6677% outcomes
//      Trial 2 has 16.6551% outcomes
//      Trial 3 has 16.6881% outcomes
//      Trial 4 has 16.7103% outcomes
//      Trial 5 has 16.6273% outcomes
//      Trial 6 has 16.6515% outcomes

/*---------------------------------*/

#include "boost/random.hpp"
#include <iostream>
#include <map>

using namespace std;

/*---------------------------------*/
int main()
{
    /*---------------------------------*/
    // Throwing dice.
    // Mersenne Twister.
    boost::random::mt19937 myRng;

    // Set the seed.
    myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

    // Uniform in range [1,6]
    boost::random::uniform_int_distribution<int> six(1,6);

    map<int, long> statistics; // Structure to hold outcome + frequencies
    int outcome;

    // Init a larger number of trials
    int num = 1000000;

    // Simulate tossing dies
    for (int i = 0; i < num; i++)
    {
        outcome = six(myRng);  // Randomly generate imt in the range[1,6]
        statistics[outcome]+=1;  // Update output
    }

    // Print Results
    for (int i = 1; i <= 6; i++)
    {
        cout << "Trial " << i << " has " << (double)statistics[i] / (double)num * 100 << "% outcomes" << endl;
    }

    return 0;
}



