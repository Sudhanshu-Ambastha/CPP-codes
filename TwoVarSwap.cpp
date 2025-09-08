#include <iostream>

using namespace std;

void swap_vars(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int x = 10;
    int y = 20;

    cout << "Before swap:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    swap_vars(&x, &y);

    cout << "\nAfter swap:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}