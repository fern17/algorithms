#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
namespace Algorithms
{
	void matrix_multiply(std::vector<std::vector<double> >& A, std::vector<std::vector<double> >& B, std::vector<std::vector<double> >& C)
	{
		size_t a_rows = A.size();
		size_t b_rows = B.size();
		if (a_rows == 0 || b_rows == 0)
		{
			std::cout << "Matrix sizes do not match for multiplication!" << std::endl;
			std::cout << "A rows: " << a_rows << std::endl;
			std::cout << "B rows: " << b_rows << std::endl;
			return;
		}
		
		size_t a_cols = A[0].size();
		size_t b_cols = B[0].size();
		if (a_cols != b_rows)
		{
			std::cout << "Matrix sizes do not match for multiplication!" << std::endl;
			std::cout << "A rows: " << a_rows << std::endl;
			std::cout << "A cols: " << a_cols << std::endl;
			std::cout << "B rows: " << b_rows << std::endl;
			std::cout << "B cols: " << b_cols << std::endl;
			return;
		}
		C.clear();
		C.resize(a_rows);
		for (int i = 0; i < a_rows; ++i)
		{
			C[i].resize(a_cols, 0.0);
		}
		for (int i = 0; i < a_rows; ++i)
		{
			for (int j = 0; j < b_cols; ++j)
			{
				for (int k = 0; k < a_cols; ++k)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
	}
}
#endif