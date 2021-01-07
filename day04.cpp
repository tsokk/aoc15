#include <iostream>
#include <string>
#include "md5.h"

using namespace std;

bool ok(const string& r, const string& s, const int& i)
{
	string digest = MD5(s + to_string(i)).hexdigest();
	int n = r.size();
	return digest.substr(0,n)==r;
}

void day04()
{
	string s {"yzbqklnj"};
	int num = 1;	// looking for lowest positive number
	while (!ok("00000",s,num)) ++num;
	cout << "day 4,part 1," << num << '\n';

	num = 1;
	while (!ok("000000",s,num)) ++num;
	cout << "day 4,part 2," << num << '\n';
}
