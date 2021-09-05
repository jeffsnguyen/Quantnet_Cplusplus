// Type: Homework
// Level: 9
// Section: 9A Exact Solutions of One-Factor Plain Options
// Description: Description of option methods


/*---------------------------------*/
#ifndef OptionExtras_HPP
#define OptionExtras_HPP

#include <vector>
using namespace std;

/*---------------------------------*/
// A simple mesher on a 1d domain
vector<double> GenerateMeshArray(double begin, double end, int n);

// Price of call with T, K, sig, r, U, b
double call_price(double T, double K, double sig, double r, double U, double b);

// Price of put with T, K, sig, r, U, b
double put_price(double T, double K, double sig, double r, double U, double b);

// Delta of call with T, K, sig, r, U, b
double call_delta(double T, double K, double sig, double r, double U, double b);

// Delta of put with T, K, sig, r, U, b
double put_delta(double T, double K, double sig, double r, double U, double b);

// Gamma of call with T, K, sig, r, U, b
double call_gamma(double T, double K, double sig, double r, double U, double b);

// Gamma of put with T, K, sig, r, U, b
double put_gamma(double T, double K, double sig, double r, double U, double b);

// Vega of call with T, K, sig, r, U, b
double call_vega(double T, double K, double sig, double r, double U, double b);

// Vega of put with T, K, sig, r, U, b
double put_vega(double T, double K, double sig, double r, double U, double b);

// Theta of call with T, K, sig, r, U, b
double call_theta(double T, double K, double sig, double r, double U, double b);

// Theta of put with T, K, sig, r, U, b
double put_theta(double T, double K, double sig, double r, double U, double b);

#endif // OptionExtras_HPP