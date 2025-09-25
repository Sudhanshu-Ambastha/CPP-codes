#include <iostream>
using namespace std;

int arr[10], temp[100];
int n, x, count = 0;

void sortArr() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}


void comb(int sum, int idx, int len) {
    if (sum == x) {
        count++;
        cout << "[";
        for (int i = 0; i < len; i++) {
            cout << temp[i];
            if (i < len - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
        return;
    }

    if (sum > x || idx >= n) {
        return;
    }

    temp[len] = arr[idx];
    comb(sum + arr[idx], idx, len + 1); 
    comb(sum, idx + 1, len);
}

int main() {
    cout << "Enter size of array: ";
    cin >> n;
    
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter target sum: ";
    cin >> x;

    sortArr();
    
    comb(0, 0, 0);

    if (count == 0) {
        cout << "Empty\n";
    }
    
    return 0;
}
