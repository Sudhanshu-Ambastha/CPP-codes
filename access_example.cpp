#include <iostream>
using namespace std;

class MyClass {
private:
    int privateData;

protected:
    int protectedData;

public:
    int publicData;

    MyClass(int pvt, int prot, int pub) : privateData(pvt), protectedData(prot), publicData(pub) {}

    void displayPublicAndProtected() {
        cout << "Accessing public data from within the class: " << publicData << endl;
        cout << "Accessing protected data from within the class: " << protectedData << endl;
        cout << "Accessing private data from within the class: " << privateData << endl;
    }

    friend void friendFunction(const MyClass& obj);
};

void friendFunction(const MyClass& obj) {
    cout << "--- Inside the friend function ---" << endl;
    cout << "Accessing private data: " << obj.privateData << endl;
    cout << "Accessing protected data: " << obj.protectedData << endl;
    cout << "Accessing public data: " << obj.publicData << endl;
    cout << "-----------------------------------" << endl;
}

int main() {
    MyClass myObject(10, 20, 30);

    cout << "Accessing public data from main(): " << myObject.publicData << endl;
    /* cout << "Accessing private data from main(): " << myObject.privateData << endl;
     cout << "Accessing protected data from main(): " << myObject.protectedData << endl;*/ //shows error because not accesible
    
    // This is allowed because it's a member function
    myObject.displayPublicAndProtected();

    // This is allowed because it's a friend function
    friendFunction(myObject);

    myObject.displayPublicAndProtected();

    friendFunction(myObject);

    return 0;
}
