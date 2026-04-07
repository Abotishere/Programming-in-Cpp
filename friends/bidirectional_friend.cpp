#include <iostream>
using namespace std;

class B; // Forward declaration
class A {
    int x;
    public:
    A(int i) {
        x = i;
    }
    // Friend function declaration
    friend int add(A, B);
};
class B {
    int y;
    public:
    B(int i) {
        y = i;
    }
    // Same friend function declared here
    friend int add(A, B);
};
// Friend function definition
int add(A a1, B b1) {
    return (a1.x + b1.y); // Accessing private members of both classes
}
int main() {
    A a1(10);
    B b1(20);
    cout << "Sum using bidirectional friend function: " << add(a1, b1);
    return 0;
}