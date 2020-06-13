#include<iostream>
#include<array>



template<typename T>
using Comp = std::pair<int, int>(*)(T x, T y);
//using Comp = bool(*)(int, int);
//template<typename T, typename X>
//struct Ad
//{
//
//	T operator ()(T first, T second, X third)
//	{
//		std::cout << std::boolalpha << third(first, second) << std::endl;
//		return first + second;
//	}
//};

int main()
{
	/*Ad<int, Comp> a;
	auto c{ [](auto a, auto b) {
		return a < b;
} };
	std::cout << a(2, 3, [](auto a, auto b)->bool {
		return a < b;
		}) << std::endl;
	std::cout << a(2, 3, c);*/

	std::array<int, 6> a{ 1,2,5,3,2,4 };
	auto x = [](auto b, auto c)->std::pair<int, int> {
		std::pair<int, int> a{*b,*b};
		while (b != c)
		{
			if (a.first > * b)
			{
				a.first = *b;
			}
			if (a.second < *b)
			{
				a.second = *b;
			}
			++b;
		}
		return a;
	};
	std::pair<int, int> b{ x(a.begin(),a.end()) };
	std::cout << b.first << ":" << b.second<<std::endl;
	return 0;

}