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

	/*! 
	Function to solve the cutting rod problem using a memoized approach. 
	\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 15.1
	*/
	int cut_rod_memoized(std::vector<int>& p, int n)
	{
		std::vector<int> r(n+1, INT_MIN);
		return cut_rod_memoized_aux(p, n, r);
	}
	
	/*! 
	Function to solve the cutting rod problem using a top down approach. 
	\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 15.1
	*/
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

	/*! 
	Solve the matrix chaining product problem. 
	\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 15.2
	*/
	size_t matrix_chain_order(std::vector<int>& P, std::vector<std::vector<int> >& S)
	{
		if (P.empty()) return 0;
		
		size_t n = P.size();
		std::vector<std::vector<int> > M;
		
		M.resize(n);
		
		for (int i = 0; i < M.size(); ++i)
		{
			M[i].resize(n, 0);
		}
		
		S.clear();
		S.resize(n - 1);
		for (int i = 0; i < S.size(); ++i)
		{
			S[i].resize(n, 0);
		}

		for (int l = 2; l < n; ++l)
		{
			size_t limitI = n - l + 1;
			for (int i = 1; i < limitI; ++i)
			{
				int j = i + l - 1;
				M[i][j] = INT_MAX;
				
				int limitK = j - 1;
				for (int k = i; k <= limitK; ++k)
				{
					int q = M[i][k] + M[k + 1][j] + P[i - 1] * P[k] * P[j];
					if (q < M[i][j])
					{
						M[i][j] = q;
						S[i][j] = k;
					}
				}
			}
		}
		return M[1][n - 1];
	}

	/*! Helper to print the solution of the optimal parenthesis problem. */
	void print_optimal_parents(std::vector<std::vector<int> >& S, size_t i, size_t j)
	{
		if (i == j)
		{
			std::cout << "A_" << i;
		}
		else
		{
			std::cout << "(";
			print_optimal_parents(S, i, S[i][j]);
			std::cout << " ";
			print_optimal_parents(S, S[i][j]+1, j);
			std::cout << ")";
		}
	}

	/*! Print the solution of the optimal parenthesis problem. */
	void print_optimal_parents(std::vector<std::vector<int> >& S)
	{
		print_optimal_parents(S, 1, S.size());
		std::cout << std::endl;
	}

}

#endif