#include <algorithm>
#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include "aoc15.h"

using namespace std;

class Cuboid {
public:
	Cuboid(int l, int w, int h)
		:length{l}, width{w}, height{h}
	{
		vector<int> dim {length, width, height};
		sort(dim.begin(), dim.end());
		smallest_dims = make_pair(dim[0], dim[1]);
	
	}
	int area()
	{
		return 2*length*width + 2*width*height + 2*height*length;
	}
	int smallest_side()
	{
		return smallest_dims.first * smallest_dims.second;
	}
	int paper_consumption()
	{
		return area() + smallest_side();
	}
	int ribbon_consumption()
	{
		int consumption = smallest_dims.first*2
			+ smallest_dims.second*2
			+ length*width*height;
		return consumption;
	}
private:
	int length, width, height;
	pair<int,int> smallest_dims;

};

struct Present { int length, width, height; };

ifstream& operator>>(ifstream& ifs, Present& p)
	// read lengthxwidthxheight Note: dimensions separated by "x"
{
	int length, width, height;
	char c1, c2;
	ifs >> length >> c1 >> width >> c2 >> height;
	if (c1=='x' && c2=='x') {
		p = {length, width, height};
		return ifs;
	}
	ifs.setstate(ios_base::failbit);
	return ifs;
}

void day02()
{
	ifstream ifs {"input/2.txt"};
	if (ifs.fail())
		cerr << "failed to open '2.tx2' for input\n";

	int part1_ans = 0;
	int part2_ans = 0;
	for (Present pp; ifs>>pp; ) {
		Cuboid cu {pp.length, pp.width, pp.height};
		part1_ans += cu.paper_consumption();
		part2_ans += cu.ribbon_consumption();
	}
	cout << "day 2,part 1," << part1_ans << '\n';
	cout << "day 2,part 2," << part2_ans << '\n';
}
