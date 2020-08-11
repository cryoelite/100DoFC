#pragma once
#include<memory>

class Sim
{
	inline static int count = 0;
	std::unique_ptr<int> hCount;
public:
	Sim();
	Sim(int temp);
	Sim(const Sim& temp);
	Sim(Sim&& temp)noexcept(true);
	int getVal();
	~Sim();
};
