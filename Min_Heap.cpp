#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class MinHeap {
private:
    int heap_array[MAX_SIZE];
    int current_size;

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int index) {
        if (index > 0) {
            int parent_index = (index - 1) / 2;
            if (heap_array[index] < heap_array[parent_index]){
                swap(heap_array[index], heap_array[parent_index]);
                heapifyUp(parent_index);
            }
        }
    }

    void heapifyDown(int index) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int smallest = index;

        if (left_child < current_size && heap_array[left_child] < heap_array[smallest]) {
            smallest = left_child;
        }
        if (right_child < current_size && heap_array[right_child] < heap_array[smallest]) {
            smallest = right_child;
        }

        if (smallest != index) {
            swap(heap_array[index], heap_array[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() {
        current_size = 0;
    }

    void insert(int value) {
        if (current_size >= MAX_SIZE) {
            cout << "Heap is full. Cannot insert." << endl;
            return;
        }
        heap_array[current_size] = value;
        heapifyUp(current_size);
        current_size++;
    }

    void deleteMin() {
        if (current_size == 0) {
            cout << "Heap is empty. Cannot delete." << endl;
            return;
        }
        heap_array[0] = heap_array[current_size - 1];
        current_size--;
        if (current_size > 0) {
            heapifyDown(0);
        }
    }

    int getMin() {
        if (current_size == 0) {
            cout << "Heap is empty. No minimum element." << endl;
            return -1; 
        }
        return heap_array[0];
    }

    void printHeap() {
        if (current_size == 0) {
            cout << "Min-Heap is empty." << endl;
            return;
        }
        cout << "Min-Heap elements: ";
        for (int i = 0; i < current_size; i++) {
            cout << heap_array[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty() {
        return current_size == 0;
    }
};

int main() {
    MinHeap minHeap;
    int choice, value;

    cout << "Min-Heap Operations:" << endl;
    cout << "1. Insert element" << endl;
    cout << "2. Delete minimum element" << endl;
    cout << "3. Get minimum element" << endl;
    cout << "4. Print heap" << endl;
    cout << "5. Exit" << endl;

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                minHeap.insert(value);
                break;
            case 2:
                minHeap.deleteMin();
                break;
            case 3:
                cout << "Minimum element is: " << minHeap.getMin() << endl;
                break;
            case 4:
                minHeap.printHeap();
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
