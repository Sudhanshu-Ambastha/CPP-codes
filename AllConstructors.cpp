#include <iostream>

using namespace std;

// Class definition
class Student {
private:
    int id;
    string name;
    int* grades; // Pointer for dynamic memory allocation

public:
    // Default Constructor
    Student() {
        cout << "Default constructor called" << endl;
        id = 0;
        name = "N/A";
        grades = nullptr;
    }

    // Parameterized Constructor
    Student(int studentId, string studentName, int numGrades) {
        cout << "Parameterized constructor called" << endl;
        id = studentId;
        name = studentName;
        grades = new int[numGrades]; // Allocate memory for grades
        for (int i = 0; i < numGrades; ++i) {
            grades[i] = 0; // Initialize grades to 0
        }
    }

    // Copy Constructor (Deep Copy)
    Student(const Student& other) {
        cout << "Deep copy constructor called" << endl;
        id = other.id;
        name = other.name;
        if (other.grades != nullptr) {
            // Allocate new memory and copy contents
            grades = new int[3]; 
            for (int i = 0; i < 3; ++i) {
                grades[i] = other.grades[i];
            }
        } else {
            grades = nullptr;
        }
    }

    // Shallow Copy Function (demonstration)
    // Note: Shallow copy is the default behavior if a copy constructor is not defined.
    // This function explicitly shows the behavior for demonstration purposes.
    void shallowCopy(const Student& other) {
        cout << "Shallow copy function called" << endl;
        id = other.id;
        name = other.name;
        grades = other.grades; // Just copies the address, not the data
    }

    // Destructor to free dynamically allocated memory
    ~Student() {
        cout << "Destructor called for student with ID: " << id << endl;
        delete[] grades; // Deallocate the memory
        grades = nullptr;
    }

    // Member function to display student details
    void display() {
        cout << "Student ID: " << id << endl;
        cout << "Name: " << name << endl;
        if (grades != nullptr) {
            cout << "Grades: ";
            for (int i = 0; i < 3; ++i) {
                cout << grades[i] << " ";
            }
            cout << endl;
        }
        cout << "Memory address of grades: " << grades << endl;
    }
    
    // Setter for grades
    void setGrades(int g1, int g2, int g3) {
        if (grades != nullptr) {
            grades[0] = g1;
            grades[1] = g2;
            grades[2] = g3;
        }
    }
};

int main() {
    // 1. Parameterized constructor
    cout << "--- Using Parameterized Constructor ---" << endl;
    Student s1(101, "Alice", 3);
    s1.setGrades(90, 85, 95);
    s1.display();
    cout << endl;

    // 2. Deep Copy Constructor
    cout << "--- Using Deep Copy Constructor ---" << endl;
    Student s2 = s1; // Calls the deep copy constructor
    s2.display();
    cout << endl;

    // Modifying s2's grades to show independence
    cout << "Modifying s2's grades..." << endl;
    s2.setGrades(70, 75, 80);
    s1.display();
    s2.display();
    cout << endl;
    
    // 3. Shallow Copy Demonstration (using a function)
    cout << "--- Demonstrating Shallow Copy ---" << endl;
    Student s3; // Default constructor
    s3.shallowCopy(s1);
    s3.display();
    cout << endl;

    // Modifying s3's grades to show the shallow copy issue
    cout << "Modifying s3's grades..." << endl;
    s3.setGrades(100, 100, 100);
    s1.display(); // s1's grades are also changed! This is the problem with shallow copy.
    s3.display();
    cout << endl;
    
    // The destructors will now be called for s1, s2, and s3 as main() exits.
    // Notice that a shallow copy on s3 with s1's pointer will cause a double free error
    // because both objects will try to deallocate the same memory.
    // The provided code is a demonstration and a shallow copy should be avoided in real-world scenarios.
    
    return 0;
}
