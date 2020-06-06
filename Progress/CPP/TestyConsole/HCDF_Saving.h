#pragma once
#include"HCDF.h"

class HCDF_Saving :public HCDF
{
public:
	const int minBal{ 500 };
	using HCDF::HCDF;
	void deposit(float& amount)override;
	void accumulateInterest()override;
	void withdraw(float&)override;
	~HCDF_Saving();
};

