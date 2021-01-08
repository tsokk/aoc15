#include <iostream>
#include "aoc15.h"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "day as argument expected\n";
		return 1;
	}
	auto day = std::stoi(argv[1]);
	if (day < 1 || day > 25) {
		std::cerr << "day must be between 1 and 25\n";
		return 1;
	}
	switch (day) {
	    case 1:
	        day01();
	        break;
	    case 2:
	        day02();
	        break;
	    case 3:
	        day03();
	        break;
	    case 4:
	        day04();
	        break;
	    case 5:
	        day05();
	        break;
	    default:
	        std::cout << "not implemented yet\n";
	        break;
	}
}
