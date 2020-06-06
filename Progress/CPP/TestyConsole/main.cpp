#include<string>
#include<iostream>

#include"HCDF.h"
#include"HCDF_Saving.h"
#include"HCDF_Current.h"
	
int main() {
	std::string name{ "KK" };
	int mno{ 6565656 };
	HCDF *h1=new HCDF_Saving(name,mno);

	return 0;
}