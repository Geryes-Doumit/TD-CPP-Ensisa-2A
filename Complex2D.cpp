#include "Complex2D.h"

Complex2D::Complex2D():re(0), im(0), theta(0), modulus(0)
{}

Complex2D::Complex2D(double real, double imaginary):re(real), im(imaginary) {
    theta = atan(im/re);
    modulus = sqrt(pow(re, 2) + pow(im, 2));
}

Complex2D::Complex2D(double ri):re(ri), im(ri) {
    theta = atan(1);
    modulus = abs(ri);
}

Complex2D::Complex2D(Complex2D const &c):re(c.re), im(c.im), theta(c.theta), modulus(c.modulus)
{}

void Complex2D::setRe(double real) {
    re = real;
    theta = atan(im/re);
    modulus = sqrt(pow(re, 2) + pow(im, 2));
}

void Complex2D::setIm(double imaginary) {
    im = imaginary;
    theta = atan(im/re);
    modulus = sqrt(pow(re, 2) + pow(im, 2));
}

double Complex2D::getRe() const {
    return re;
}

double Complex2D::getIm() const {
    return im;
}

double Complex2D::getModulus() const {
    return modulus;
}

double Complex2D::getTheta() const {
    return theta;
}

Complex2D Complex2D::getConjugate() const {
    return Complex2D(re, -im);
}

Complex2D Complex2D::getInverse() const {
    return (1/pow(modulus,2))*getConjugate();
}

Complex2D Complex2D::getRotated(double angle) {
    double new_angle = theta + angle;
    return modulus*Complex2D(cos(new_angle), sin(new_angle));
}

Complex2D operator + (Complex2D const &a, const Complex2D &b) {
    return Complex2D(a.re + b.re, a.im + b.im);
}

Complex2D operator - (Complex2D const &a, const Complex2D &b) {
    return Complex2D(a.re - b.re, a.im - b.im);
}

Complex2D operator * (Complex2D const &a, const Complex2D &b) {
    return Complex2D((a.re*b.re - a.im*b.im), (a.re*b.im + a.im*b.re));
}

Complex2D operator * (double const d, const Complex2D &a) {
    return Complex2D(d*a.re, d*a.im);
}

Complex2D operator / (Complex2D const &a, const Complex2D &b) {
    return a*b.getInverse();
}

bool operator < (Complex2D const &a, const Complex2D &b) {
    return a.modulus < b.modulus;
}

bool operator > (Complex2D const &a, const Complex2D &b) {
    return a.modulus > b.modulus;
}

string Complex2D::to_string() const {
    string separator = (im < 0) ? " - " : " + ";
    return std::to_string(re) + separator + std::to_string(abs(im)) + "·i";
}

void Complex2D::printAllInfo() const {
    string theta_str = std::to_string(theta);
    string modulus_str = std::to_string(modulus);

    cout << to_string() << endl
         << "theta: " << theta_str << endl
         << "modulus: " << modulus_str << endl;
}

ostream& Complex2D::printOn (ostream& os) const {
    os << to_string() << endl;
    return os;
}

ostream& Complex2D::printAllInfoOn (ostream& os) const {
    string theta_str = std::to_string(theta);
    string modulus_str = std::to_string(modulus);

    os << to_string() << endl
       << "theta: " << theta_str << endl
       << "modulus: " << modulus_str << endl;
    return os;
}