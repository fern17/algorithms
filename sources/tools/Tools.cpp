#include "Tools.h"
#include <iostream>
#include <random>
namespace Tools
{
	void generateRandomVector(std::vector<int>& v, unsigned int n, int lower_bound, int upper_bound)
	{
		// TODO: check negative range
		v.clear();
		v.resize(n, 0);
		for (auto&& i : v)
		{
			i = random(lower_bound, upper_bound);
		}
	}

	int random(int lower_bound, int upper_bound)
	{
		static std::random_device rd;
		static std::default_random_engine re(rd());
		std::uniform_int_distribution<int> dist(lower_bound, upper_bound);
		return dist(re);
	}
}