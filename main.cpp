#include <iostream>
#include <cmath>
using namespace std;

#include "Complex2D.h"

int main() {
    Complex2D c(3, 5);
    Complex2D c2(6, 3);

    cout << "c  = ";
    c.printAllInfo();
    cout << endl;
    cout << "c2 = ";
    c2.printAllInfo();
    cout << endl;

    // Testing the methods

    cout << "c.getConjugate()" << endl;
    c.getConjugate().printAllInfo();
    cout << endl;

    cout << "c.getInverse()" << endl;
    c.getInverse().printAllInfo();
    cout << endl;

    cout << "c.getRotated(pi/4)" << endl;
    c.getRotated(M_PI/4).printAllInfo();
    cout << endl;

    cout << "c + c2" << endl;
    (c + c2).printAllInfo();
    cout << endl;

    cout << "c - c2" << endl;
    (c - c2).printAllInfo();
    cout << endl;

    cout << "c * c2" << endl;
    (c * c2).printAllInfo();
    cout << endl;

    cout << "c / c2" << endl;
    (c / c2).printAllInfo();
    cout << endl;

    cout << "c < c2 (compares the absolute values)" << endl;
    cout << to_string(c < c2) << endl;
    cout << endl;
    
    cout << "c > c2 (compares the absolute values)" << endl;
    cout << to_string(c > c2) << endl;
    cout << endl;
    
    return 0;
}