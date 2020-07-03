#include<iostream>
#include<type_traits>



int sum()
{
	return 0;
}

template<typename T, typename ...ArgX>
int sum(T a, ArgX ...args)
{
	return a + sum(args...);
}


template<typename ...ArgX>
int sum2(ArgX ...args)
{
	return (args + ... + 0);
}


template<typename ...ArgX, typename T>
int sum3(T a, ArgX ...args)
{
	return (a(args)+ ... + 0);
}

template<typename T>
void whatIsIt(T &val)
{
	if constexpr(std::is_pointer_v<T>) {
		std::cout << "Pointer";
	} 
	else if constexpr(std::is_array_v<T>)
	{
		std::cout << "Array";
	}
	else
	{
		std::cout << "Dunno Dun Care";
	}
}

int main()
{/*
	std::cout << sum(1, 2, 3, 4);
	std::cout << sum2(1, 2, 3, 4);*/
	//std::cout << sum3([](int x) {
	//	return x; },1,2,3,4);
	int* p = new int{1};
	int a[]={0,1};
	whatIsIt(p);
	whatIsIt(a);

	return 0;
}