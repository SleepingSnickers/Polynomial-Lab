#include "Term.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//set default values
Term::Term() {
	coefficient = 0.0;
	exponent = 0;
	variable = 'a';
}

//alternative constructor
Term::Term(double coef, int exp, char var) {
	coefficient = coef;
	exponent = exp;
	variable = var;
}

//copy constructor
Term::Term(const Term& term) {
	coefficient = term.coefficient;
	exponent = term.exponent;
	variable = term.variable;
}

//setters and getters
double Term::getCoefficient() const {
	return coefficient;
}

void Term::setCoefficient(double coef) {
	coefficient = coef;
}

int Term::getExponent() const {
	return exponent;
}

void Term::setExponent(int exp) {
	exponent = exp;
}

char Term::getVariable() const {
	return variable;
}

void Term::setVariable(char var) {
	variable = var;
}

//test to confirm everything is different, then set the = operator
Term& Term::operator=(const Term& right) {
	if (this != &right) {
		coefficient = right.coefficient;
		exponent = right.exponent;
		variable = right.variable;
	}

	return *this;
}

//relational operators, setting left and right
bool Term::operator<= (const Term& right) const {
	return exponent <= right.exponent;
}

bool Term::operator>= (const Term& right) const {
	return exponent >= right.exponent;
}

bool Term::operator< (const Term& right) const {
	return exponent < right.exponent;
}

bool Term::operator> (const Term& right) const {
	return exponent > right.exponent;
}

bool Term::operator== (const Term& right) const {
	return exponent == right.exponent;
}

//checks that the two sides are compatible
bool Term::compatible(const Term& term) const {
	return exponent == term.exponent && variable == term.variable;
}