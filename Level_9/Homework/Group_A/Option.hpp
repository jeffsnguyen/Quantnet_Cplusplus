// Type: Homework
// Level: 9
// Section: 9A Exact Solutions of One-Factor Plain Options
// Description: Description of the Option class


/*---------------------------------*/
#ifndef Option_HPP
#define Option_HPP

#include <string>
using namespace std;

/*---------------------------------*/
class Option
{
private:
    virtual double CallPrice() const = 0;
    virtual double PutPrice() const = 0;
    virtual double CallDelta() const ;
    virtual double PutDelta() const ;
    virtual double CallGamma() const ;
    virtual double PutGamma() const ;
    virtual double CallVega() const ;
    virtual double PutVega() const ;
    virtual double CallTheta() const ;
    virtual double PutTheta() const ;

public:
    string  optionType; // Option type, call or put

    virtual void Init(); // Initialize all default values
    virtual void Copy(const Option& source); // Copy all values

    Option(); // Default constructor
    Option(const string& optionType); // Constructor with type
    Option(const Option& source); // Copy constructor
    virtual ~Option(); // Destructor

    // Assignment operator
    Option& operator = (const Option& source);

    // Calculate Greeks
    double Price() const;
    double Delta() const;
    double Gamma() const;
    double Vega() const;
    double Theta() const;

    // Modifier functions
    void toggle(); // Change option type
};

#endif // Option_HPP