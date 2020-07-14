// Interface for complex numbers, a simple algebraic type
// (a product type)

class complex {
    double re, im;
public:
    complex(double r, double i);
    complex(double r); // im=0
    complex(); // both 0

    // Use 'const' to make this a constant function, i.e. these
    // promise not to modify any members
    double real() const;
    double imag() const;

    void real(double r);
    void imag(double i);

    complex& operator+=(complex z);
    complex& operator-=(complex z);
    complex& operator*=(complex z);
    complex& operator/=(complex z);
};
