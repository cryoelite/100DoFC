#include<iostream>
#include<vector>
#include<algorithm>

using ll=long long;

using namespace std;
int main()
{

	vector<int> g{ 10,9,8,7 };
	vector<int> s{ 5,6,7,8 };
	int count{};
	sort(s.begin(), s.end());
	sort(g.begin(), g.end());
	int i{}, j{};
	while (i < g.size() && j < s.size())
	{
		if (g[i] <= s[j])
		
			count++,i++;
		j++;
	}

	cout << count;
	return 0;

}