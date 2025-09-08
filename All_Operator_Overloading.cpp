#include <iostream>
#include <cmath> // For std::sqrt and std::pow

using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    // Constructor
    Vector2D(double dx = 0.0, double dy = 0.0) : x(dx), y(dy) {}

    // Public member functions to access private data
    double getX() const { return x; }
    double getY() const { return y; }

    // --- Unary Operator Overloading (Member Functions) ---

    // Overload unary minus (-)
    // Returns a new Vector2D with negated components.
    Vector2D operator-() const {
        return Vector2D(-x, -y);
    }

    // Overload pre-increment (++)
    // Modifies the current object and returns a reference to it.
    Vector2D& operator++() {
        ++x;
        ++y;
        return *this;
    }

    // Overload post-increment (++)
    // The 'int' parameter is a dummy to distinguish it from the pre-increment version.
    // It returns a copy of the object *before* the increment.
    Vector2D operator++(int) {
        Vector2D temp = *this;
        ++x;
        ++y;
        return temp;
    }

    // --- Binary Operator Overloading (Member Functions) ---

    // Overload addition (+)
    // Returns a new Vector2D object.
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // Overload subtraction (-)
    // Returns a new Vector2D object.
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    // Overload compound assignment (+=)
    // Modifies the current object and returns a reference to it.
    Vector2D& operator+=(const Vector2D& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    // --- Relational Operator Overloading (Member Functions) ---

    // Overload equality (==)
    bool operator==(const Vector2D& other) const {
        return (x == other.x) && (y == other.y);
    }

    // Overload inequality (!=)
    bool operator!=(const Vector2D& other) const {
        return !(*this == other); // Leverage the overloaded ==
    }

    // Overload less than (<) based on magnitude
    bool operator<(const Vector2D& other) const {
        double mag1 = sqrt(pow(x, 2) + pow(y, 2));
        double mag2 = sqrt(pow(other.x, 2) + pow(other.y, 2));
        return mag1 < mag2;
    }

    // --- Subscript Operator Overloading (Member Functions) ---

    // Non-const version for read/write access
    double& operator[](int index) {
        if (index == 0) return x;
        if (index == 1) return y;
        throw out_of_range("Vector2D subscript out of range");
    }

    // Const version for read-only access on const objects
    const double& operator[](int index) const {
        if (index == 0) return x;
        if (index == 1) return y;
        throw out_of_range("Vector2D subscript out of range");
    }

    // --- Stream Operator Overloading (Non-Member `friend` Functions) ---

    // The 'friend' keyword allows these functions to access private members.
    // Overload stream insertion (<<) for output.
    friend ostream& operator<<(ostream& os, const Vector2D& v);
    
    // Overload stream extraction (>>) for input.
    friend istream& operator>>(istream& is, Vector2D& v);
};

// Implementations for the non-member friend functions
ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

istream& operator>>(istream& is, Vector2D& v) {
    cout << "Enter x component: ";
    is >> v.x;
    cout << "Enter y component: ";
    is >> v.y;
    return is;
}

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    Vector2D v3;

    cout << "Initial vectors: v1 = " << v1 << ", v2 = " << v2 << endl;

    // 1. Binary Operator Overloading
    cout << "\n--- Binary Operators ---" << endl;
    v3 = v1 + v2;
    cout << "v1 + v2 = " << v3 << endl;
    v3 = v2 - v1;
    cout << "v2 - v1 = " << v3 << endl;
    
    v3 = Vector2D(5.0, 5.0);
    cout << "v3 is initially " << v3 << endl;
    v3 += v1;
    cout << "v3 after += v1 is " << v3 << endl;

    // 2. Unary Operator Overloading
    cout << "\n--- Unary Operators ---" << endl;
    Vector2D v4 = v1++; // Post-increment
    cout << "After v4 = v1++, v1 is now " << v1 << " and v4 is " << v4 << endl;
    
    Vector2D v5 = ++v2; // Pre-increment
    cout << "After v5 = ++v2, v2 is now " << v2 << " and v5 is " << v5 << endl;
    
    Vector2D v6 = -v1;
    cout << "v6 = -v1: " << v6 << endl;

    // 3. Relational Operator Overloading
    cout << "\n--- Relational Operators ---" << endl;
    cout << "v1 == v2? " << (v1 == v2 ? "Yes" : "No") << endl;
    Vector2D v1_copy(2.0, 3.0);
    cout << "v1 == v1_copy? " << (v1 == v1_copy ? "Yes" : "No") << endl;
    cout << "v1 < v2? " << (v1 < v2 ? "Yes" : "No") << endl; // Based on magnitude

    // 4. Subscript Operator Overloading
    cout << "\n--- Subscript Operator ---" << endl;
    try {
        cout << "v1[0] is " << v1[0] << endl;
        v1[1] = 10.0;
        cout << "v1 after v1[1] = 10.0 is " << v1 << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // 5. Stream I/O Operator Overloading
    cout << "\n--- Stream Operators ---" << endl;
    Vector2D v_input;
    cout << "Please enter a new vector:" << endl;
    cin >> v_input;
    cout << "You entered: " << v_input << endl;

    return 0;
}
