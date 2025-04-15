#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    Complex operator + (const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator - (const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator * (const Complex& c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    Complex operator / (const Complex& c) {
        double denom = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denom, 
                       (imag * c.real - real * c.imag) / denom);
    }

    friend ostream& operator << (ostream& out, const Complex& c) {
        out << "(" << c.real << " + " << c.imag << "i)";
        return out;
    }

    friend double magnitude(const Complex& c);
};

double magnitude(const Complex& c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

int main() {
    Complex a(3, 4), b(1, 2);
    Complex c = a + b;
    Complex d = a - b;
    Complex e = a * b;
    Complex f = a / b;

    cout << "a + b = " << c << endl;
    cout << "a - b = " << d << endl;
    cout << "a * b = " << e << endl;
    cout << "a / b = " << f << endl;
    cout << "Magnitude of a: " << magnitude(a) << endl;

    return 0;
}