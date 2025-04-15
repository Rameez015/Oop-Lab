#include <iostream>
using namespace std;

class Vector2D {
private:
    int x, y;

public:
    Vector2D(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    Vector2D operator + (const Vector2D& v) {
        return Vector2D(x + v.x, y + v.y);
    }

    Vector2D operator - (const Vector2D& v) {
        return Vector2D(x - v.x, y - v.y);
    }

    Vector2D operator * (int scalar) {
        return Vector2D(x * scalar, y * scalar);
    }

    friend int dotProduct(const Vector2D& v1, const Vector2D& v2);

    friend ostream& operator << (ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }
};

int dotProduct(const Vector2D& v1, const Vector2D& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

int main() {
    Vector2D v1(2, 3), v2(4, 1);

    Vector2D sum = v1 + v2;
    Vector2D diff = v1 - v2;
    Vector2D scaled = v1 * 2;
    int dot = dotProduct(v1, v2);

    cout << "v1 + v2 = " << sum << endl;
    cout << "v1 - v2 = " << diff << endl;
    cout << "v1 * 2 = " << scaled << endl;
    cout << "Dot Product = " << dot << endl;

    return 0;
}