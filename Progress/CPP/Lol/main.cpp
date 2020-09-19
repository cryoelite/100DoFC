#include<future>
#include<iostream>
#include<thread>
#include<vector>

using vectorPair = std::vector<std::pair<int, long long>>;
using timer=std::chrono::system_clock;
vectorPair name0() {
    vectorPair aTimeObject{};
	aTimeObject.push_back(std::make_pair(1,timer::now().time_since_epoch().count()));


std::this_thread::sleep_for(std::chrono::seconds(5));
aTimeObject.push_back(std::make_pair(2,timer::now().time_since_epoch().count()));
return aTimeObject;
}

int main()
{
	using namespace std;
	vectorPair ogTime{};
	ogTime.push_back(make_pair(3,timer::now().time_since_epoch().count()));

	future f1{ async(launch::async,name0) };
	
	std::this_thread::sleep_for(std::chrono::seconds(2));
	ogTime.push_back(make_pair(4,timer::now().time_since_epoch().count()));
	if (f1.valid())
	{
			ogTime.push_back(make_pair(5,timer::now().time_since_epoch().count()));
			auto aNewObj = f1.get();
			ogTime.push_back(aNewObj[0]);
			ogTime.push_back(aNewObj[1]);
	}

	
	ogTime.push_back(make_pair(6,timer::now().time_since_epoch().count()));

	sort(ogTime.begin(), ogTime.end(), [](const auto& x,const auto &y) {
		return x.second < y.second;
		});

	for (auto& x : ogTime)
		cout << x.first << " " << x.second << endl;
	return 0;
}