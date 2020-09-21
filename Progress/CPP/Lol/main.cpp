#include<iostream>
#include<thread>
#include<windows.h>
#include<future>




void loading(int& a, HANDLE& consoleHandle, int& percent)
{
	COORD coord{ 0,1 };
	SetConsoleCursorPosition(std::ref(consoleHandle), std::ref(coord));

	std::cout << "\33[2K";
	std::cout << "\r";
	std::cout << percent;
	std::cout << "%";
	coord.X = a;
	coord.Y = 0;
	SetConsoleCursorPosition(std::ref(consoleHandle), std::ref(coord));
}

int main()
{
	using namespace std;

	CONSOLE_SCREEN_BUFFER_INFO csbi;


	volatile char block{ static_cast<char>(219) };
	char backspace[]{ "\b \b" };
	int percent{};
	char colorCode[8] = "\x1b[36m";
	HANDLE consoleHandle{ GetStdHandle(STD_OUTPUT_HANDLE) };
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);
	int vSize{ csbi.srWindow.Right - csbi.srWindow.Left };


	auto output{ [&](int& i) {
		future f1{ async(launch::async,loading,std::ref(i),std::ref(consoleHandle),std::ref(percent)) };
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
} };
	for (int i{}; i < vSize; ++i)
	{
		
		percent = i * 100 / vSize;

		int colorVal = percent*12/100;
		SetConsoleTextAttribute(consoleHandle,colorVal+3);
		cout << block;
		output(i);

	}
	
		SetConsoleTextAttribute(consoleHandle,15);
	for (int i{ vSize }; i >= 0; --i)
	{
		percent = i * 100 / vSize;;
		cout << backspace;
		output(i);
	}
	return 0;

}