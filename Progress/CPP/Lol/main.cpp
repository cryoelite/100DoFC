#include<iostream>
#include<array>

using namespace std;
template<typename T,int size>
void SIZE(T arr[size])
{
	cout << sizeof(arr);
}


int main()
{
	int arr[]{ 1,2,3 };
	SIZE<int,3>(arr);
	return 0;
}