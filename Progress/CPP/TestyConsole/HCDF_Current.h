#pragma once
#include "HCDF.h"

class HCDF_Current : public HCDF
{
	const int minBal = 300;
	using HCDF::HCDF;
	void deposit(float&);
	void withdraw(float&);
	~HCDF_Current();
};