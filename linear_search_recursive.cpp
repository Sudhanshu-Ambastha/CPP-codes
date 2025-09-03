#include <iostream>
using namespace std;

int recSearch(int arr[], int l, int r, int x){
    if (r < l){
        return -1;
    }
    if (arr[l] == x){
        return l;
    }
    return recSearch(arr, l + 1, r, x);
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int x;
    cout << "Enter the element to search: ";
    cin >> x;

    int index = recSearch(arr, 0, n - 1, x);

    if (index != -1){
        cout << "Element " << x << " is present at index " << index << "." << endl;
    }else{
        cout << "Element " << x << " is not present in the array." << endl;
    }

    return 0;
}
