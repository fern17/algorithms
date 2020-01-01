#include "Tools.h"
#include <iostream>
namespace Tools
{
	void printVector(std::vector<int>& v, std::string separator)
	{
		for (auto i : v)
		{
			std::cout << i << separator;
		}
		std::cout << std::endl;
	}

	void generateRandomVector(std::vector<int>& v, unsigned int n, int lower_bound, int upper_bound)
	{
		// TODO: modernize
		// TODO: check negative range
		v.clear();
		v.resize(n, 0);
		for (auto&& i : v)
		{
			i = rand() % upper_bound + lower_bound;
		}
	}
}