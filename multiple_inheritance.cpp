#include <iostream>
#include <string>

using namespace std;

// Base class 1
class Student {
protected:
    string studentID;
public:
    void getStudentID() {
        cout << "Enter student ID: ";
        cin >> studentID;
    }
    void displayStudentID() {
        cout << "Student ID: " << studentID << endl;
    }
};

// Base class 2
class Worker {
protected:
    int employeeID;
public:
    void getEmployeeID() {
        cout << "Enter employee ID: ";
        cin >> employeeID;
    }
    void displayEmployeeID() {
        cout << "Employee ID: " << employeeID << endl;
    }
};

// Derived class inheriting from two base classes
class WorkingStudent : public Student, public Worker {
public:
    void getDetails() {
        getStudentID();
        getEmployeeID();
    }
    void displayDetails() {
        displayStudentID();
        displayEmployeeID();
    }
};

int main() {
    WorkingStudent person;
    cout << "--- Multiple Inheritance Example ---" << endl;
    person.getDetails();
    cout << "\n--- Displaying Details ---" << endl;
    person.displayDetails();
    return 0;
}
