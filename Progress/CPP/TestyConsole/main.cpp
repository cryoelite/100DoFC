#include <iostream>
#include<string>
#include<vector>

enum class Case { SENSITIVE, INSENSITIVE };

std::vector<int>
FindAll(
	const std::string target,         //Target string to be searched
	std::string search_string,         //The string to search for
	Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
	size_t offset = 0)
{
	std::vector<int> arr{}, temp{};
	int j{ 0 };
	if (searchCase == Case::SENSITIVE) {

		std::cout << "Sensitive" << std::endl;

		for (int i = offset; i < search_string.length(); ++i) {
			if (target[j] == search_string[i]) {
				temp.push_back(i);
				++j;
			}
			else if (j == 1) {
				temp.clear();
				if (target[0] == search_string[i]) {
					temp.push_back(i);
				}

			}
			else {
				temp.clear();
				j = 0;
			}
			if (temp.size() == target.size()) {
				for (auto x : temp) {
					arr.push_back(x);
				}
				arr.push_back(-1);
				temp.clear();
				j = 0;
			}
		}

	}
	else {
		std::cout << "Insensitive" << std::endl;

		for (int i = offset; i < search_string.length(); ++i) {
			if (tolower(target[j]) == tolower(search_string[i])) {
				temp.push_back(i);
				++j;
			}
			else if (j == 1) {
				temp.clear();
				if (tolower(target[0]) == tolower(search_string[i])) {
					temp.push_back(i);
				}

			}
			else {
				temp.clear();
				j = 0;
			}
			if (temp.size() == target.size()) {
				for (auto x : temp) {
					arr.push_back(x);
				}
				arr.push_back(-1);
				temp.clear();
				j = 0;
			}
		}
	}
	return arr;
}
int main() {
	std::string target{}, searchString, ccas;
	int offset;
	std::cout << "Enter the string, then the target , then the case and then the offset \n";
	std::getline(std::cin, searchString);
	std::getline(std::cin, target);
	std::getline(std::cin, ccas);
	std::cin >> offset;
	auto it = ccas.begin();
	while (it != ccas.end()) {
		*it = tolower(*it);
		++it;
	}
	std::vector<int> a1{ FindAll(target,searchString,ccas == "sensitive" ? Case::SENSITIVE : Case::INSENSITIVE,offset) };
	for (auto x : a1) {
		std::cout << x << std::endl;
	}


	return 0;
}
