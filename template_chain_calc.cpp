#include <iostream>
using namespace std;

template <typename T1, typename T2>
auto calculate(T1 a, T2 b, char op) -> decltype(a + b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                cout << "\nError: Division by zero! Retaining previous result." << endl;
                return a; 
            }
            return a / b;
        default:
            return a;
    }
}

template <typename T>
T readNumericInput(const char* prompt) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        } else {
            cout << "Invalid numeric input. Please try again." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

char readOperatorOrCommand() {
    char op;
    while (true) {
        cout << "Enter next operator (+, -, *, /) or 'q' to quit: ";
        if (cin >> op) {
            if (op == '+' || op == '-' || op == '*' || op == '/' || op == 'q') {
                return op;
            }
        }
        cout << "Invalid input. Please enter +, -, *, /, or 'q'." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    cout << "--- Continuous Template Calculator ---" << endl;
    
    double current_result = readNumericInput<double>("Enter initial number: ");
    
    char op;

    while (true) {
        op = readOperatorOrCommand();

        if (op == 'q') {
            cout << "\nExiting calculator. Final result: " << current_result << endl;
            break;
        }

        double num_b = readNumericInput<double>("Enter next number: ");
        
        current_result = calculate(current_result, num_b, op);
        
        cout << "Current result: " << current_result << endl;
    }

    return 0;
}
