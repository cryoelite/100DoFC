#include<iostream>


#include "sim.h"
#include<filesystem>
#include<fstream>
#include<sstream>

int main()
{
	using namespace std;
	filesystem::path source(filesystem::current_path());
	source /= "HH.txt";
	ofstream obj{ source,std::ios::binary | std::ios::out };
	obj.write();


	return 0;
}