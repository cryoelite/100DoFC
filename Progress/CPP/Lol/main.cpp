#include<iostream>


#include "sim.h"
#include<filesystem>
#include<fstream>
#include<sstream>


void name0()
{
	std::cout << __FUNCDNAME__;
}
int main()
{
	using namespace std;
	name0.operator()();


	return 0;
}