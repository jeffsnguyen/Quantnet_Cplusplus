// Type: Homework
// Level: 8
// Section: Random
// Exercise: 4
// Description: Test features of Boost library's random
// In this exercise we experiment with the exponential and Poisson distributions
//  that have many applications to queueing theory, scheduling and jump (Levy) processes in finance.
// Some typical examples of use are:
//      double scaleParameter = 0.5;
//      // Default type is 'double'
//      exponential_distribution<> myExponential(scaleParameter);
//      cout << "Mean:" << mean(myExponential)
//      << ",standard deviation: " << standard_deviation(myExponential) << endl;
//   and
//      double mean = 3.0;
//      poisson_distribution<double> myPoisson(mean);
//  Modify the code in the file “TestNormalDistribution.cpp” to work with
//      exponential distribution instead of normal distribution and Poisson distribution
//      instead of gamma distribution.

/*---------------------------------*/

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions.hpp>

#include <vector>
#include <iostream>
using namespace std;


int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;

	/*---------------------------------*/
	// Exponential Distribution
	double x = 10;
	double scaleParameter = 0.5;
	exponential_distribution<> myExponential(scaleParameter);

	// Other properties
	cout << "\n***Exponential distribution: \n";
	cout << "mean: " << mean(myExponential) << endl;
	cout << "variance: " << variance(myExponential) << endl;
	cout << "median: " << median(myExponential) << endl;
	cout << "mode: " << mode(myExponential) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
	cout << "kurtosis: " << kurtosis(myExponential) << endl;
	cout << "characteristic function: " << chf(myExponential, x) << endl;
	cout << "hazard: " << hazard(myExponential, x) << endl;

	/*---------------------------------*/
	// Poisson distribution
	//Passion distribution
	double avg = 3.0;
	poisson_distribution<double> myPoisson(avg);

	double val = 13.0;
	cout << "\n***Poisson distribution: \n";
	cout << "pdf: " << pdf(myPoisson, val) << endl;
	cout << "cdf: " << cdf(myPoisson, val) << endl;
	cout << "mean: " << mean(myPoisson) << endl;
	cout << "variance: " << variance(myPoisson) << endl;
	cout << "median: " << median(myPoisson) << endl;
	cout << "mode: " << mode(myPoisson) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myPoisson) << endl;
	cout << "kurtosis: " << kurtosis(myPoisson) << endl;
	cout << "skewness: " << skewness(myPoisson) << endl;
	cout << "characteristic function: " << chf(myPoisson, val) << endl;
	cout << "hazard: " << hazard(myPoisson, val) << endl;
	cout << "\n\n " << endl;

	vector<double> pdfList;
	vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myPoisson, val));
		cdfList.push_back(cdf(myPoisson, val));

		val += h;
	}

	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", ";

	}

	cout << "***" << endl;

	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", ";

	}

	return 0;
}