#include <iostream>
using namespace std;

class A; // Forward declaration

class B {
    int y;
    public:
    B(int i) { // Constructor
        y = i;
    }
    friend class A; // A is friend of B
};

class A {
    int x;
    public:
    A(int i) { // Constructor
        x = i;
    }
    int add(A a1, B b1) {
        // A can access private member y of B
        return (a1.x + b1.y);
    }
    void display(A a1, B b1) {
        cout << "Sum computed with friend function: " << add(a1, b1);
    }
};

int main() {
    A a1(5);
    B b1(15);
    a1.display(a1, b1);
    return 0;
}