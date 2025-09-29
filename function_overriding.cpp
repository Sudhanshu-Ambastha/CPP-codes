#include <iostream>
using namespace std;

// Base Class
class Animal {
public:
    // The base class function MUST be virtual to allow derived classes
    // to override it and enable dynamic binding (runtime polymorphism).
    virtual void speak() const {
        cout << "Animal: The animal makes a generic sound.\n";
    }

    // A non-virtual function cannot be truly overridden polymorphically.
    void move() const {
        cout << "Animal: The animal moves using its limbs.\n";
    }

    virtual ~Animal() {
        // Virtual destructor for safety in polymorphic deletion
    }
};

// Derived Class
class Dog : public Animal {
public:
    // Function Overriding: Provides a specific implementation for the virtual function.
    // The 'override' keyword (C++11+) is optional but highly recommended.
    // It tells the compiler to check that the function signature exactly matches 
    // a virtual function in the base class.
    void speak() const override {
        cout << "Dog: Woof! Woof! (This is the OVERRIDDEN implementation).\n";
    }

    // This is NOT true overriding because the base function is not virtual.
    // It is technically HIDING the base function, not overriding it polymorphically.
    void move() const {
        cout << "Dog: The dog runs on four paws.\n";
    }
};

void demonstrate_overriding() {
    // 1. Standard Object
    Dog actual_dog;
    cout << "--- 1. Direct Object Call ---\n";
    actual_dog.speak(); // Calls Dog::speak()
    actual_dog.move();  // Calls Dog::move()
    
    cout << "\n--- 2. Polymorphic Pointer Call (Dynamic Binding) ---\n";
    
    // 2. Base Class Pointer pointing to Derived Class Object
    Animal* poly_ptr = new Dog();

    // A. Overridden Virtual Function Test (True Overriding)
    // The program executes the Dog::speak() function at RUNTIME.
    cout << "Virtual Speak: ";
    poly_ptr->speak(); 

    // B. Non-Virtual Function Test (Function Hiding/Static Binding)
    // The program executes the Animal::move() function at COMPILE TIME, 
    // based on the pointer type (Animal*). The Dog's 'move' is ignored.
    cout << "Non-Virtual Move: ";
    poly_ptr->move(); 
    
    // Cleanup
    delete poly_ptr;
}

int main() {
    demonstrate_overriding();
    return 0;
}