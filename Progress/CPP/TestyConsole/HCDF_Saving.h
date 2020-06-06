#pragma once
#include"HCDF.h"

class HCDF_Saving:public HCDF
{
	const int minBal{ 500 };
	using HCDF::HCDF;
	void deposit(int& amount) {
		HCDF::balance += amount;
	}
};

