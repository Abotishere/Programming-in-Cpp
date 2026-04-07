#include <iostream>

using namespace std;
struct complex{
    int real;
    int imag;
};

complex max(complex c1, complex c2){
    if (c1.real+c1.imag > c2.real+c2.imag)
        return c1;
    else 
        return c2;
}

int main(){
    complex c1;
    complex c2;

    cout << "Enter real and imaginary parts of a complex number:\n";
    cin >> c1.real >> c1.imag;
    cout << "Enter real and imaginary parts of a complex number:\n";
    cin >> c2.real >> c2.imag;

    complex c3 = max(c1, c2);
    cout << c3.real << " + i" << c3.imag << "\n";
}