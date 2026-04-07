#include <iostream>
using namespace std;

class complex{
   int real, imag;

   public:
      complex(int i, int j) { real = i; imag = j; }

      void show() {cout << "\n" << real << "+ i" << imag;}

      complex operator+(complex c) { 
         cout << "\n USING MEMEBER FUNCTION";
         return complex((real+c.real),(imag+c.imag)); 
      }

      // friend complex operator+(complex c1, complex c2);
      
};


/*complex operator+(complex c1, complex c2)
{ 
   cout<<"\nUSING FRIEND FUNCTION";
   return complex ((c1.real+c2.real), (c1.imag+c2.imag));  
}*/


int main(){
   complex c1(2,3), c2(4,5), c3(0,0);
   c3 = c1 + c2;  //calls c1.operator+(c2) and the return value stored in c3
   c3.show();
   return 0;
}