#include<iostream>
#include<string>
#include "main.h"

void loopDiLoop(std::string& result, int sizeA, int sizeB, std::string& a, std::string& b, char& carry)
{
	result.resize(sizeA, '0');
	for (int i{ sizeA }, j{ sizeB }; i >= 0; --i, --j)
	{
		char first{ a[i] };
		char second{};
		if (j < 0) second = '0';
		else second = b[j];
		
		if (carry == '1')
		{
			if (first == '1' && second == '1')
			{
				carry = '1';
				result[i] = '1';
			}
			else if ((first == '0' && second == '1') || (first == '1' && second == '0')) {
				carry = '1';
				result[i] = '0';
			}
			else {
				carry = '0';
				result[i] = '1';
			}
		}
		else {
			if (first == '1' && second == '1')
			{
				carry = '1';
				result[i] = '0';
			}
			else if ((first == '0' && second == '1') || (first == '1' && second == '0')) {
				carry = '0';
				result[i] = '1';
			}
			else {
				carry = '0';
				result[i] = '0';
			}
		}
	}

	if (carry == '1')
	{
		result.insert(0, "1");
	}
}

int main()
{
	using namespace std;
	string a{ "023333333123123" };
	string b{ "111111" };

	int sizeA{ (int)a.size()  };
	int sizeB{ (int)b.size()  };
	string result{};


	char carry{ '0' };
	if (sizeA > sizeB)
	{
		loopDiLoop(result, sizeA, sizeB, a, b, carry);
	}
	else {
		loopDiLoop(result, sizeB, sizeA, b, a, carry);
	}
	cout << result;


	return 0;
}