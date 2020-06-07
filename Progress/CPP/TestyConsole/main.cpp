#include<iostream>
#include<fstream>
#include<string>

struct getAd
{
	long long int p;
	std::string l;
};

void writeAd(getAd &g)
{
	std::cout << "write text" << std::endl;
	std::ofstream out;
	out.open(" datum.txt");
	out.write((const char*)&g.l, sizeof(g.l));
	std::cout << "Pos: " << out.tellp() << std::endl;
	out << "Or not \n";
	out.close();
}

void readAd()
{
	std::cout << "read text" << std::endl;
	std::ifstream inp;
	inp.open("datum.txt", std::ios::in);
	if (!inp.is_open()) {
		std::cout << "No such file" << std::endl;
		return;
	}
	std::string temp;
	inp >> temp;
	std::cout << "temp : " << temp << std::endl;
	inp.seekg(0);
	std::getline(inp, temp);
	std::cout << "temp now:" << temp << std::endl;
	inp.close();


}

void writeBinary(getAd  *g)
{
	std::cout << "write binary" << std::endl;
	std::ofstream out;
	out.open("binaryFile", std::ios::binary | std::ios::out);
	out.write((const char*)g , sizeof(getAd));
	out.close();

}

void readBinary()
{
	std::cout << "read binary" << std::endl;
	getAd g;
	std::ifstream in;
	in.open("binaryFile", std::ios::binary | std::ios::in);
	if (!in.is_open()) {
		std::cout<<"Failed" << std::endl;
	}
	std::string p;
	in.read((char*)&g, sizeof(getAd));
	std::cout << " Binna: " << g.p << std::endl;

}
int main()
{
	
	getAd p;
	p.p = std::numeric_limits<long long int>::max();
	p.l = R"bvc(Yala Habibi \n)bvc";
	writeAd(p);
	readAd();
	writeBinary(&p);
	readBinary();
	std::cout << "Fin";
}