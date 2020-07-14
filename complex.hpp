// Interface for complex numbers (with doubles),
// a simple arithmetic (product) type.

class complex {
    double re, im;
public:
    complex(double r=0, double i=0);

    // Use 'const' to make this a constant function, i.e. these
    // promise not to modify any members.
    double real() const;
    double imag() const;

    void real(double r);
    void imag(double i);

    // These composite operators are used as fundamental
    // rather than the {+, -, *, /} operators because they
    // are simpler: no need for temporaries. A good optimizing
    // compiler will inline these.
    complex& operator+=(complex z);
    complex& operator-=(complex z);
    complex& operator*=(complex z);
    complex& operator/=(complex z);    
};

// The following operations don't need access
// to complex's representation, so they are outside the class.
// Stroustrup recommends this in TC++PL.
complex operator+(complex a, complex b);
complex operator-(complex a, complex b);
complex operator-(complex a); // unary minus
complex operator*(complex a, complex b);
complex operator/(complex a, complex b);
bool operator==(complex a, complex b);
bool operator!=(complex a, complex b);
