#include "Dodo.h"
#include<iostream>

Dodo::Dodo() :a_val{ 0 }, p{ new int(0) } {
	std::cout << "Dodo()" << std::endl;
}

Dodo::Dodo(int a, int& b) : a_val{ a }, p{ new int(b) } {
	std::cout << "Dodo(int,int*)" << std::endl;
}


Dodo::~Dodo() {
	std::cout << "~Dodo()" << std::endl;
	delete p;
}

void Dodo::setVal(int temp) {
	a_val = temp;
	std::cout << "setval" << std::endl;
}

int Dodo::getVal() const {
	std::cout << "getval" << std::endl;
	return this->a_val;
}

bool Dodo::operator==(Dodo& temp) {
	std::cout << "==" << std::endl;
	return (this->a_val == temp.a_val) ? true : false;
}

Dodo::Dodo(const Dodo& temp) {
	std::cout << "Dodo(&)" << std::endl;
	this->a_val = temp.a_val;
	this->p = new int(*temp.p);
	std::cout << "Dodo" << *p << std::endl;
}

Dodo::Dodo(Dodo&& temp) {
	std::cout << "Dodo(&&)" << std::endl;
	this->a_val = temp.a_val;
	this->p = temp.p;
	temp.p = nullptr;
	temp.a_val = 0;
}

Dodo::operator int() {
	std::cout << "int" << std::endl;
	return this->a_val;
}

Dodo& Dodo::operator=(Dodo& temp) {
	std::cout << "=" << std::endl;
	if (this != &temp) {
		delete this->p;
		this->a_val = temp.a_val;
		this->p = new int(*(temp.p));
		std::cout << "ya" << std::endl;
	}
	return *this;
}
