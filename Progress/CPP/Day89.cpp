#https://leetcode.com/problems/add-strings/


#include<iostream>
#include<string>


void loopDiLoop(std::string& result, int sizeA, int sizeB, std::string& a, std::string& b, int& carry)
{
	using namespace std;
	result.resize(sizeA, '0');
	for (int i{ sizeA }, j{ sizeB }; i >= 0; --i,--j)
	{
		int first{ a[i]-48 };
		int second{};
		if (j >= 0) second = b[j]-48;
		if (first < 0) first = 0;
		if (second < 0) second = 0;
		int temp{ first + second + carry };
		carry = temp / 10;
		int mod= temp % 10+48;
		result[i] = mod;
	
	}
	if (carry > 0) result.insert(0, to_string(carry));
	
}

int main()
{
	using namespace std;
	string a{ "0" };
	string b{ "0" };

	int sizeA{ (int)a.size() };
	int sizeB{ (int)b.size() };
	string result{};


	int carry{};
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

#https://leetcode.com/problems/add-to-array-form-of-integer/

#include<iostream>
#include<vector>


int main()
{
	using namespace std;
	vector<int> A{ 9,9 };
	int K{ 99 };
	int size{(int) A.size() - 1 };
	int carry{};
	while (K > 0 || carry != 0)
	{
		int temp = K % 10;
		
		if (size < 0) {

			auto it = A.begin();
			A.insert(it, 0);
			size = 0;
		}
		int &value{ A[size] };
		temp = value + temp+carry;
		value = temp % 10;
		carry = temp / 10;

		K = K / 10;
		size--;
	}

	for (auto& x : A)
		cout << " x: " << x << "\n";
	return 0;
}