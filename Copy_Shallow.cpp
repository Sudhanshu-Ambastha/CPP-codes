#include <iostream>
using namespace std;

class ShallowCopyExample {
public:
    int* data;

    ShallowCopyExample(int val) {
        data = new int(val);
        cout << "Constructor called. Data at " << data << endl;
    }
    
    // Default copy constructor (compiler-generated)
    // Shallow copy occurs here
    
    ~ShallowCopyExample() {
        delete data;
        cout << "Destructor called. Memory at " << data << " deallocated." << endl;
    }
    
    void display() {
        cout << "Value: " << *data << endl;
    }
};

int main() {
    ShallowCopyExample original(10);
    ShallowCopyExample copy = original; // Shallow copy happens here

    cout << "--- After Shallow Copy ---" << endl;
    cout << "Original's memory address: " << original.data << endl;
    cout << "Copy's memory address: " << copy.data << endl;

    // Modifying the copy also modifies the original, as they point to the same memory
    *copy.data = 20;

    cout << "--- After modifying copy ---" << endl;
    original.display();
    copy.display();

    // The program will crash when the second object is destroyed,
    // as it tries to delete the same memory location twice.
    return 0;
}
