#include "sim.h"
#include<iostream>
#include<memory>

std::ostream & operator <<(std::ostream & arg,Sim &temp)
{
	arg << temp.getVal();
	return arg;
}

int main()
{
	using namespace std;

	Sim sk(24);
	Sim sp(12);
	Sim als{ std::move(sp) };
	cout << als << endl;


	cout << "Ya" << endl;
	return 0;
}