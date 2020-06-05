#pragma once

class Dodo {
	int a_val;
	
public:
	int* p;
	Dodo();
	Dodo(int a, int& b);
	Dodo(float, float) = delete;
	~Dodo();
	void setVal(int temp);
	int getVal()const;
	bool operator == (Dodo& temp);
	Dodo(const Dodo& temp);
	Dodo( Dodo&& temp);
	operator int();
	Dodo& operator =(Dodo& temp);
};