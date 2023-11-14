#ifndef COMPLEX2D_H
#define COMPLEX2D_H

#include <iostream>
#include <cmath>
using namespace std;

class Complex2D {
    private:
        double re;
        double im;
        double theta;
        double modulus;

    public:
        Complex2D();
        Complex2D(double, double);
        Complex2D(double);
        Complex2D(Complex2D const&);

        void setRe(double);
        void setIm(double);
        double getRe() const;
        double getIm() const;
        double getModulus() const;
        double getTheta() const;
        
        Complex2D getConjugate() const;
        Complex2D getInverse() const;
        Complex2D getRotated(double angle);

        friend Complex2D operator + (const Complex2D &a, const Complex2D &b);
        friend Complex2D operator - (Complex2D const &a, Complex2D const &b);
        friend Complex2D operator * (Complex2D const &a, Complex2D const &b);
        friend Complex2D operator * (double const d, const Complex2D &a);
        friend Complex2D operator / (Complex2D const &a, Complex2D const &b);
        friend bool      operator < (Complex2D const &a, Complex2D const &b);
        friend bool      operator > (Complex2D const &a, Complex2D const &b);

        string to_string() const;
        void printAllInfo() const;
        ostream& printOn(ostream&) const;
        ostream& printAllInfoOn(ostream&) const;
};

#endif