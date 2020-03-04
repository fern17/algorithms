#ifndef DYNAMICPROGRAMMING_H
#define DYNAMICPROGRAMMING_h

#include <vector>
#include <algorithm>

namespace Algorithms
{
	/*! Auxiliary function to solve the cutting rod problem using a memoized approach. */
	int cut_rod_memoized_aux(std::vector<int>& p, int n, std::vector<int>& r)
	{
		if (r[n] >= 0)
		{
			return r[n];
		}
		int q;
		if (n == 0)
		{
			q = 0;
		}
		else
		{
			q = INT_MIN;
			for (int i = 1; i <= n; ++i)
			{
				q = std::max(q, p[i-1] + cut_rod_memoized_aux(p, n - i, r));
			}
		}
		r[n] = q;
		return q;
	}

	/*! Function to solve the cutting rod problem using a memoized approach. */
	int cut_rod_memoized(std::vector<int>& p, int n)
	{
		std::vector<int> r(n+1, INT_MIN);
		return cut_rod_memoized_aux(p, n, r);
	}
	
	/*! Auxiliary function to solve the cutting rod problem using a top down approach. */
	int cut_rod_bottom_up(std::vector<int>& p, int n, std::vector<int>& s)
	{
		std::vector<int> r(n+1);
		s.resize(n+1);
		r[0] = 0;
		for (int j = 1; j <= n; ++j)
		{
			int q = INT_MIN;
			for (int i = 1; i <= j; ++i)
			{
				int v = p[i-1] + r[j - i];
				if (q < v)
				{
					q = v;
					s[j] = i;
				}
			}
			r[j] = q;
		}
		return r[n];
	}

}

#endif