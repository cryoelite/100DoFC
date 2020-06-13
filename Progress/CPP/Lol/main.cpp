#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<functional>


void arr()
{
	std::array<int, 6> a{ 1,2,45,3,2,7 };
	std::cout << *(a.data()) << std::endl;
	std::cout << a[2] << std::endl;
}
void vec()
{
	std::vector<int> a{ 1,2 };
	a.push_back(3);
	std::cout << *(a.data() + 2) << std::endl;
	std::cout << a.size() << std::endl;
	a.pop_back();
	std::cout << a.size() << std::endl;
	a.insert(a.begin() + 1, 4);
	std::cout << "xxx" << std::endl;
	for (auto& x : a)
	{
		std::cout << x << std::endl;
	}
	a.erase(a.end() - 1);
	std::cout << a[2] << std::endl;
}
void Dec()
{
	std::deque<int> a{ 1,2 };
	a.push_back(3);
	std::cout << a.size() << std::endl;
	a.pop_back();
	std::cout << a.size() << std::endl;
	a.insert(a.begin() + 1, 4);
	for (auto& x : a)
	{
		std::cout << x << ":" << &x << " ";
	}
	a.erase(a.end() - 1);
	a.pop_front();
	a.push_front(2);
	std::cout << a[1] << std::endl;
}
void LL()
{
	//doubly link list
	std::list<int> a{ 1,3 };
	a.push_back(2);

	a.push_back(2);
	a.push_front(3);
	for (auto& x : a)
	{
		std::cout << x << ":" << &x << " ";
	}
	a.erase(a.begin());
	a.pop_back();
	a.pop_front();
}
void FL()
{
	//singly link list
	std::forward_list<int> a{ 1,3 };
	a.push_front(3);

	a.pop_front();
	a.push_front(4);

	a.erase_after(a.begin());
	a.insert_after(a.begin(), 5);
	for (auto& x : a)
	{
		std::cout << x << ":" << &x << " ";
	}
}
void SS()
{
	//binary tree 
	std::set<int, std::less<int>> a{ 1,3,5,7,2,1 };
	a.insert(6);
	a.erase(6);
	a.erase(a.begin());
	auto b = a.find(7);
	if (b != a.end())
	{
		std::cout << "Found " << *b << std::endl;
	}
	for (auto& x : a)
	{
		std::cout << x << ":" << &x << " ";
	}
}
void MS()
{
	//binary tree 
	std::multiset<int, std::less<int>> a{ 1,3,5,7,2,1 };
	a.insert(6);
	a.erase(6);
	a.erase(a.begin());
	auto b = a.find(7);
	if (b != a.end())
	{
		std::cout << "Found " << *b << std::endl;
	}
	for (auto& x : a)
	{
		std::cout << x << ":" << &x << " ";
	}
	std::cout << std::endl;
	a.insert(8);
	a.insert(8);
	a.insert(9);
	auto c = a.equal_range(10);
	while (c.first != c.second)
	{
		std::cout << *(c.first)++ << " " << std::endl;

	}
}
void mp()
{
	//binary tree but now is key-value pair
	std::map<int, std::string, std::greater<int>> a{
	{0,"hello"},
	{7,"bye"},
	{1,"ya"},
	{8,"na"}
	};
	a.insert(std::pair<int, std::string>(5, "ha"));
	a.insert(std::make_pair(0, R"("Hello ?")"));
	a[1] = "override";
	a.erase(7);
	auto b = a.find(8);
	if (b != a.end())
	{
		std::cout << "Found " << b->first << std::endl;
	}
	for (auto& x : a)
	{
		std::cout << x.first << ":" << x.second << " ";
	}
	return;
}
void mmp()
{
	std::multimap<int, std::string, std::greater<int>> a{
	{0,"hello"},
	{7,"bye"},
	{1,"ya"},
	{8,"na"}
	};
	a.insert(std::pair<int, std::string>(5, "ha"));
	a.insert(std::make_pair(0, R"(Hello ?)"));
	a.erase(7);
	auto b = a.find(8);
	if (b != a.end())
	{
		std::cout << "Found " << b->first << std::endl;
	}
	for (auto& x : a)
	{
		std::cout << x.first << ":" << x.second << " ";
	}
	std::cout << std::endl;
	auto c = a.equal_range(0);
	while (c.first != c.second)
	{
		std::cout << c.first->first << ":" << c.first->second << " ";
		c.first++;
	}

	return;
}
void us()
{
	std::unordered_set<std::string> a{ "hello", "yea", "ashit" };
	a.insert("watchdog");
	a.insert("watcher");

	std::cout << a.bucket_count() << std::endl;
	std::cout << a.load_factor() << std::endl;
	std::cout << a.size() << std::endl;


	for (auto& x : a)
	{
		std::cout << a.bucket(x) << ":" << x << " ";
	}
	//rest same as set, same for multiset
}
void um()
{
	std::unordered_map<int, double> a{ {0,2.2},{5,33.2},{2,3.4} };
	a[3] = 4.3;
	for (auto& x : a)
	{
		std::cout << a.bucket(x.first) << ":" << x.first << " + " << x.second << " ";
	}
}

class Ela
{
public:
	int num;
	std::string name;
	Ela(int num, const std::string& name)
	{
		this->num = num;
		this->name = name;
	}

};
struct Elahash
{
	size_t operator()(const Ela& a)const {
		return std::hash<int>{}(a.num) ^ std::hash<std::string>{}(a.name);
	}
};
struct ElaEqual
{
	bool operator()(const Ela& a, const Ela b)const
	{
		return a.num == b.num;
	}
};
struct Elaless
{
	bool operator()(const Ela& a, const Ela b)const
	{
		return a.num < b.num;
	}
};



void CustomHashForCustomObjects()
{
	Ela a(0, "Hallo");
	Ela b(1, "Yaloo");
	Ela c(5, "Na");
	std::unordered_set<Ela, Elahash, ElaEqual> e1{ a,b,c };
	e1.erase(Ela(1, "Yaloo"));
	e1.insert(Ela(2, "Naah"));

	for (auto& x : e1)
	{
		std::cout << x.num << ":" << x.name << " ";
	}
}

void Algos()
{
	Ela a(0, "Hallo");
	Ela b(1, "Yaloo");
	Ela c(5, "Na");
	/*std::set<Ela,Elaless> e1{ a,b,c };*/
	std::vector<Ela> e1{ a,b,c };
	std::sort(e1.begin(), e1.end(), [](const Ela& first, const Ela& second) {
		return first.num < second.num;
		});
	int cCount{};
	e1.push_back(Ela(2, "Yaloo"));
	cCount = std::count_if(e1.begin(), e1.end(), [](const Ela& first) {
		return first.name == "Yaloo";
		});
	std::cout << cCount << std::endl;
	//theres also find_if and for_each.
	for (auto& x : e1)
	{
		std::cout << x.num << ":" << x.name << " ";
	}
}
int main()
{
	Algos();
	return 0;
}