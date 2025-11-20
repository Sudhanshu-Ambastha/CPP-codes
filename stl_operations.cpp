#include <bits/stdc++.h>

using namespace std;

template <typename T>
void handleVectorOps(vector<T>& vec) {
    cout << "\n--- Vector Operations Demo ---" << endl;
    
    int choice = 0;
    while (choice != 4) {
        cout << "\nVector: [";
        for (const auto& item : vec) {
            cout << item << " ";
        }
        cout << "]" << endl;
        
        cout << "Choose action for vector:" << endl;
        cout << "1. Push Back (Add element)" << endl;
        cout << "2. Pop Back (Remove last element)" << endl;
        cout << "3. Display Size" << endl;
        cout << "4. Finish Vector Demo" << endl;
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                T element;
                cout << "Enter element to push (e.g., an integer): ";
                if (cin >> element) {
                    vec.push_back(element);
                    cout << element << " pushed to back." << endl;
                } else {
                    cout << "Invalid element input." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;
            }
            case 2: {
                if (!vec.empty()) {
                    T last_element = vec.back();
                    vec.pop_back();
                    cout << last_element << " popped from back." << endl;
                } else {
                    cout << "Vector is empty. Cannot pop." << endl;
                }
                break;
            }
            case 3: {
                cout << "Current vector size: " << vec.size() << endl;
                break;
            }
            case 4: {
                cout << "Exiting vector demo." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please select 1, 2, 3, or 4." << endl;
        }
    }
}

template <typename K, typename V>
void handleMapOps(map<K, V>& m) {
    cout << "\n--- Map Operations Demo ---" << endl;

    int choice = 0;
    while (choice != 3) {
        cout << "\nCurrent Map Contents:" << endl;
        if (m.empty()) {
            cout << " (Map is empty)" << endl;
        } else {
            for (const auto& pair : m) {
                cout << "[" << pair.first << "]: " << pair.second << endl;
            }
        }

        cout << "\nChoose action for map:" << endl;
        cout << "1. Insert/Update Mapping (Key -> Value)" << endl;
        cout << "2. Find Value by Key" << endl;
        cout << "3. Finish Map Demo" << endl;
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                K key;
                V value;
                cout << "Enter key (string, e.g., 'apple'): ";
                cin >> key;
                cout << "Enter value (integer): ";
                if (cin >> value) {
                    m[key] = value;
                    cout << "Mapping updated/inserted: " << key << " -> " << value << endl;
                } else {
                    cout << "Invalid value input." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;
            }
            case 2: {
                K key;
                cout << "Enter key to find: ";
                cin >> key;
                
                auto it = m.find(key);
                if (it != m.end()) {
                    cout << "Found: [" << it->first << "] maps to " << it->second << endl;
                } else {
                    cout << "Key '" << key << "' not found in map." << endl;
                }
                break;
            }
            case 3: {
                cout << "Exiting map demo." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please select 1, 2, or 3." << endl;
        }
    }
}


int main() {
    cout << "Welcome to the STL Demonstration Program!" << endl;
    
    vector<int> my_vector;
    handleVectorOps(my_vector);

    map<string, int> item_inventory;
    handleMapOps(item_inventory);

    cout << "\nProgram finished successfully." << endl;
    
    return 0;
}