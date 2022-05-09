#include "std_lib_facilities.h"


class B1 {
public:
virtual void vf() {cout <<"B1::vf()"<<endl;}
void f() {cout << "B1::f()" <<endl;}
class D2 : public D1  { 
};

class D1 : public B1 { 
public:
void vf() {cout << "D1::vf()"<<endl;}
void f() {cout << "D1::f()" <<endl;}

};
class D2 : public D1  {
public:
void pvf(){cout << "D2::pvf()" <<endl;} 
};

class B2 {
public:
virtual void pvf() = 0; 
};
				
class D21 : public B2  {
public:
string s;
void pvf() { cout<< s << endl;}
};

class D22: public B2 {
public:
int n;
void pvf(){ cout << n << endl;}
				
				
};
void f(B2& b2)
{
b2.pvf();
}

int main(){
		
D2 d2;
d2.f();
d2.vf();
d2.pvf();
		
D21 d21;
d21.s = "d21.s";
d21.pvf();
		
D22 d22;
d22.n = 22;
d22.pvf();
		
f(d21);
f(d22);
		
}
		


