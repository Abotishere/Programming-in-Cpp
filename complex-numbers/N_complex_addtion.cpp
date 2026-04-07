#include <iostream>
#include <vector>
using namespace std;

class complex{
    float real, imag;

public:
    complex() : real(0.0f), imag(0.0f) {}

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
};

int main(){
    int n;
    cout << "Enter number of complex numbers: ";
    cin >> n;

    vector<complex> c(n);
    complex sum, obj;

    cout << "\nEnter complex Numbers:\n";

    for(int i = 0; i < n; i++){
        cout << "\nComplex Number " << i+1 << endl;
        c[i].input();
    }

    for(int i = 0; i < n; i++){
        sum = obj.add(sum, c[i]);
    }

    cout << "\nSum of all complex numbers = ";
    sum.display();

    return 0;
}
