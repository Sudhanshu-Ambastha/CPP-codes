#include <iostream>
using namespace std;

// --- 1. Base Class (The Grandparent) ---
// This class is inherited VIRTUALLY to solve the Diamond Problem.
class Student {
public:
    int roll_number;

    Student(int r) : roll_number(r) {
        cout << "Student initialized (Roll: " << roll_number << ")\n";
    }
    
    void display_roll() const {
        cout << "  Roll Number: " << roll_number << endl;
    }
};

// --- 2. Multilevel Inheritance Branch (A Parent) ---
// Inherits Student VIRTUALLY
class Exam : virtual public Student {
public:
    float marks;

    Exam(int r, float m) : Student(r), marks(m) {
        cout << "  Exam initialized (Marks: " << marks << ")\n";
    }

    void display_exam_data() const {
        cout << "  Exam Marks: " << marks << endl;
    }
};

// --- 3. Multiple Inheritance Branch (The Other Parent) ---
// Inherits Student VIRTUALLY
class Sports : virtual public Student {
public:
    float score; // E.g., points in a sport

    Sports(int r, float s) : Student(r), score(s) {
        cout << "  Sports initialized (Score: " << score << ")\n";
    }

    void display_sports_data() const {
        cout << "  Sports Score: " << score << endl;
    }
};

// --- 4. Hybrid Inheritance (The Child) ---
// Inherits from both Exam and Sports (Multiple Inheritance)
// Since both parents inherited Student virtually, only ONE copy of Student exists.
class Result : public Exam, public Sports {
public:
    float total_percentage;

    // The Result constructor must initialize the Grandparent (Student) class directly,
    // in addition to its direct parents (Exam and Sports).
    Result(int r, float m, float s) 
        : Student(r), // Direct initialization of virtual base class
          Exam(r, m), 
          Sports(r, s) 
    {
        total_percentage = (m + s) / 2.0f;
        cout << "Result initialized.\n";
    }

    void display_result() const {
        cout << "\n--- Final Hybrid Result ---\n";
        // Call to Student's function is unambiguous due to 'virtual' inheritance
        display_roll(); 
        display_exam_data();
        display_sports_data();
        cout << "  Total Percentage: " << total_percentage << "%\n";
    }
};

int main() {
    cout << "Starting Hybrid Inheritance Demo:\n";
    
    // Create an object of the final hybrid class
    Result student_report(
        101,    // Roll Number
        85.5f,  // Exam Marks
        92.0f   // Sports Score
    );

    student_report.display_result();
    
    cout << "---------------------------------\n";
    cout << "If 'virtual' was removed, calling 'student_report.display_roll()' \n";
    cout << "would cause a compiler error due to ambiguity (the Diamond Problem).\n";

    return 0;
}