#include <iostream>
using namespace std;

class DeepCopyExample {
public:
    int* data;

    DeepCopyExample(int val) {
        data = new int(val);
        cout << "Constructor called. Data at " << data << endl;
    }

    // Custom Copy Constructor for deep copy
    DeepCopyExample(const DeepCopyExample& other) {
        data = new int(*other.data); // Allocate new memory and copy the value
        cout << "Deep Copy Constructor called. New data at " << data << endl;
    }

    ~DeepCopyExample() {
        delete data;
        cout << "Destructor called. Memory at " << data << " deallocated." << endl;
    }
    
    void display() {
        cout << "Value: " << *data << endl;
    }
};

int main() {
    DeepCopyExample original(10);
    DeepCopyExample copy = original; // Deep copy happens here

    cout << "--- After Deep Copy ---" << endl;
    cout << "Original's memory address: " << original.data << endl;
    cout << "Copy's memory address: " << copy.data << endl;

    // Modifying the copy does NOT affect the original
    *copy.data = 20;

    cout << "--- After modifying copy ---" << endl;
    original.display();
    copy.display();

    // The program will run without errors as each object has its own memory to delete.
    return 0;
}
