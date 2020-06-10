#include<iostream>
#include<string.h>

template<typename Y>
using PPAP = Y;

void add_stuff()
{
	std::cout << "The End" << std::endl;
}

template<typename...T, typename X>
void add_stuff(const X& first, const T&... args)
{
	std::cout << first ;
	if (sizeof...(args) != 0)
		std::cout << " , ";
	else
		std::cout << std::endl;
	add_stuff(args...);
}

int main()
{
	add_stuff(1, "2", 2.3, "hello", 4.0f);
	PPAP<int> p{ 2 };
	PPAP<float> s{ 2 };
	std::cout << typeid(s).name() << std::endl;
	return 0;
}