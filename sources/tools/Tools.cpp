#include "Tools.h"
#include <iostream>
#include <random>

/**
	\brief A namespace to group all utilities that are used from other classes.
**/
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
	

	void generateRandomVector(std::vector<double> & v, unsigned int n, double lower_bound, double upper_bound)
	{
		// TODO: check negative range
		v.clear();
		v.resize(n, 0);
		for (auto&& i : v)
		{
			i = random(lower_bound, upper_bound);
		}
	}

	void generateRandomMatrix(std::vector<std::vector<double> >& A, unsigned int n, unsigned int m, double lower_bound, double upper_bound)
	{
		A.clear();
		A.resize(n);
		for (int i = 0; i < n; ++i)
		{
			A[i].resize(m, 0.0);
			for (int j = 0; j < m; ++j)
			{
				A[i][j] = Tools::random(lower_bound, upper_bound);
			}
		}
	}

	void print_matrix(std::vector<std::vector<double> >& A, std::string separator)
	{
		size_t n = A.size();
		for (int i = 0; i < n; ++i)
		{
			size_t m = A[i].size();
			for (int j = 0; j < m; ++j)
			{
				std::cout << A[i][j] << separator;
			}
			std::cout << std::endl;
		}
	}

	int random(int lower_bound, int upper_bound)
	{
		static std::random_device rd;
		static std::default_random_engine re(rd());
		std::uniform_int_distribution<int> dist(lower_bound, upper_bound);
		return dist(re);
	}

	double random(double lower_bound, double upper_bound)
	{
		static std::random_device rd;
		static std::default_random_engine re(rd());
		std::uniform_real_distribution<double> dist(lower_bound, upper_bound);
		return dist(re);
	}
}