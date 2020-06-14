#include<iostream>
#include<string>
#include<cmath>

void doStuff(std::string& x)
{
	if (x[0] == '0' && x[1] == 'x')
	{
		x = x.substr(2, -1);
	}

	long long finalSum{};
	int j{ static_cast<int>(x.size() - 1) };
	int temp{};
	for (auto& y : x)
	{
		temp = y;
		if (temp - 48 >= 0 && temp - 48 <= 9)
		{
			finalSum += pow(16, j) * (temp - 48);

		}
		else if (temp >= 65 && temp <= 97) {
			finalSum += pow(16, j) * (temp - 55);

		}
		else {
			finalSum += pow(16, j) * (temp - 87);

		}
		j--;
	}
	std::cout << "Hex: " << x << " Int: " << finalSum << std::endl;
}


int main()
{
	long long x{};
	std::string s{};
	int option{};
	std::cout << "Enter hex " << std::endl;
	std::getline(std::cin, s);
	doStuff(s);
	return 0;
}