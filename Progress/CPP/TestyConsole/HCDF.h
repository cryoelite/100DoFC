#pragma once
#include<string>

class HCDF
{
public:
	static int acNo;
	float interest, balance;
	std::string name;
	int mobNo;
	HCDF() = delete;
	HCDF(std::string& name, int& mobNo);
	virtual void deposit(int&);
	virtual float withdraw(float&);
	virtual void accumulateInterest();
	virtual ~HCDF();
};

