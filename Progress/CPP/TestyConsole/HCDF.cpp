#include "HCDF.h"
#include<iostream>

HCDF::HCDF(std::string& name, int& mobNo) : name{ name }, mobNo{ mobNo }
{
	std::cout << __FUNCSIG__ << std::endl;
}

void HCDF::deposit(int&)
{
}

float HCDF::withdraw(float&)
{
	return 0.0f;
}

void HCDF::accumulateInterest()
{
}

HCDF::~HCDF()
{
	std::cout << __FUNCSIG__ << std::endl;
}
