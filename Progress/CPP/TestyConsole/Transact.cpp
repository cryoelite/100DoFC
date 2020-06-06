#include<iostream>
#include<typeinfo>

#include "HCDF.h"
#include"HCDF_Saving.h"

void Transact(HCDF* h) {
	std::cout << "Txn begin" << std::endl;
	if (typeid(*h).name() == typeid(HCDF_Saving).name()) {
		std::cout << "yaya" << std::endl;
	}
}
