#include <iostream>
using namespace std;

int x = 3;
class A
{
    static int x;
    public:
        class B
        {
            public:
                void f1()
                {
                    class C
                    {
                        int x = 78;
                        public:
                            void f2(int x)
                            {
                                cout << "Local x in f2 = " << x << endl;
                                cout << "Member x in C = " << this->x << endl;
                                cout << "Static x in A = " << A::x << endl;
                                cout << "Global x = " << ::x << endl;
                            }
                    };

                    C c_obj;
                    c_obj.f2(100);
                }
        };
};

int A::x = 50;

int main(){
    A::B b;
    b.f1();
    return 0;
}