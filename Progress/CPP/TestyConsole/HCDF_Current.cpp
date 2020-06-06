#include "HCDF_Current.h"

#include<iostream>

void HCDF_Current::deposit(float& amount)
{
	balance += amount;
	std::cout << "Deposited Current " << amount << std::endl;
}

void HCDF_Current::withdraw(float& amount)
{
	if (balance - amount > minBal) {
		balance -= amount;
		std::cout << "Txn Success" << std::endl;
	}
	else {
		std::cout << "Insufficient Balance" << std::endl;
	}
}

HCDF_Current::~HCDF_Current()
{
	std::cout << "~HCDF_Current" << std::endl;
}
