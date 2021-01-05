#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Point { int x, y; };

class Santa {
public:
	Santa() { }
	void visit(char d)
	{
		if (d=='^')
			++pos.y;
		else if (d=='>')
			++pos.x;
		else if (d=='v')
			--pos.y;
		else if (d=='<')
			--pos.x;
		else
			cerr << "unknown direction\n";
		visits.push_back(pos);
	}
	vector<Point>& visited()
	{
		return visits;
	}
private:
	Point pos {0,0};
	vector<Point> visits {{0,0}};
};

string read_input(ifstream& ifs)
{
	if (ifs.fail())
		cerr << "failed to open '3.txt' for input\n";
	string s;
	ifs >> s;
	return s;
}

void day03()
{
	ifstream ifs {"input/3.txt"};
	string directions = read_input(ifs);
	Santa claus {};
	for (const auto& d : directions)
		claus.visit(d);
	map<string,int> places;
	for (const auto& v : claus.visited()) {
		string key = to_string(v.x) + to_string(v.y);
		places[key] += 1;
	}
	cout << "day 3,part 1," << places.size() << '\n';

	Santa santa {};
	Santa robo_santa {};
	for (auto i=0; i<directions.size(); ++i)
		if (i%2==0)
			santa.visit(directions[i]);
		else
			robo_santa.visit(directions[i]);
	map<string,int> next_year_places;
	for (const auto& v : santa.visited()) {
		string key = to_string(v.x) + to_string(v.y);
		next_year_places[key] += 1;
	}
	for (const auto& v : robo_santa.visited()) {
		string key = to_string(v.x) + to_string(v.y);
		next_year_places[key] += 1;
	}
	cout << "day 3,part 2," << next_year_places.size() << '\n';
	
}

