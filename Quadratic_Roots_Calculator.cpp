#include <iostream>
using namespace std;

double myAbs(double x) {
    return (x < 0) ? -x : x;
}

double mySqrt(double x) {
    if (x < 0) {
        return 0.0;
    }
    if (x == 0) {
        return 0.0;
    }

    double guess = x / 2.0;
    double epsilon = 0.00001;

    while (myAbs(guess * guess - x) > epsilon) {
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
}

int main() {
    double a, b, c;
    double root1, root2;
    double discriminant;

    cout << "Enter coefficient a: ";
    cin >> a;

    cout << "Enter coefficient b: ";
    cin >> b;

    cout << "Enter coefficient c: ";
    cin >> c;

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + mySqrt(discriminant)) / (2 * a);
        root2 = (-b - mySqrt(discriminant)) / (2 * a);
        cout << "Two distinct real roots:" << endl;
        cout << "Root 1 = " << root1 << endl;
        cout << "Root 2 = " << root2 << endl;
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        cout << "One real root (repeated root):" << endl;
        cout << "Root = " << root1 << endl;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = mySqrt(myAbs(discriminant)) / (2 * a);
        cout << "Two complex roots:" << endl;
        cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i" << endl;
    }

    return 0;
}
