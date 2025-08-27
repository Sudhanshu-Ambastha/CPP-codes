#include <iostream>
using namespace std;

class Swap{
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
        cout << "Inside swap function with integer references: a = " << a << ", b = " << b << endl;
    }

    void swap(float &a, float &b){
        float temp = a;
        a = b;
        b = temp;
        cout << "Inside swap function with float references: a = " << a << ", b = " << b << endl;
    }

    void swap(double &a, double &b){
        double temp = a;
        a = b;
        b = temp;
        cout << "Inside swap function with double references: a = " << a << ", b = " << b << endl;
    }

    void swap(char &a, char &b){
        char temp = a;
        a = b;
        b = temp;
        cout << "Inside swap function with character references: a = " << a << ", b = " << b << endl;
    }
}; 

int main(){
    Swap s;
    char inputType;

    cout << "Demonstrating function overloading with a single input system:" << endl;
    cout << "Enter the type of values to swap (i for int, f for float, d for double, c for char): ";
    cin >> inputType;
    cin.ignore();

    switch (inputType){
        case 'i':
            int x, y;
            cout << "Enter two integers to swap: ";
            cout << "Sample input: 10 20" << endl;
            cin >> x >> y;
            cout << "Before swap: x = " << x << ", y = " << y << endl;
            s.swap(x, y);
            cout << "After swap: x = " << x << ", y = " << y << endl;
            break;

        case 'f':
            float a, b;
            cout << "Enter two floats to swap: ";
            cout << "Sample input: 5.5f 10.1f" << endl;
            cin >> a >> b;
            cout << "Before swap: a = " << a << ", b = " << b << endl;
            s.swap(a, b);
            cout << "After swap: a = " << a << ", b = " << b << endl;
            break;

        case 'd':
            double p, q;
            cout << "Enter two doubles to swap: ";
            cout << "Sample input: 5.5 10.1" << endl;
            cin >> p >> q;
            cout << "Before swap: p = " << p << ", q = " << q << endl;
            s.swap(p, q);
            cout << "After swap: p = " << p << ", q = " << q << endl;
            break;

        case 'c':
            char m, n;
            cout << "Enter two characters to swap: ";
            cout << "Sample input: A B" << endl;
            cin >> m >> n;
            cout << "Before swap: m = " << m << ", n = " << n << endl;
            s.swap(m, n);
            cout << "After swap: m = " << m << ", n = " << n << endl;
            break;

        default:
            cout << "Error: Type not present." << endl;
    }

    return 0;
}
