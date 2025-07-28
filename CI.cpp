#include <iostream>
#include <cmath>
using namespace  std;

int main(){
    int p, r, t;
    double ta, ci;
    cout<<"Enter Principal: ";
    cin>>p;
    cout<<"Enter Rate(%): ";
    cin>>r;
    cout<<"Enter Time (yrs): ";
    cin>>t;
    ta = p * pow((1 + r / 100.0), t);
    cout<<"Total Amount: "<<ta<<"\n";
    ci = ta - p;
    cout<<"Compound interest: "<<ci;
}
