#include<iostream>

template<typename X>

X bax(X first, X second)
{
	return first + second;
}

std::string convert(char t)
{
	std::string s{ t };
	return s;
}
void doSome(const char* a, const char* b)
{
	std::cout << std::strcmp(b,a) << std::endl;
	return;
}
int main()
{
	const char* c{ "c" };
	const char* d{ "d" };
	std::string s{ c };
	std::string f{ d };
	std::cout << bax(s, convert(*c)) << std::endl;
	doSome(c, d);
	return 0;

}