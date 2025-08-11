#include <iostream>
using namespace std;

class Vector{
    int sz;
    float *elements;

public:
    Vector(int n){
        sz = n;
        elements = new float[sz];
        for (int i = 0; i < sz; i++)
            elements[i] = 0.0f;
    }

    ~Vector(){
        delete[] elements;
    }

    void create(){
        for (int i = 0; i < sz; i++){
            cin >> elements[i];
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    void modify(int idx, float val){
        if (idx >= 0 && idx < sz)
            elements[idx] = val;
    }

    void multiply(float scalar){
        for (int i = 0; i < sz; i++){
            elements[i] *= scalar;
        }
    }

    void display(){
        cout << "(";
        for (int i = 0; i < sz; i++){
            cout << elements[i];
            if (i != sz - 1)
                cout << ", ";
        }
        cout << ")";
    }
};

int main(){
    int n;
    cout << "Enter size of vector: ";
    cin >> n;

    Vector v(n);

    cout << "Enter vector elements:\n";
    v.create();

    cout << "Original vector: ";
    v.display();
    cout << "\n";

    int idx;
    float val;
    cout << "Enter index to modify and new value: ";
    cin >> idx >> val;
    v.modify(idx, val);

    cout << "Vector after modification: ";
    v.display();
    cout << "\n";

    float scalar;
    cout << "Enter scalar to multiply: ";
    cin >> scalar;
    v.multiply(scalar);

    cout << "Vector after multiplication: ";
    v.display();
    cout << "\n";

    return 0;
}
