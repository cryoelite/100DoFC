#include<iostream>
#include<typeinfo>

#include "HCDF.h"
#include"HCDF_Saving.h"
#include "Transact.h"


void transact(HCDF* h, int& option, float& amount) {
	std::cout << "Txn begin" << std::endl;
	if (option == 0) {
		if (typeid(*h).name() == typeid(HCDF_Saving).name()) {
			std::cout << "HCDF_Saving" << std::endl;
			HCDF_Saving* p = static_cast<HCDF_Saving*>(h);
			p->accumulateInterest();
			p->withdraw(amount);
		}
		else {
			std::cout << "HCDF_Current" << std::endl;
			h->withdraw(amount);
		}

	}
	else {

		if (typeid(*h).name() == typeid(HCDF_Saving).name()) {
			std::cout << "HCDF_Saving" << std::endl;
			HCDF_Saving* p = static_cast<HCDF_Saving*>(h);
			p->accumulateInterest();
			p->deposit(amount);
		}
		else {
			std::cout << "HCDF_Current" << std::endl;
			h->deposit(amount);
		}

	}
}
