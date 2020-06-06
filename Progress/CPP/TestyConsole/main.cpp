#include<string>
#include<iostream>
#include<memory>

#include"HCDF.h"
#include"HCDF_Saving.h"
#include"HCDF_Current.h"
#include "Transact.h"

enum class actype { SAVINGS, CURRENT };

int main() {
	HCDF* h;
	
	std::cout << "HCDF Bank" << std::endl;
	while (true) {
		std::string name{};
		long int mobNo{};
		int temp{};
		actype act{};
		std::cout << "Enter your name " << std::endl;
		std::getline(std::cin, name);

		std::cout << "Enter your mobile no. " << std::endl;
		std::cin >> mobNo;


		std::cout << "Enter your account type \n 0: Savings \n 1. Current " << std::endl;
		std::cin >> temp;
		act = static_cast<actype>(temp);
		if (act == actype::SAVINGS) {

			h = new HCDF_Saving{ name, mobNo };
		}
		else {
			h = new  HCDF_Current{ name, mobNo };
		}
		while (true) {
			float amount{};
			std::cout << "Account no.: " << h->acno << std::endl;
			std::cout << "Do you want to 0. withdraw or 1. deposit 2.balance 3.exit \n" << std::endl;
			std::cin >> temp;
			if (temp == 2) {
				std::cout << "Balance:" << h->getBal() << std::endl;
				continue;
			}
			else if (temp == 3) {
				break;
			}
			std::cout << "Enter amount \n" << std::endl;
			std::cin >> amount;
			transact(h, temp, amount);
		}
		std::cout << "Press1 to continue 2 to exit" << std::endl;
		std::cin >> temp;
		if (temp == 2) {
			break;
		}
		else if (temp == 1) {
			continue;
		}

	}
	std::cout << "Bye Bye" << std::endl;
	return 0;
}