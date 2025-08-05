#include <iostream>
using namespace std;

int main(){
    int n, s;
    cout << "Enter the no. of roll nos. you want to add: ";
    cin >> n;

    int *arr = new int[n];
    int *ptr = arr;
    cout << "\nEnter list of roll no.s:-\n";
    for (int i = 1; i <= n; i++){
        cout << "roll no. " << i << ": ";
        cin >> *(ptr + i);
    }
    
    cout << "\nEnter roll no. you want to search for: ";
    cin >> s;
    int flag = 0;
    for (int i = 0; i < n; i++){
        if (s == ptr[i]){
            cout << i << " ";
            flag = 1;
        }
    }
    
    if (!flag){
        cout << "\nNot found\n";
    }

    delete[] arr;
    return 0;
}
