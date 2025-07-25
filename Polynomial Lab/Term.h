#ifndef TERM
#define TERM

#include <iostream>

using namespace std;

class Term
{
private:
	double coefficient;
	int exponent;
	char variable;

public:
	//default constructor
	Term();
	//constructor overload
	Term(double, int, char);
	//copy constructor
	Term(const Term&);

	//getter/setter for coefficient
	double getCoefficient() const;
	void setCoefficient(double);

	//getter/setter for exponent
	int getExponent() const;
	void setExponent(int);

	//getter/setter for variable
	char getVariable() const;
	void setVariable(char);

	//= overload
	Term& operator=(const Term&);

	//relational operator overloads
	bool operator<=(const Term&) const;
	bool operator>=(const Term&) const;
	bool operator<(const Term&) const;
	bool operator>(const Term&) const;
	bool operator==(const Term&) const;
	//exponent and variable match
	bool compatible(const Term&) const;
};


#endif
