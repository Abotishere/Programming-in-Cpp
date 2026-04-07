#include <iostream>
#include <cmath>
using namespace std;

class complex{
    float real, imag;

public:

    void input(){
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    void display(){
        if(imag >= 0)
            cout << real << " + i" << imag << endl;
        else
            cout << real << " - i" << -imag << endl;
    }

    complex add(complex c1, complex c2){
        complex temp;
        temp.real = c1.real + c2.real;
        temp.imag = c1.imag + c2.imag;
        return temp;
    }

    complex subtract(complex c1, complex c2){
        complex temp;
        temp.real = c1.real - c2.real;
        temp.imag = c1.imag - c2.imag;
        return temp;
    }

    complex multiply(complex c1, complex c2){
        complex temp;

        temp.real = (c1.real * c2.real) - (c1.imag * c2.imag);
        temp.imag = (c1.real * c2.imag) + (c1.imag * c2.real);

        return temp;
    }

    void max(complex c1, complex c2){
        if ((sqrt(c1.real*c1.real + c1.imag*c1.imag)) > sqrt(c2.real*c2.real + c2.imag*c2.imag)){
            c1.display();
            cout << " is greater(in magnitude)." << endl;
        }
        else if ((sqrt(c1.real*c1.real + c1.imag*c1.imag)) < sqrt(c2.real*c2.real + c2.imag*c2.imag)){
            c2.display();
            cout << "is greater(in magnitude)." << endl;
        }
        else
            cout << "Both the complex numbers are same(in magnitude)." << endl;
    }
};

int main(){
    complex c1, c2, result, obj;

    cout << "Enter First complex Number:\n";
    c1.input();

    cout << "\nEnter Second complex Number:\n";
    c2.input();

    cout << "\nFirst complex Number: ";
    c1.display();

    cout << "Second complex Number: ";
    c2.display();

    result = obj.add(c1, c2);
    cout << "\nAddition Result: ";
    result.display();

    result = obj.subtract(c1, c2);
    cout << "Subtraction Result: ";
    result.display();

    result = obj.multiply(c1, c2);
    cout << "Multiplication Result: ";
    result.display();

    obj.max(c1, c2);

    return 0;
}
