#include "MatrixBase.h"
#include "MatrixNumerical.h"
#include <iostream>

using namespace std;

int main(){

    MatrixNumerical<double> M(3,3);

    M.addElement(0,0,1.2);
    M.addElement(0,1,2);
    M.addElement(0,2,3);
    M.addElement(1,0,4);
    M.addElement(1,1,5);
    M.addElement(1,2,6);
    M.addElement(2,0,7);
    M.addElement(2,1,8);
    M.addElement(2,2,9);

    cout << "M matrix: " << endl;
    M.Display();
    cout << endl;

    MatrixNumerical<double> N(3,3);

    N.addElement(0,0,1.2);
    N.addElement(0,1,2);
    N.addElement(0,2,3);
    N.addElement(1,0,4);
    N.addElement(1,1,5);
    N.addElement(1,2,6);
    N.addElement(2,0,7);
    N.addElement(2,1,8);
    N.addElement(2,2,9);

    cout << "N matrix: " << endl;
    N.Display();
    cout << endl;

    cout << "M + N: " << endl;
    (M+N).Display();
    cout << endl;

    cout << "M * N: " << endl;
    (M*N).Display();
    cout << endl;

    cout << "2*M: " << endl;
    (2*M).Display();
    cout << endl;

    cout << "M/N: " << endl;
    (M/N).Display();
    cout << endl;

    cout << "M's determinant: " << endl;
    cout << M.getDeterminant() << endl;
    cout << endl;

    cout << "M's inverse: " << endl;
    (M.getInverse()).Display();
    cout << endl;

    cout << "(M*N)'s inverse: " << endl;
    ((M*N).getInverse()).Display();
    cout << endl;

    cout << "getIdentity: " << endl;
    MatrixNumerical<double>::getIdentity(5).Display();
    cout << endl;

    return 0;
}