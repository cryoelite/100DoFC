#include "HCDF.h"
#include<iostream>

HCDF::HCDF(std::string& name, long int& mobNo) : name{ name }, mobNo{ mobNo }, balance{ 0 }
{
	std::cout << "HCDF(&&)" << std::endl;
}

void HCDF::deposit(float& amount)
{
	balance += amount;
	std::cout << "Deposited HCDF " << amount << std::endl;
}

void HCDF::withdraw(float& amount)
{
	balance -= amount;
	std::cout << "Null txn done" << std::endl;
}

void HCDF::accumulateInterest()
{
}

float HCDF::getBal()
{
	return balance;
}



HCDF::~HCDF()
{
	std::cout << "HCDF_Saving" << std::endl;
}
