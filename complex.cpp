#include "complex.hpp"
#include <math.h>

complex::complex(double r, double i) :re{r}, im{i} {}
complex::complex(double r) :re{r}, im{0} {}
complex::complex() :re{0}, im{0} {}

double complex::real() const { return re; }
double complex::imag() const { return im; }

void complex::real(double r) { re=r; }
void complex::imag(double i) { im=i; }

complex& complex::operator+=(complex z) {
    re += z.re;
    im += z.im;
    
    // Dereference the 'this' pointer and implicitly
    // convert to reference type 'complex&'
    return *this;
}

complex& complex::operator-=(complex z) {
    re -= z.re;
    im -= z.im;
    return *this;
}

complex& complex::operator*=(complex z) {
    // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
    re = re*z.re - im*z.im;
    im = re*z.im + im*z.re;
    return *this;
}

complex& complex::operator/=(complex z) {
    // (a + bi)/(c + di) =
    // (ac + bd)/(c^2 + d^2) + i(bc - ad)/(c^2 + d^2)
    // could be made slightly faster if z is the conjugate
    double bottom = (pow(z.re, 2) + pow(z.im, 2));
    re = (re*z.re + im*z.im)/bottom;
    im = (im*z.re - re*z.im)/bottom;
    return *this;
}
