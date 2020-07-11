#include<iostream>
#include<set>
#include<string>
#include<sstream>


void filler(std::multiset<int>& tempVec, std::string& tempString)
{
	std::stringstream splitter(tempString);
	std::string splitVal{};
	while (std::getline(splitter, splitVal, ' '))
	{
		tempVec.insert(stoi(splitVal));
	}
	return;
}

void solver(std::multiset<int>& villain, std::multiset<int>& hero, size_t& size)
{
	for (int i{ 0 }; i < size; ++i)
	{
		auto itrVillain = villain.begin();
		auto itrHero = hero.begin();
		std::advance(itrHero, i);
		std::advance(itrVillain, i);
		if (*itrHero < *itrVillain) {
			std::cout << "LOSE";
			return;
		}
	}

	std::cout << "WIN";
}
int main()
{
	int nOfTestCases{};
	std::cin >> nOfTestCases;
	for (int i{ 0 }; i < nOfTestCases; ++i)
	{
		using namespace std;
		size_t size;
		string tempInput{};
		multiset<int> villain{};
		multiset<int> hero{};
		cin >> size;
		cin.ignore();
		getline(cin, tempInput);
		filler(villain, tempInput);
		getline(cin, tempInput);
		filler(hero, tempInput);
		solver(villain, hero, size);
	}

	return 0;
	
}