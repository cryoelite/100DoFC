#include "sim.h"
#include<iostream>

ABC::ABC()
{
	std::cout << __FUNCSIG__;
}


ABC::ABC(int no)
{
	std::cout << __FUNCSIG__ << " " << no;
}