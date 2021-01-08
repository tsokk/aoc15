#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include "aoc15.h"

using namespace std;

bool has_wovels(const string& s)
{
	regex pat {"(.*[aeiou].*){3,}"};
	return regex_match(s,pat);
}

bool has_duplicates(const string& s)
{
	regex pat {R"(.*([a-z])\1.*)"};
	return regex_match(s,pat);
}

bool has_forbidden(const string& s)
{
	regex pat {".*(ab|cd|pq|xy).*"};
	return regex_match(s,pat);
}

bool is_nice(const string& s)
{
	return has_wovels(s) && has_duplicates(s) && !has_forbidden(s);
}

bool has_pair_twice(const string& s)
{
	regex pat {R"(.*(..).*\1.*)"};
	return regex_match(s,pat);
}

bool has_repeated(const string& s)
{
	regex pat {R"(.*([a-z]).\1.*)"};
	return regex_match(s,pat);
}

bool is_really_nice(const string& s)
{
	return has_pair_twice(s) && has_repeated(s);
}

void day05()
{
	ifstream ifs {"input/5.txt"};
	
	if (!ifs) cerr << "no input file";

	vector<string> ss;
	for (string s; getline(ifs,s); )
		ss.push_back(s);
	
	int ans = 0;
	for (const auto& s : ss)
		if (is_nice(s)) ++ans;

	cout << "day 5,part 1," << ans << '\n';

	ans = 0;
	for (const auto& s : ss)
		if (is_really_nice(s)) ++ans;
	
	cout << "day 5,part 2," << ans << '\n';
}
