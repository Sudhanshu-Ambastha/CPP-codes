#include <iostream>

using namespace std;

// Base class
class Shape {
public:
    double area;

    void calculateArea() {
        cout << "Calculating area..." << endl;
    }
};

// Derived class 1
class Circle : public Shape {
private:
    double radius;

public:
    void getDetails() {
        cout << "Enter radius of the circle: ";
        cin >> radius;
    }

    void calculateArea() {
        area = 3.14 * radius * radius;
        cout << "Area of Circle: " << area << endl;
    }
};

// Derived class 2
class Square : public Shape {
private:
    double side;

public:
    void getDetails() {
        cout << "Enter side length of the square: ";
        cin >> side;
    }

    void calculateArea() {
        area = side * side;
        cout << "Area of Square: " << area << endl;
    }
};

int main() {
    Circle c;
    Square s;

    cout << "--- Hierarchical Inheritance Example ---" << endl;
    
    cout << "\n--- Circle ---" << endl;
    c.getDetails();
    c.calculateArea();

    cout << "\n--- Square ---" << endl;
    s.getDetails();
    s.calculateArea();
    
    return 0;
}
