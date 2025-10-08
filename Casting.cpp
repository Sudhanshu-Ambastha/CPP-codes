#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function to enable polymorphism and dynamic_cast
    virtual void speak() const {
        cout << "Animal makes a sound." << endl;
    }
    virtual ~Animal() = default; // Important for proper cleanup
};

// Derived class 1
class Dog : public Animal {
public:
    void speak() const override {
        cout << "Dog barks: Woof!" << endl;
    }
    void fetch() const {
        cout << "Dog is fetching a ball." << endl;
    }
};

// Derived class 2 (to show the risk of unsafe downcasting)
class Cat : public Animal {
public:
    void speak() const override {
        cout << "Cat meows: Meow!" << endl;
    }
};

void processAnimal(Animal* a) {
    cout << "\n--- Processing Animal: " << endl;
    a->speak();

    // 1. Upcasting Example: Not explicit, as 'a' is already a Base class pointer
    // The call a->speak() demonstrates polymorphic behavior
    // If 'a' pointed to a Dog object, it was implicitly upcast when assigned to Animal*

    // 2. Downcasting Example (Unsafe static_cast for demonstration)
    // We want to access the derived class's unique method (fetch)

    // A. Safe Downcasting Check (Preferred in real code, but requires RTTI and virtual functions)
    if (Dog* d_safe = dynamic_cast<Dog*>(a)) {
        cout << "  (Downcast success via dynamic_cast)" << endl;
        d_safe->fetch(); // Safe to call Dog-specific method
    } else {
        cout << "  (Downcast failed, object is not a Dog)" << endl;
    }

    // B. Unsafe Downcasting (Using static_cast for contrast - DANGEROUS!)
    // If 'a' points to a Cat, this will lead to UNDEFINED BEHAVIOR
    // Dog* d_unsafe = static_cast<Dog*>(a);
    // d_unsafe->fetch(); // <-- This would crash or corrupt memory if 'a' was a Cat*
}

int main() {
    // Upcasting Demonstration

    // Create a Derived class object
    Dog myDog;

    // Upcasting (Implicit): A Dog* is implicitly converted to an Animal*
    Animal* animalPtr = &myDog;
    cout << "--- Upcasting Demonstration: " << endl;
    cout << "A Dog* is assigned to an Animal* (Implicit Upcasting)." << endl;
    animalPtr->speak(); // Calls Dog::speak() because 'speak' is virtual

    // Downcasting Demonstration

    // Valid case: The Animal* actually points to a Dog object
    processAnimal(animalPtr);

    // Invalid case: The Animal* points to a Cat object
    Cat myCat;
    Animal* anotherAnimalPtr = &myCat;
    processAnimal(anotherAnimalPtr); // Downcasting attempt inside processAnimal will fail
    
    return 0;
}
