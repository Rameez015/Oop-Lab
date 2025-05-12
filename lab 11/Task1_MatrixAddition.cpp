#include <iostream>
#include <exception>
using namespace std;

class DimensionMismatchException : public exception {
    int rows1, cols1, rows2, cols2;
public:
    DimensionMismatchException(int r1, int c1, int r2, int c2)
        : rows1(r1), cols1(c1), rows2(r2), cols2(c2) {}
    const char* what() const noexcept override {
        return "DimensionMismatchException - Matrices must have same dimensions!";
    }
};

template <typename T>
class Matrix {
    int rows, cols;
    T** data;
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }
    void setElement(int r, int c, T value) {
        data[r][c] = value;
    }
    Matrix operator+(Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix<int> a(2, 2);
    Matrix<int> b(3, 3);
    try {
        Matrix<int> c = a + b;
    } catch (DimensionMismatchException& e) {
        cout << e.what() << " (2x2 vs 3x3)" << endl;
    }
    return 0;
}