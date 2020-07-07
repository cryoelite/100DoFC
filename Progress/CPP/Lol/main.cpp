#include<iostream>
#include<optional>
#include<variant>
#include<any>
#include<string>
#include<string_view>
#include<filesystem>
#include<vector>
#include<algorithm>
#include<chrono>
#include<random>
#include<execution>

class TimeIt {
	std::chrono::steady_clock::time_point start;
public:
	TimeIt() :start{ std::chrono::steady_clock::now() } {};

	void StopIt(){
		auto end = std::chrono::steady_clock::now();
		auto diff = end - start;
		std::cout << "Time Taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
	}


};
std::optional<int> whatVal(int temp)
{
	if (temp != 0)
	{
		return std::optional<int>(temp);
	}
	else
	{
		return std::optional<int>();
	}
}

struct Visitor
{
	void operator()(std::string& temp) const {
		std::cout << "String: " << temp + " Lol" << std::endl;
	}
	void operator()(int& temp) const {
		std::cout << "int: " << temp + 10 << std::endl;
	}


};

void variantWork()
{
	std::variant<std::string, int> p{ "s" };

	std::cout << std::get<0>(p) << std::endl;
	std::cout << p.index() << std::endl;
	std::cout << *(std::get_if<0>(&p)) << std::endl;
	p.emplace<int>(5);
	std::cout << p.index() << std::endl;
	p = "hahaha";
	std::visit(Visitor(), p);
	std::visit([](auto& temp) {
		using T = std::decay_t<decltype(temp)>;
		if constexpr (std::is_same_v<T, int>) {
			std::cout << "int: " << temp + 2 << std::endl;
		}
		else if constexpr (std::is_same_v<T, std::string>) {
			std::cout << "string: " << temp + "LOL" << std::endl;
		}

		}, p);


}

void anyWork()
{
	using namespace std::string_literals;
	std::any p{ "go" };

	try {
		std::cout << std::any_cast<std::string>(p) << std::endl;
	}
	catch (std::exception& x) {
		std::cout << x.what() << std::endl;
	}

	p.reset();
	auto p2 = std::make_any<int>(2);
	if (p2.has_value())
	{
		if (p2.type() == typeid(int))
		{
			std::cout << "Int" << std::endl;
		}
	}

	auto& p3 = std::any_cast<int&>(p2);
	p3 = 4;
	std::cout << std::any_cast<int>(p2) << std::endl;
}

void svWork()
{
	using namespace std::string_view_literals;
	std::string_view s1{ "Hello\0uo"sv };
	std::cout << s1.length() << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s1.data() << std::endl;
	s1.remove_prefix(2);
	s1.remove_suffix(2);
	std::cout << s1 << std::endl;


}

void pathHere(std::filesystem::path path) {
	namespace fs = std::filesystem;

	if (path.has_extension()) {
		std::cout << "Ext: " << path.extension().string() << std::endl;
	}if (path.has_filename()) {
		std::cout << "filename: " << path.filename().string() << std::endl;
	}if (path.has_parent_path()) {
		std::cout << "parent_path: " << path.parent_path().string() << std::endl;
	}if (path.has_relative_path()) {
		std::cout << "elative_path: " << path.relative_path().string() << std::endl;
	}if (path.has_root_directory()) {
		std::cout << "root_directory: " << path.root_directory().string() << std::endl;
	}if (path.has_root_name()) {
		std::cout << "root_name: " << path.root_name().string() << std::endl;
	}if (path.has_root_path()) {
		std::cout << "root_path: " << path.root_path().string() << std::endl;
	}if (path.has_stem()) {
		std::cout << "stem: " << path.stem().string() << std::endl;
	}

}
void filesys()
{
	using namespace std::string_view_literals;
	namespace fs = std::filesystem;
	std::string_view svPath{ R"(E:\TestCode)" };
	fs::path path{ svPath };
	std::cout << path.string() << std::endl;
	//	pathHere(path);
	if (!fs::exists(path))
	{
		std::cout << "Path doesnt exist";
		return;
	}
	path /= "FSD";
	if (!fs::create_directory(path)) {
		std::cout << "Fail " << path.string() << std::endl;
	}
	/*fs::remove(path);*/


	//std::vector<fs::directory_entry> dirPath{};
	//for (const auto& x : fs::directory_iterator{ path }) {
	//	dirPath.push_back(x);
	//
	//}
	//
	//	std::partition(dirPath.begin(), dirPath.end(), [](fs::directory_entry &x) {
	//		return x.is_directory();
	//		});
	//	for (const auto& x : dirPath )
	//{
	//	switch (const auto& p = x.path(); /*x.status().type()*/ fs::status(x).type())
	//	{
	//	case fs::file_type::directory:
	//		std::cout << "[DIR]\t" << p.string() << std::endl;
	//		break;
	//	case fs::file_type::regular:
	//		std::cout << "     \t" << p.string() << std::endl;
	//		break;
	//	}
	//}
	path /= "FSD";
	std::error_code ec{};
	std::cout << fs::current_path() << std::endl;
	fs::current_path(path, ec);
	if (ec) {
		std::cout << ec.message() << std::endl;
		return;
	}
	std::cout << fs::current_path() << std::endl;



}

void permDisp(std::filesystem::perms perms) {
	namespace fs = std::filesystem;
	std::cout << ((perms & fs::perms::others_read) != fs::perms::none ? "r" : "-");
	std::cout << ((perms & fs::perms::others_write) != fs::perms::none ? "w" : "-")<<std::endl;
}
void filesysPerms() {

	namespace fs = std::filesystem;
	fs::path path{ "E:\TestCode\1.py" };
	auto perms = fs::status(path).permissions();
	permDisp(perms);
	fs::permissions(path, fs::perms::others_read, fs::perm_options::remove);
	permDisp(perms);

}

void pLL() {
	TimeIt timeIt{TimeIt()};
	constexpr unsigned long long int VAL{ 1000000 };
	std::vector<long long int> p{};
	p.reserve(VAL);
	std::default_random_engine engine{ std::random_device{}() };
	std::uniform_int_distribution<long long int> dist{ 0,VAL };
	for (unsigned i{ 0 }; i < VAL; ++i) {
		p.push_back(dist(engine));
	}
	std::sort(std::execution::par,p.begin(), p.end());
	timeIt.StopIt();

}

int main()
{
	/*std::optional<int> p{ whatVal(0) };
	std::cout << p.value_or(0);


	variantWork();

	anyWork();

	svWork();
	filesys();
	filesysPerms(); */
	pLL();
	return 0;
}