#include "complex.hpp"
#include <math.h>

complex::complex(double r, double i) :re{r}, im{i} {}

double complex::real() const { return re; }
double complex::imag() const { return im; }

void complex::real(double r) { re=r; }
void complex::imag(double i) { im=i; }

complex& complex::operator+=(complex z) {
    re += z.re;
    im += z.im;
    
    // Dereference the 'this' pointer and implicitly
    // convert to reference type 'complex&'.
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
    // This could be made slightly faster if z is the conjugate.
    double bottom = (pow(z.re, 2) + pow(z.im, 2));
    re = (re*z.re + im*z.im)/bottom;
    im = (im*z.re - re*z.im)/bottom;
    return *this;
}

// a and b are passed by value (copied) so a can be
// modified and used as the return value without affecting
// the copy of the caller.
complex operator+(complex a, complex b) { return a+=b; }
complex operator-(complex a, complex b) { return a-=b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; }
complex operator*(complex a, complex b) { return a*=b; }
complex operator/(complex a, complex b) { return a/=b; }

bool operator==(complex a, complex b) {
    return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(complex a, complex b) {
    return !(a==b);
}
