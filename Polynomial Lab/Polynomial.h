#ifndef POLYNOMIAL
#define POLYNOMIAL

#include "Term.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Polynomial
{
private:
	Term* terms;
	int numTerms;
	void simplify();

public:
    //default constructor
    Polynomial();
    //alternative constructors
    Polynomial(Term*, int);
    Polynomial(const Polynomial&);
    //destructor
    ~Polynomial();

    //relational operators
    Polynomial& operator=(const Polynomial&);
    Polynomial operator+(const Polynomial&);
    Polynomial operator-(const Polynomial&);
    Polynomial operator*(const Polynomial&);

    //setters/getters
    Term* getTerms() const;
    void setTerms(Term*, int);
    int getNumTerms() const;
    void setNumTerms(int);

    //make the ostream a friend
    friend ostream& operator<<(ostream&, const Polynomial&);
};


#endif
