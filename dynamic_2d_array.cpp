#include <iostream>
using namespace std;

int main(){
    int ROWS, COLS;
    cout << "Enter number of rows: ";
    cin >> ROWS;
    cout << "Enter number of columns: ";
    cin >> COLS;

    int **arr = new int *[ROWS];
    for (int i = 0; i < ROWS; ++i){
        arr[i] = new int[COLS];
    }

    cout << "Enter " << ROWS * COLS << " elements for the 2-D array (" << ROWS << "x" << COLS << "):" << endl;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "\nGenerated 2-D Matrix:" << endl;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < ROWS; ++i){
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}
