#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements you want to enter: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of elements must be positive. Exiting." << endl;
        return 1;
    }

    int arr[n];
    int *ptr = arr;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> *(ptr + i);
    }

    cout << "\n--- Pointer Increment Operations ---" << endl;
    int *temp_ptr = arr;
    for (int i = 0; i < n; i++) {
        cout << "Address of arr[" << i << "]= " << temp_ptr << endl;
        cout << "Value at arr[" << i << "]= " << *temp_ptr << endl;
        temp_ptr++;
    }

    ptr = arr;
    ptr = ptr + (n - 1);

    cout << "\n--- Pointer Decrement Operations ---" << endl;
    for (int i = n - 1; i >= 0; i--) {
        cout << "Address of arr[" << i << "]= " << ptr << endl;
        cout << "Value at arr[" << i << "]= " << *ptr << endl;
        ptr--;
    }

    return 0;
}
