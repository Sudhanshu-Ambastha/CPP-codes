#include <iostream>
using namespace std;

// Base Class
class Shape {
public:
    // 1. NON-VIRTUAL FUNCTION: Uses Static Binding
    // The compiler binds the function call based on the pointer type.
    void draw() {
        cout << "Shape::draw() - Performing Static Binding (Default behavior).\n";
    }

    // 2. VIRTUAL FUNCTION: Uses Dynamic Binding
    // The compiler generates code to look up the correct function at runtime.
    virtual void calculate_area() {
        cout << "Shape::calculate_area() - Base class implementation.\n";
    }
    
    // Virtual destructor is good practice when dealing with inheritance and dynamic memory
    virtual ~Shape() {
        // Simple destructor implementation
    }
};

// Derived Class
class Circle : public Shape {
public:
    // Overrides the base class non-virtual function
    void draw() {
        cout << "Circle::draw() - Drawing a specific circle.\n";
    }

    // Overrides the base class virtual function
    void calculate_area() override {
        cout << "Circle::calculate_area() - Calculating Pi * r * r (Dynamic Binding).\n";
    }
};

void demonstrate_binding() {
    // --- Scenario 1: Static Binding Demonstration ---
    cout << "--- 1. STATIC BINDING (Non-Virtual Function: draw) ---\n";
    
    // Create a Circle object
    Circle c;

    // A. Direct Call (Bound to Circle::draw at compile time)
    c.draw(); 

    // B. Pointer Call (Crucial Test)
    // The pointer type is 'Shape*', so the compiler binds to Shape::draw() at compile time.
    Shape* shape_ptr = &c;
    shape_ptr->draw(); 
    // CHALLENGE POINT: Even though the object IS a Circle, the Shape::draw() runs!
    
    
    // --- Scenario 2: Dynamic Binding Demonstration ---
    cout << "\n--- 2. DYNAMIC BINDING (Virtual Function: calculate_area) ---\n";

    // A. Direct Call (Same as static, bound to Circle::calculate_area)
    c.calculate_area(); 

    // B. Pointer Call (Crucial Test)
    // The pointer type is 'Shape*', but because the function is virtual,
    // the program looks at the actual object's VTABLE at RUNTIME.
    Shape* shape_ptr_2 = &c;
    shape_ptr_2->calculate_area();
    // RESULT: The correct Circle::calculate_area() runs!
}

int main() {
    demonstrate_binding();
    return 0;
}