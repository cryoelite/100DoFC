#include<iostream>
#include<vector>


using ll = long long;

using namespace std;



int main()
{
	vector<vector<string>> board{
		{".",".",".",".",".",".",".","."},
		{".",".",".","p",".",".",".","."},
		{".",".",".","p",".",".",".","."},
		{"p","p",".","R",".","p","B","."},
		{".",".",".",".",".",".",".","."},
		{".",".",".","B",".",".",".","."},
		{".",".",".","p", ".", ".", ".", "."},
		{ ".", ".", ".", ".", ".", ".", ".", "." }
	};

	vector<pair<int, int>> valsP{};
	vector<pair<int, int>> valsB{};
	auto begB = valsB.begin();
	auto endB = valsB.end();
	pair<int, int> valsR{};
	int count{};
	for (int i{}; i < board.size(); ++i)
		for (int j{}; j < 8; ++j)
		{
			if (board[i][j] == "p")
				valsP.push_back(make_pair(j, i));
			if (board[i][j] == "R")
				valsR = make_pair(j, i);
			if (board[i][j] == "B")
				valsB.push_back(make_pair(j, i));
		}
	for (int i{}; i < valsP.size(); ++i)
	{
		int firstP = valsP[i].first;
		int secondP = valsP[i].second;
		if (firstP == valsR.first)
		{
			int flag{};
			for (int j{}; j < valsB.size(); ++j)
			{
				cout << valsB[j].first<<" "<<firstP<<"\n";
				if (valsB[j].first <= firstP &&valsB[j].second==secondP)
				{
				
					flag = 1;
				}
			}
			if (flag == 0)
			{
				count++;
			}
		}
		else if (secondP == valsR.second)
		{
			int flag{};

			for (int j{}; j < valsB.size(); ++j)
			{
				if (valsB[j].second <= secondP &&valsB[j].first==firstP)
				{
					cout << "na";
					flag = 1;
				}
			}
			if (flag == 0)
				count++;

		}


	}

	cout << count;

	return 0;
}