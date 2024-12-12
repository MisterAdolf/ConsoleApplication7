#include <iostream>
#include <cmath>

using namespace std;

class Vector3D {
private:
    double x, y, z;

public:
    Vector3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    Vector3D& operator++() {
        ++x; ++y; ++z;
        return *this;
    }

    Vector3D operator++(int) {
        Vector3D temp = *this;
        ++(*this);
        return temp;
    }

    Vector3D& operator--() {
        --x; --y; --z;
        return *this;
    }

    Vector3D operator--(int) {
        Vector3D temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const Vector3D& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    Vector3D& operator=(const Vector3D& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }

    bool operator>(const Vector3D& other) const {
        return magnitude() > other.magnitude();
    }

    bool operator>=(const Vector3D& other) const {
        return magnitude() >= other.magnitude();
    }

    bool operator<(const Vector3D& other) const {
        return magnitude() < other.magnitude();
    }

    bool operator<=(const Vector3D& other) const {
        return magnitude() <= other.magnitude();
    }

    friend ostream& operator<<(ostream& os, const Vector3D& vec) {
        os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return os;
    }

private:
    double magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }
};

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    bool operator==(const Vector3D& vec3) const {
        return x == vec3.x && y == vec3.y && vec3.z == 0;
    }

    bool operator!=(const Vector3D& vec3) const {
        return !(*this == vec3);
    }

    friend ostream& operator<<(ostream& os, const Vector2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

int main() {
    Vector3D vec3_1(1, 2, 3), vec3_2(4, 5, 6);
    Vector2D vec2_1(1, 2), vec2_2(3, 4);

    cout << "Vector3D addition: " << vec3_1 + vec3_2 << endl;
    cout << "Vector3D subtraction: " << vec3_1 - vec3_2 << endl;

    cout << "Prefix increment: " << ++vec3_1 << endl;
    cout << "Postfix increment: " << vec3_1++ << endl;
    cout << "After postfix increment: " << vec3_1 << endl;

    cout << "Vector2D addition: " << vec2_1 + vec2_2 << endl;
    cout << "Vector2D == Vector3D: " << (vec2_1 == vec3_1) << endl;

    return 0;
}