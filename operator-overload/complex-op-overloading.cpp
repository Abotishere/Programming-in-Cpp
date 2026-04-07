#include <iostream>
#include <string>
using namespace std;

class Complex{
	int real, imag;
    public:
		Complex(int r, int i) { real = r; imag = i; }

		void show() { cout << real << " + i" << imag << endl; }

		friend Complex operator+(Complex c1, Complex c2);
        friend Complex operator>=(Complex c1, Complex c2);

		Complex operator-(Complex &c) { 
            return Complex((this->real - c.real), (this->imag - c.imag)); }

		Complex operator++() { 
            return Complex(++this->real, ++this->imag); }
};

Complex operator+(Complex c1, Complex c2) { 
    return Complex((c1.real + c2.real), (c1.imag + c2.imag)); }

Complex operator>=(Complex c1, Complex c2) {
    if ((c1.real+c1.imag) >= (c2.real+c2.imag)) return c1;
    else return c2;
}

int main(){
	const int n = 5;
	Complex *arr = new Complex[n]{
        Complex(4,5),
        Complex(2,2),
        Complex(3,4),
        Complex(1,8),
        Complex(5,9)
    };
	
    Complex P = Complex(8,2);
    cout << "P = ";
    P.show();
    Complex Q = Complex(5,6);
    cout << "Q = ";
    Q.show();

    cout << endl;

    cout << "Addition using friend function--";
	Complex A = P + Q;
	cout << "\nP + Q = ";
	A.show(); cout << endl;
    
    cout << "Subtraction using member function--";
    Complex B = P - Q;
    cout << "\nP - Q = ";
	B.show(); cout << endl;
	
    cout << "Prefix using member function--";
	Complex C = ++P;
	cout << "\n++P = ";
	C.show(); cout << endl;

    Complex D = (P >= Q);
    cout << "Greater complex no. is = ";
    D.show();
    
    Complex sum = Complex(0,0);
    for (int i = 0; i < n; i++){
        sum = sum + arr[i];
    }
    cout << "\nSummation of all the complex numbers in the array =" << endl;
    sum.show();

    Complex greatest = Complex(0,0);
    for (int i = 0; i < n - 1; i++){
        greatest = (arr[i] >= arr[i + 1]);
    }
    cout << "\nGreatest of all the complex numbers in the array = " << endl;
    greatest.show();
	
	delete[] arr;
	return 0;
}
