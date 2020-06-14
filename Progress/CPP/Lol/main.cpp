#include<iostream>
#include<thread>
#include<list>
#include<mutex>
#include<future>
#include<Windows.h>

std::mutex mx;
std::list<int> g_sT{};
void drawF(int& count)
{
	std::cout << "Starting" << std::endl;
	for (int i = 0; i < count; i++)
	{
		mx.lock();
		g_sT.push_back(i);
		mx.unlock();
	}
	std::cout << "End" << std::endl;
}
void drawF2(int& count)
{
	std::cout << "Starting" << std::endl;
	for (int i = 0; i < count; i++)
	{
		mx.lock();
		g_sT.push_back(i);
		mx.unlock();
	}
	std::cout << "End" << std::endl;
}

void initiator()
{
	int count{ 9000 };
	std::cout << "Main Start" << std::endl;
	std::thread f(drawF, std::ref(count));
	std::thread f2(drawF2, std::ref(count));
	if (f.joinable() && f2.joinable())
	{
		f.join();
		f2.join();
		std::cout << g_sT.size() << std::endl;
	}
	std::cout << "Main End" << std::endl;
}


void drawX(int& count)
{
	std::cout << "Starting" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::lock_guard<std::mutex> mtx(mx);
		g_sT.push_back(i);
	}
	std::cout << "End" << std::endl;
}

void drawX2(int& count)
{
	std::cout << "Starting" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::lock_guard<std::mutex> mtx(mx);
		g_sT.push_back(i);
	}
	std::cout << "End" << std::endl;
}
void initiator2()
{
	int count{ 9000 };
	std::cout << "Main Start" << std::endl;
	std::thread f(drawX, std::ref(count));
	std::thread f2(drawX2, std::ref(count));
	if (f.joinable() && f2.joinable())
	{
		f.join();
		f2.join();
		std::cout << g_sT.size() << std::endl;
	}
	std::cout << "Main End" << std::endl;
}


int Proc()
{
	std::cout << std::this_thread::get_id() << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << i << std::endl;
	}
	return 0;
}


void initiator3()
{
	std::thread f(Proc);
	std::cout << f.get_id() << std::endl;
	std::cout << f.native_handle() << std::endl;
	HANDLE h = f.native_handle();
	std::cout << "Cores: " << std::thread::hardware_concurrency() << std::endl;
	SetThreadDescription(h, L"MooMOo");
	f.join();
}

int Proc2()
{
	std::cout << "Thread" << std::endl;
	return 0;
}

void initiator4()
{
	std::cout << "MT start" << std::endl;
	std::future<int> f{ std::async(std::launch::deferred, Proc2) };
	if (f.valid())
	{
		auto status{ f.wait_for(std::chrono::seconds(5)) };
		switch (status)
		{
		case std::future_status::deferred: std::cout << "Deferred" << std::endl;
			break;
		case std::future_status::ready: std::cout << "ready" << std::endl;
			break;
		case std::future_status::timeout: std::cout << "timeout" << std::endl;
			break;
		default:std::cout << "Nada" << std::endl;
		}
		std::cout << f.get() << std::endl;
	}
}

void initiator5()
{
	using namespace std::chrono_literals;
	std::cout << "MT start" << std::endl;
	std::future<int> f{ std::async(std::launch::deferred, Proc2) };
	if (f.valid())
	{
		auto timepoint{ std::chrono::system_clock::now() };
		auto status{ f.wait_until(timepoint + 1s) };
		switch (status)
		{
		case std::future_status::deferred: std::cout << "Deferred" << std::endl;
			break;
		case std::future_status::ready: std::cout << "ready" << std::endl;
			break;
		case std::future_status::timeout: std::cout << "timeout" << std::endl;
			break;
		default:std::cout << "Nada" << std::endl;
		}
		std::cout << f.get() << std::endl;
	}
}

template<typename T>
int ProcX(std::promise<T>& dat)
{
	try {
		std::cout << "Waiting for object" << std::endl;
		auto x = dat.get_future();
		std::cout << "Still waiting" << std::endl;
		auto cc = x.get();
		std::cout << "Got" << std::endl;
		return cc;
	}
	catch (std::runtime_error& ex)
	{
		std::cout << "Exception caught: " << ex.what() << std::endl;
		return -1;
	}
}
void init6()
{
	using namespace std::chrono_literals;
	std::promise<int> dat;
	std::future<int> f{ std::async(ProcX<int>,std::ref(dat)) };
	std::cout << "MT" << std::endl;
	try {

		std::this_thread::sleep_for(5s);
		//dat.set_value(100);
		throw std::runtime_error("Dumbass ");
		std::cout << "Passed val" << std::endl;
		if (f.valid())
		{
			std::cout << f.get() << std::endl;
		}
	}
	catch (std::runtime_error& ex) {
		dat.set_exception(std::make_exception_ptr(ex));
	}
}
int main()
{
	init6();
	return 0;
}