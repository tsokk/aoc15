#include <iostream>
#include <fstream>
#include <string>
#include "aoc15.h"

using namespace std;

class Elevator {
public:
	Elevator(int f) :fl{f} { }
	void move(const char c)
	{
		if (c == '(')
			++fl;
		else
			--fl;
	}
	int floor() { return fl; }
	void floor(int f)
	{
		fl = f;
	}
private:
	int fl;
};

string read_input()
{
	ifstream ifs {"input/1.txt"};
	if (ifs.fail())
		cerr << "failed to open '1.txt' for input\n";
	string s;
	ifs >> s;
	return s;
}

void day01()
{
	string s = read_input();
	Elevator el {0};
	for (const auto& c : s)
		el.move(c);
	cout << "day1,part 1," << el.floor() << '\n';

	int pos = 0;
	el.floor(0);
	while (el.floor() != -1) {
		char c = s[pos];
		el.move(c);
		++pos;
	}
	cout << "day 1,part 2," << pos << '\n';
}
