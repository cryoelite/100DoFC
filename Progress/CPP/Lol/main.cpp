#include<iostream>


#include "sim.h"


class A {
public:
	int a{};
}
;

class B : public A{
public:

		B() {
			a = 1;
		}
	
	
};

class C : public A {
	public:
		
		C() {
			a = 21;
		}
};

class D : public B,  public C {
	public:
		
};

int main()
{
	
	D d;
	std::cout << "\n" << d.a;
	return 0;
}