#include <iostream>
using namespace std;

void copy_string(char* destination, const char* source, int max_length) {
    int i = 0;
    while (source[i] != '\0' && i < max_length - 1) {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

class Student {
private:
    int enrollmentNo;
    char name[50];
    char branch[10];
    double cgpa;

public:
    Student(int en, const char* n, const char* b, double c) {
        enrollmentNo = en;
        copy_string(name, n, 50);
        copy_string(branch, b, 10);
        cgpa = c;
    }

    Student(int en, const char* n, double c) {
        enrollmentNo = en;
        copy_string(name, n, 50);
        copy_string(branch, "CSE", 10);
        cgpa = c;
    }

    Student() {
        enrollmentNo = 1;
        copy_string(name, "Unknown", 50);
        copy_string(branch, "CSE", 10);
        cgpa = 6.0;
    }

    int getEnrollmentNo() const {return enrollmentNo;}
    const char* getName() const {return name;}
    const char* getBranch() const {return branch;}
    double getCGPA() const {return cgpa;}

    void setEnrollmentNo(int en) {enrollmentNo = en;}
    void setName(const char* n) {copy_string(name, n, 50);}
    void setBranch(const char* b) {copy_string(branch, b, 10);}
    void setCGPA(double c) {cgpa = c;}

    void showDetails() const {
        cout << "-------------------------" << endl;
        cout << "Enrollment No: " << enrollmentNo << endl;
        cout << "Name: " << name << endl;
        cout << "Branch: " << branch << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    Student default_student;

    int numStudents;
    cout << "Enter the number of students you want to add: ";
    cin >> numStudents;
    cin.ignore();

    Student* allStudents = new Student[numStudents + 1];
    allStudents[0] = default_student; 

    for (int i = 1; i <= numStudents; ++i) {
        cout << "\nEnter details for student " << i+1 << ":" << endl;
        int en;
        char n[50], b[10];
        double c;

        cout << "Enter Enrollment No.: ";
        cin >> en;
        cin.ignore();

        if (en == default_student.getEnrollmentNo()) {
            cout << "Enrollment number 1 is reserved for the default student. Please enter a different number." << endl;
            --i; 
            continue;
        }

        cout << "Enter Name: ";
        cin.getline(n, 50);

        cout << "Enter CGPA: ";
        cin >> c;
        cin.ignore();

        cout << "Enter Branch (leave blank for 'CSE'): ";
        cin.getline(b, 10);

        if (b[0] == '\0') {
            allStudents[i] = Student(en, n, c);
        } else {
            allStudents[i] = Student(en, n, b, c);
        }
    }

    cout << "\n--- All Student Details ---" << endl;
    for (int i = 0; i < numStudents + 1; ++i) {
        allStudents[i].showDetails();
    }

    char editChoice = 'y';
    while (editChoice == 'y' || editChoice == 'Y') {
        int updateEn;
        cout << "\n--- Update Student Details ---" << endl;
        cout << "Enter the Enrollment No. of the student you want to update: ";
        cin >> updateEn;

        bool found = false;
        for (int i = 0; i < numStudents + 1; ++i) {
            if (allStudents[i].getEnrollmentNo() == updateEn) {
                int option;
                cout << "Student found. Select a parameter to update:" << endl;
                cout << "1. Name" << endl;
                cout << "2. Branch" << endl;
                cout << "3. CGPA" << endl;
                cout << "Enter option: ";
                cin >> option;
                cin.ignore();

                switch(option) {
                    case 1: {
                        char newName[50];
                        cout << "Enter new name: ";
                        cin.getline(newName, 50);
                        allStudents[i].setName(newName);
                        break;
                    }
                    case 2: {
                        char newBranch[10];
                        cout << "Enter new branch: ";
                        cin.getline(newBranch, 10);
                        allStudents[i].setBranch(newBranch);
                        break;
                    }
                    case 3: {
                        double newCGPA;
                        cout << "Enter new CGPA: ";
                        cin >> newCGPA;
                        allStudents[i].setCGPA(newCGPA);
                        cin.ignore();
                        break;
                    }
                    default:
                        cout << "Invalid option." << endl;
                }
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student with Enrollment No. " << updateEn << " not found." << endl;
        }

        cout << "\n--- All Student Details ---" << endl;
        for (int i = 0; i < numStudents + 1; ++i) {
            allStudents[i].showDetails();
        }

        cout << "\nDo you want to edit another student? (y/n): ";
        cin >> editChoice;
        cin.ignore();
    }

    delete[] allStudents;

    return 0;
}
