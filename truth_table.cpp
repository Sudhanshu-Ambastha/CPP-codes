#include <iostream>
using namespace std;

int main(){
    cout << "a    b    a && b    a || b    !a    !b" << endl;
    cout << "---------------------------------------" << endl;

    for (int a = 0; a <= 1; a++){
        for (int b = 0; b <= 1; b++){
            int and_result = (a && b);
            int or_result = (a || b);
            int not_a_result = (!a);
            int not_b_result = (!b);

            cout << a << "    " << b << "    ";
            cout << and_result << "         ";
            cout << or_result << "         ";
            cout << not_a_result << "     " << not_b_result << endl;
        }
    }

    return 0;
}
