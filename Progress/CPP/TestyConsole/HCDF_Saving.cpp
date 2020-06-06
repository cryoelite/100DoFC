#include<iostream>

#include "HCDF_Saving.h"

void HCDF_Saving::deposit(float& amount)
{
	balance += amount;
	std::cout << "Deposited Savings " << amount << std::endl;
}



void HCDF_Saving::withdraw(float& amount)
{
	if (balance - amount > minBal) {
		balance -= amount;
		std::cout << "Txn Success" << std::endl;
	}
	else {
		std::cout << "Insufficient Balance" << std::endl;
	}
}
void HCDF_Saving::accumulateInterest() {
	balance *= 0.05f;
}

HCDF_Saving::~HCDF_Saving()
{
	std::cout << "~HCDF_Current" << std::endl;
}

