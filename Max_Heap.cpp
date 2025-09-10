#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class MaxHeap {
private:
    int heap_array[MAX_SIZE];
    int current_size;

    // Helper function to swap two elements in the array
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Maintains max-heap property by bubbling up an element
    void heapifyUp(int index) {
        if (index > 0) {
            int parent_index = (index - 1) / 2;
            if (heap_array[index] > heap_array[parent_index]) { // The only change from min-heap
                swap(heap_array[index], heap_array[parent_index]);
                heapifyUp(parent_index);
            }
        }
    }

    // Maintains max-heap property by bubbling down an element
    void heapifyDown(int index) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int largest = index;

        if (left_child < current_size && heap_array[left_child] > heap_array[largest]) { // The only change from min-heap
            largest = left_child;
        }
        if (right_child < current_size && heap_array[right_child] > heap_array[largest]) { // The only change from min-heap
            largest = right_child;
        }

        if (largest != index) {
            swap(heap_array[index], heap_array[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() {
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

    void deleteMax() {
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

    int getMax() {
        if (current_size == 0) {
            cout << "Heap is empty. No maximum element." << endl;
            return -1; // Or throw an exception
        }
        return heap_array[0];
    }

    void printHeap() {
        if (current_size == 0) {
            cout << "Max-Heap is empty." << endl;
            return;
        }
        cout << "Max-Heap elements: ";
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
    MaxHeap maxHeap;
    int choice, value;

    cout << "Max-Heap Operations:" << endl;
    cout << "1. Insert element" << endl;
    cout << "2. Delete maximum element" << endl;
    cout << "3. Get maximum element" << endl;
    cout << "4. Print heap" << endl;
    cout << "5. Exit" << endl;

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                maxHeap.insert(value);
                break;
            case 2:
                maxHeap.deleteMax();
                break;
            case 3:
                cout << "Maximum element is: " << maxHeap.getMax() << endl;
                break;
            case 4:
                maxHeap.printHeap();
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
