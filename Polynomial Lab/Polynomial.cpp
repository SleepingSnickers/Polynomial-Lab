#include "Polynomial.h"
#include "Term.h"

#include <iostream>

using namespace std;

//I had to get some help for this function (*cough* chatgpt im sorry)
void Polynomial::simplify() {
    for (int i = 0; i < numTerms; ++i) {
        for (int j = i + 1; j < numTerms; ++j) {
            if (terms[i].compatible(terms[j])) {
                terms[i].setCoefficient(terms[i].getCoefficient() + terms[j].getCoefficient());
                for (int k = j; k < numTerms - 1; ++k)
                    terms[k] = terms[k + 1];
                --numTerms;
                --j;
            }
        }
    }
}

//default constructor
Polynomial::Polynomial() {
    numTerms = 0;
    terms = nullptr;
}

//alternate constructor, goes thru all of the values in terms and sets it to the class terms. sets the parameters terms and numTerms
Polynomial::Polynomial(Term* terms, int numTerms) {
    this->numTerms = numTerms;
    
    this->terms = new Term[numTerms];

    for (int i = 0; i < numTerms; ++i) {
        this->terms[i] = terms[i];
    }

    simplify();
}

//constructor setting the Polynomial& poly
Polynomial::Polynomial(const Polynomial& poly) {
    numTerms = poly.numTerms;

    terms = new Term[numTerms];
    for (int i = 0; i < numTerms; i++) {
        terms[i] = poly.terms[i];
    }
}

//destructor
Polynomial::~Polynomial() {
    delete[] terms;
}

//getters/setters
Term* Polynomial::getTerms() const {
    return terms;
}

//pointer has to go thru each of the array values, just like the above constructor
void Polynomial::setTerms(Term* terms, int size) {
    delete[] this->terms;

    this->terms = new Term[size];

    for (int i = 0; i < size; i++) {
        this->terms[i] = terms[i];
    }

    numTerms = size;

    simplify();
}

int Polynomial::getNumTerms() const {
    return numTerms;
}

void Polynomial::setNumTerms(int numTerms) {
    this->numTerms = numTerms;
}

//relational operator overloads
Polynomial& Polynomial::operator=(const Polynomial& right) {
    if (this != &right) {
        delete[] terms;
        numTerms = right.numTerms;
        terms = new Term[numTerms];
        for (int i = 0; i < numTerms; ++i)
            terms[i] = right.terms[i];
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& right) {
    int newSize = numTerms + right.numTerms;
    Term* combinedTerms = new Term[newSize];
    for (int i = 0; i < numTerms; ++i)
        combinedTerms[i] = terms[i];
    for (int j = 0; j < right.numTerms; ++j)
        //I cannot figure out why it's upset
        combinedTerms[numTerms + j] = right.terms[j];

    Polynomial result(combinedTerms, newSize);
    delete[] combinedTerms;
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& right) {
    Term* negated = new Term[right.numTerms];
    for (int i = 0; i < right.numTerms; ++i) {
        negated[i] = Term(-right.terms[i].getCoefficient(), right.terms[i].getExponent(), right.terms[i].getVariable());
    }
    Polynomial result = *this + Polynomial(negated, right.numTerms);
    delete[] negated;
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& right) {
    int totalTerms = numTerms * right.numTerms;
    Term* productTerms = new Term[totalTerms];
    int index = 0;

    //had help with this as well
    for (int i = 0; i < numTerms; ++i) {
        for (int j = 0; j < right.numTerms; ++j) {
            double coef = terms[i].getCoefficient() * right.terms[j].getCoefficient();
            int exp = terms[i].getExponent() + right.terms[j].getExponent();
            //same here, it's prbly simple but I'm not sure
            productTerms[index++] = Term(coef, exp, terms[i].getVariable());
        }
    }

    Polynomial result(productTerms, totalTerms);
    delete[] productTerms;
    return result;
}

ostream& operator<< (ostream& out, const Polynomial& poly) {
    for (int i = 0; i < poly.numTerms; ++i) {
        const Term& t = poly.terms[i];
        out << t.getCoefficient() << t.getVariable();
        if (t.getExponent() != 1) out << "^" << t.getExponent();
        if (i != poly.numTerms - 1) out << " + ";
    }
    return out;
}