#include <iostream>
#include<vector>

void sortIt(std::vector<int> &a)
{
	int temp{0};
	while (temp == 0)
	{
		int tempS{ 0 };
		for (int i{ 0 }; i < a.size()-1; ++i)
		{
			if (a[i] > a[i + 1])
			{
				tempS = 1;
				int tempX{ a[i] };
				a[i] = a[i + 1];
				a[i + 1] = tempX;
			}
			
		}
		if (tempS != 0) {
			temp = 0;
		}
		else
		{
			temp = 1;
		}
	}


	for (auto& x : a)
	{
		std::cout << x << std::endl;
	}
	return;
}

int main() {
	int size;
	std::cout << "Enter number of elements: ";
	std::cin >> size;
	std::cout << "\nEnter element values: ";
	std::vector<int> a;
	for (int i = 0; i < size; ++i)
	{
		int temp;
		std::cin >> temp;
		a.push_back(temp);
		std::cout << std::endl;
	}
	sortIt(a);


	return 0;

}