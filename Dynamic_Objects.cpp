#include <iostream>
using namespace std;

class Vector {
private:
    double x, y;

public:
    Vector(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {
        cout << "Vector object created." << endl;
    }

    ~Vector() {
        cout << "Vector object destroyed." << endl;
    }

    void display() const {
        cout << "Vector(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // Creating a single dynamic object
    Vector* myVector = new Vector(10.5, 20.3);

    cout << "--- Accessing single dynamic object ---" << endl;
    myVector->display();

    // Deleting the single dynamic object
    delete myVector;
    cout << "--- Single object deleted ---" << endl;

    // Creating a dynamic array of objects
    Vector* vectorArray = new Vector[3];

    cout << "--- Accessing dynamic array of objects ---" << endl;
    for (int i = 0; i < 3; ++i) {
        vectorArray[i].display();
    }

    // Deleting the dynamic array
    delete[] vectorArray;
    cout << "--- Dynamic array deleted ---" << endl;

    return 0;
}
