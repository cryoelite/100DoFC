#pragma once
#include<string>

class HCDF
{
public:
	int acno;
	float  balance;
	std::string name;
	long int mobNo;
	HCDF(std::string& name, long int& mobNo);
	virtual void deposit(float&);
	virtual void withdraw(float&);
	virtual void accumulateInterest();
	float getBal();
	
	virtual ~HCDF();
};


