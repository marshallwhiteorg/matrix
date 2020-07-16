// Interface for complex numbers (with doubles),
// a simple arithmetic (product) type.

// Scalar T.
template <typename T>
class complex {
    double re, im;
public:
    complex(T r=0, T i=0);

    // Use 'const' to make this a constant function, i.e. these
    // promise not to modify any members.
    T real() const;
    T imag() const;

    void real(T r);
    void imag(T i);

    // These composite operators are used as fundamental
    // rather than the {+, -, *, /} operators because they
    // are simpler: no need for temporaries. A good optimizing
    // compiler will inline these.
    complex& operator+=(complex z);
    complex& operator-=(complex z);
    complex& operator*=(complex z);
    complex& operator/=(complex z);

    complex operator+(complex a);
    complex operator-(complex a);
    complex operator-(); // unary minus
    complex operator*(complex a);
    complex operator/(complex a);
    bool operator==(complex a);
    bool operator!=(complex a);

};
