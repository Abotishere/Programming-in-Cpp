#include <iostream>
using namespace std;

class A{
	int x;
	public: 
	A(int i){x = i;}

	void show()  {cout<<"\nX:- "<<x;}

	/*
	void operator-(){
		cout<<"\n INSIDE NON STATIC MEMBER FUNCTION"; x=-x; 
	}*/

	
	/*A operator-() { 
		cout<<"\n INSIDE NON STATIC MEMBER FUNCTION WITH OBJECT RETURN";
		A a3(0);
		a3.x = -x;
		return a3;
	}*/

	friend void operator-(A &a2);

	void operator++(){
		cout<<"\n OPERATED AS PREFIX";
		++x;
	}

	void operator++(int y){
		cout<<"\n OPERATED AS POSTFIX";	
		x++;
	}
};

void operator-(A &a2)
{ cout<<"\nINSDE FRIEND FUNCTION";
	a2.x = -a2.x; }

int main(){
	A a1(5), a2(0), a3(7);	
	-a1;	// calls operator-() function  i.e   a1.operator-()	
	a1.show();
	// a2 = -a1;
	// a2.show();
	++a3;
	a3.show();
	a3++;
	a3.show();
	return 0;
}
