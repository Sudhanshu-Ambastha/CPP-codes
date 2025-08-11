#include <iostream>
#include <string>
using namespace std;

class Bank {
public:
    string name, type;
    int no;
    float bal;

    void input() {
        cout << "Enter the Name of the Depositor: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter the Number of the Account: ";
        cin >> no;

        cout << "Enter the Type of the Account: ";
        cin.ignore();
        getline(cin, type);

        cout << "Enter the Balance of the Account: ";
        cin >> bal;
        cout << endl;
    }

    void deposit() {
        float dep;
        cout << "Enter deposit: ";
        cin >> dep;
        bal += dep;
        cout << "Amount successfully deposited!" << endl;
    }

    void withdraw() {
        float wd;
        cout << "Enter the amount to withdraw: ";
        cin >> wd;
        if (bal < wd) {
            cout << "Error! Your account doesn't have enough balance to withdraw." << endl;
        } else {
            bal -= wd;
            cout << "Amount successfully withdrawn!" << endl;
        }
    }

    void show() {
        cout << "\nName of the Depositor: " << name << endl;
        cout << "Number of the Account: " << no << endl;
        cout << "Type of the Account: " << type << endl;
        cout << "Balance of the Account: " << bal << endl;
    }
};

int main() {
    int n, ch, num;
    cout << "Enter total no. of depositors: ";
    cin >> n;
    cout << endl;

    Bank* obj = new Bank[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter details of the depositor " << i + 1 << ": " << endl;
        obj[i].input();
    }

    cout << "Details of each depositor:-\n";
    for (int i = 0; i < n; i++) {
        obj[i].show();
    }

    do {
        cout << "\nPress the depositor no. you want to check (0 to " << n - 1 << "): ";
        cin >> num;
        if (num < 0 || num >= n) {
            cout << "Invalid depositor number!" << endl;
            continue;
        }
        cout << "Press 1 to withdraw\n2 to deposit\n3 to display\n4 to exit: ";
        cin >> ch;
        switch (ch) {
            case 1:
                obj[num].withdraw();
                break;
            case 2:
                obj[num].deposit();
                break;
            case 3:
                obj[num].show();
                break;
            case 4:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Enter valid choice" << endl;
                break;
        }
    } while (ch != 4);

    delete[] obj;
    return 0;
}
