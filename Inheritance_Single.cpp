#include <iostream>

using namespace std;

// Base class
class Vehicle {
    string brand;
    string model;
public:

    void getVehicleDetails() {
        cout << "Enter vehicle brand: ";
        cin >> brand;
        cout << "Enter vehicle model: ";
        cin >> model;
    }

    void displayVehicleDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
};

// Derived class
class Car : public Vehicle {
    int doors;
public:

    void getCarDetails() {
        getVehicleDetails(); // Call base class function
        cout << "Enter number of doors: ";
        cin >> doors;
    }

    void displayCarDetails() {
        displayVehicleDetails(); // Call base class function
        cout << "Number of doors: " << doors << endl;
    }
};

int main() {
    Car myCar;
    cout << "--- Single Inheritance Example ---" << endl;
    myCar.getCarDetails();
    cout << "\n--- Displaying Car Details ---" << endl;
    myCar.displayCarDetails();

    return 0;
}
