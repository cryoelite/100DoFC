#include<iostream>
#include<vector>
#include<numeric>
#include<functional>



int main()
{
	std::vector<int> a{ 1,2,3,4 };
	std::cout<<std::accumulate(a.begin(), a.end(), 0,std::plus<int>());

	return 0;
}