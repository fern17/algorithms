#ifndef TOOLS_H
#define TOOLS_H

#include <string>
#include <vector>

namespace Tools
{
	void printVector(std::vector<int>& v, std::string separator = " ");

	void generateRandomVector(std::vector<int>& v, unsigned int n, int lower_bound, int upper_bound);
};

#endif