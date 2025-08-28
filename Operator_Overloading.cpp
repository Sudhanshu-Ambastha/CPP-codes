#include <iostream>

using namespace std;

class Vector {
private:
    double x, y;

public:
    Vector(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Overloading the + operator
    Vector operator+(const Vector& other) const {
        return Vector(this->x + other.x, this->y + other.y);
    }

    void display() const {
        cout << "Vector(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Vector v1(1.0, 2.0);
    Vector v2(3.0, 4.0);

    // Using the overloaded + operator
    Vector v3 = v1 + v2;

    cout << "v1: ";
    v1.display();
    cout << "v2: ";
    v2.display();
    cout << "v3 = v1 + v2: ";
    v3.display();

    return 0;
}
