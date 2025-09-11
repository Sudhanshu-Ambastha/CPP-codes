#include <iostream>
#include <string>

using namespace std;

// Grandfather (Base Class)
class Grandfather {
protected:
    string name_grandfather;
public:
    void getGrandfatherName() {
        cout << "Enter Grandfather's name: ";
        cin >> name_grandfather;
    }
    void displayGrandfatherName() {
        cout << "Grandfather's Name: " << name_grandfather << endl;
    }
};

// Father (Derived from Grandfather)
class Father : public Grandfather {
protected:
    string name_father;
public:
    void getFatherName() {
        cout << "Enter Father's name: ";
        cin >> name_father;
    }
    void displayFatherName() {
        cout << "Father's Name: " << name_father << endl;
    }
};

// Son (Derived from Father)
class Son : public Father {
protected:
    string name_son;
public:
    void getSonName() {
        cout << "Enter Son's name: ";
        cin >> name_son;
    }
    void displayAllNames() {
        displayGrandfatherName();
        displayFatherName();
        cout << "Son's Name: " << name_son << endl;
    }
};

int main() {
    Son mySon;
    cout << "--- Multilevel Inheritance Example ---" << endl;
    mySon.getGrandfatherName();
    mySon.getFatherName();
    mySon.getSonName();
    cout << "\n--- Displaying Names ---" << endl;
    mySon.displayAllNames();
    return 0;
}
