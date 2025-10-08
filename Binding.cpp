#include <iostream>

using namespace std;

// Base class
class Shape {
public:
    // 1. Early Binding (Static Dispatch) - Non-virtual function
    void identify() const {
        cout << "Shape::identify() -> I am a generic Shape. (Early Bound)" << endl;
    }

    // 2. Late Binding (Dynamic Dispatch) - Virtual function
    virtual void draw() const {
        cout << "Shape::draw() -> Drawing a generic shape." << endl;
    }
    
    // Crucial for proper destruction in polymorphic classes
    virtual ~Shape() = default; 
};

// Derived class
class Circle : public Shape {
public:
    // Overriding the Early Bound function (hiding, not true overriding)
    void identify() const {
        cout << "Circle::identify() -> I am a Circle. (Still Early Bound)" << endl;
    }

    // Overriding the Late Bound virtual function
    void draw() const override {
        cout << "Circle::draw() -> Drawing a Circle! (Late Bound)" << endl;
    }
};

int main() {
    Circle c;
    Shape* sPtr = &c; // Upcasting: Base pointer points to a Derived object

    cout << "--- Early Binding (Static Dispatch) Demonstration ---" << endl;
    
    // The compiler determines which 'identify' to call based on the POINTER TYPE (Shape*), 
    // NOT the actual object type (Circle). This is early binding.
    sPtr->identify(); // Calls Shape::identify()

    // Calling directly on the object variable uses the object's type.
    c.identify();     // Calls Circle::identify()
    
    cout << "\n--- Late Binding (Dynamic Dispatch) Demonstration ---" << endl;

    // The function call is resolved at RUNTIME based on the actual object 
    // the pointer points to (the Circle object). This is late binding.
    sPtr->draw(); // Calls Circle::draw() because 'draw' is virtual

    // If sPtr pointed to a new Shape object, it would call Shape::draw() at runtime.
    Shape s;
    Shape* anotherPtr = &s;
    anotherPtr->draw(); // Calls Shape::draw()
    
    return 0;
}
