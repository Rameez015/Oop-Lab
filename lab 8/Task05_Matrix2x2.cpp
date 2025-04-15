#include <iostream>
using namespace std;

class Matrix2x2 {
private:
    int a, b, c, d;

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    Matrix2x2 operator + (const Matrix2x2& m) {
        return Matrix2x2(a + m.a, b + m.b, c + m.c, d + m.d);
    }

    Matrix2x2 operator - (const Matrix2x2& m) {
        return Matrix2x2(a - m.a, b - m.b, c - m.c, d - m.d);
    }

    Matrix2x2 operator * (const Matrix2x2& m) {
        return Matrix2x2(
            a * m.a + b * m.c, a * m.b + b * m.d,
            c * m.a + d * m.c, c * m.b + d * m.d
        );
    }

    friend int determinant(const Matrix2x2& m);

    friend class MatrixHelper;

    friend ostream& operator << (ostream& out, const Matrix2x2& m) {
        out << "[" << m.a << " " << m.b << "]\n[" << m.c << " " << m.d << "]";
        return out;
    }
};

int determinant(const Matrix2x2& m) {
    return m.a * m.d - m.b * m.c;
}

class MatrixHelper {
public:
    void updateElement(Matrix2x2& m, int pos, int value) {
        switch(pos) {
            case 1: m.a = value; break;
            case 2: m.b = value; break;
            case 3: m.c = value; break;
            case 4: m.d = value; break;
        }
    }
};

int main() {
    Matrix2x2 m1(1, 2, 3, 4), m2(5, 6, 7, 8);
    Matrix2x2 sum = m1 + m2;
    Matrix2x2 prod = m1 * m2;

    cout << "Sum:\n" << sum << endl;
    cout << "Product:\n" << prod << endl;
    cout << "Determinant of m1: " << determinant(m1) << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 1, 10);
    cout << "Updated m1:\n" << m1 << endl;

    return 0;
}