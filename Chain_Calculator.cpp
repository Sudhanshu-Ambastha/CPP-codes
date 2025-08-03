#include <iostream>
using namespace std;

int calculate(int a, int b, char op){
    switch (op){
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b != 0){
            return a / b;
        }
        return 0;
    default:
        return 0;
    }
}

bool processOperation(int a, int b, char op, int &result){
    if (op == '/' && b == 0){
        cout << "Error: Division by zero is not allowed." << endl;
        return false;
    }else if (op != '+' && op != '-' && op != '*' && op != '/'){
        cout << "Invalid operator." << endl;
        return false;
    }else{
        result = calculate(a, b, op);
        return true;
    }
}

int main(){
    char op;
    int a, b;
    int result = 0;
    char uc = 'y';

    cout << "Enter 1st no.: ";
    cin >> a;
    cout << "Enter 2nd no.: ";
    cin >> b;
    cout << "Enter choice (+,-,*,/): ";
    cin >> op;

    if (processOperation(a, b, op, result)){
        cout << "Current Result: " << result << endl;
    }else{
        result = 0;
        cout << "Starting with Result: 0" << endl;
    }

    while (uc == 'y'){
        cout << "Do you want to continue? (Y/N): ";
        cin >> uc;
        uc = tolower(uc);

        if (uc == 'y'){
            cout << "Enter next operator (+,-,*,/): ";
            cin >> op;
            cout << "Enter next no.: ";
            cin >> b;

            if (processOperation(result, b, op, result)){
                cout << "Current Result: " << result << endl;
            }
        }
    }

    cout << "Final Result = " << result << endl;

    return 0;
}
