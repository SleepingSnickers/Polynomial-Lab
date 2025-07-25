#include "Polynomial.h"
#include "Term.h"

#include <iostream>

using namespace std;

int main() {
    Term t1(2.0, 2, 'x');
    Term t2(3.0, 1, 'x');
    Term t3(4.0, 0, 'x');
    Term terms1[] = { t1, t2, t3 };

    Polynomial p1(terms1, 3);
    cout << "Polynomial 1: " << p1 << endl;

    Polynomial p2 = p1;
    cout << "Copy of Polynomial 1: " << p2 << endl;

    Polynomial sum = p1 + p2;
    cout << "Sum: " << sum << endl;

    Polynomial diff = p1 - p2;
    cout << "Difference: " << diff << endl;

    Polynomial prod = p1 * p2;
    cout << "Product: " << prod << endl;

    return 0;
}