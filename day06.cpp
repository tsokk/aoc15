#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

struct Point { int x, y; };

struct Light { int brightness; };

enum class Operation { turn_on, turn_off, toggle };

struct Instruction {
	Operation op;
	Point a, b;
};

vector<Instruction> read_input()
{
	ifstream ifs {"input/6.txt"};
	if (!ifs)
		cerr << "could not open file '6.txt' for reading\n";

	string line;
	int lineno = 0;
	vector<Instruction> vi;

	regex row {R"(^(turn\son|turn\soff|toggle)\s(\d+),(\d+)\sthrough\s(\d+),(\d+)$)"};

	while (getline(ifs,line)) {
		++lineno;
		smatch matches;

		if(!regex_match(line,matches,row))
			cerr << "bad line: " << lineno << '\n';

		string curr_s = matches[1];
		Operation curr_op;
		if (curr_s=="turn on") {
			curr_op = Operation::turn_on;
		}
		else if (curr_s=="turn off") {
			curr_op = Operation::turn_off;
		}
		else if (curr_s=="toggle") {
			curr_op = Operation::toggle;
		}
		else {
			cerr << "invalid operation on line: " << lineno << '\n';
		}
		int curr_x = stoi(matches[2]);
		int curr_y =  stoi(matches[3]);
		int curr_u = stoi(matches[4]);
		int curr_w = stoi(matches[5]);
		
		Point a {curr_x,curr_y};
		Point b {curr_u,curr_w};
		vi.push_back({curr_op,a,b});
	}

	return vi;
}

void lights_on(vector<vector<Light>>& vl, const Instruction& ins)
{
	for (int i=ins.a.x; i<=ins.b.x; ++i)
		for (int j=ins.a.y; j<=ins.b.y; ++j)
			vl[i][j].brightness += 1;
}

void lights_off(vector<vector<Light>>& vl, const Instruction& ins)
{
	for (int i=ins.a.x; i<=ins.b.x; ++i)
		for (int j=ins.a.y; j<=ins.b.y; ++j)
			if (vl[i][j].brightness>0)
				 vl[i][j].brightness -= 1;
}

void lights_toggle(vector<vector<Light>>& vl, const Instruction& ins)
{
	for (int i=ins.a.x; i<=ins.b.x; ++i)
		for (int j=ins.a.y; j<=ins.b.y; ++j)
			vl[i][j].brightness += 2;
}

void day06()
{
	vector<Instruction> vi = read_input();

	const int n = 1000;
	Light off {0};
	vector<Light> v(n,off);
	vector<vector<Light>> vl(n,v);

	for (const auto& i : vi) {
		switch (i.op) {
		case Operation::turn_on:
			lights_on(vl, i);
			break;
		case Operation::turn_off:
			lights_off(vl, i);
			break;
		case Operation::toggle:
			lights_toggle(vl, i);
			break;
		default:
			cerr << "invalid operation\n";
			break;
		}
	}

	int ans = 0;
	for (const auto& ll : vl)
		for (const auto& l : ll)
			ans += l.brightness;
	cout << "day 6,part 2," << ans << '\n';
}
