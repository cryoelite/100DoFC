#include "sim.h"
#include<iostream>

Sim::Sim() :Sim(0)
{
	std::cout << __FUNCSIG__ << std::endl;

}

Sim::Sim(int temp)
{

	std::cout << __FUNCSIG__ << std::endl;
	std::cout << Sim::count++ << std::endl;
	hCount = std::make_unique<int>(temp);

}

Sim::Sim(const Sim& temp)
{
	hCount = std::make_unique<int>(*(temp.hCount));

	std::cout << __FUNCSIG__ << std::endl;
}


Sim::Sim(Sim&& temp)noexcept
{
	hCount = std::move(temp.hCount);

	std::cout << __FUNCSIG__ << std::endl;
}

int Sim::getVal()
{
	return *hCount;
}

Sim::~Sim()
{

	std::cout << __FUNCSIG__ << std::endl;
	hCount.reset();
}