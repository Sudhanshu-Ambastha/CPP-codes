#include <iostream>
using namespace std;

int main() {
    int n, largest, secondLargest;
    cout << "Enter no. of elements to enter: ";
    cin >> n;

    if (n < 2) {
        cout << "Please enter at least two numbers." << endl;
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter value for integer " << i + 1 << ": ";
        cin >> arr[i];
    }

    if (arr[0] > arr[1]) {
        largest = arr[0];
        secondLargest = arr[1];
    } else {
        largest = arr[1];
        secondLargest = arr[0];
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    cout << "The second largest number is: " << secondLargest << endl;

    return 0;
}
