#ifndef SORTING_H
#define SORTING_H
#include <vector>
#include <iostream>
namespace Algorithms
{
	namespace Sorting
	{
		template<typename T>
		void insertion_sort(std::vector<T>& v)
		{
			for (unsigned int j = 1; j < v.size(); ++j)
			{
				T key = v[j];
				int i = j - 1;
				while (i >= 0 && v[i] > key)
				{
					v[i + 1] = v[i];
					--i;
				}
				v[i + 1] = key;
			}
		}


		template<typename T>
		void bubble_sort(std::vector<T>& v)
		{
			size_t sz = v.size();
			for (size_t i = 0; i < sz - 1; ++i)
			{
				for (size_t j = sz - 1; j >= (i + 1); --j)
				{
					if (v[j] < v[j - 1])
					{
						std::swap(v[j], v[j - 1]);
					}
				}
			}
		}

		template<typename T>
		void selection_sort(std::vector<T>& v)
		{
			size_t sz = v.size();
			for (unsigned int i = 0; i < sz - 1; ++i)
			{
				unsigned int min_idx = i;
				for (unsigned int j = i + 1; j < sz; ++j)
				{
					if (v[j] < v[min_idx])
					{
						min_idx = j;
					}
				}
				if (min_idx != i)
				{
					std::swap(v[min_idx], v[i]);
				}
			}
		}

		template<typename T>
		void merge(std::vector<T>& v, int p, int q, int r)
		{
			int n1 = q - p + 1;
			int n2 = r - q;

			int i = 0;
			int j = 0;
			int k = 0;

			std::vector<T> vleft(n1, 0);
			for (i = 0; i < n1; ++i)
			{
				vleft[i] = v[p + i];
			}

			std::vector<T> vright(n2, 0);
			for (j = 0; j < n2; ++j)
			{
				vright[j] = v[q + j + 1];
			}

			i = 0;
			j = 0;
			for (k = p; k <= r; ++k)
			{
				if (i == n1)
				{
					for (; j < n2; ++j)
					{
						v[k++] = vright[j];
					}
				}
				else if (j == n2)
				{
					for (; i < n1; ++i)
					{
						v[k++] = vleft[i];
					}
				}
				else if (vleft[i] <= vright[j])
				{
					v[k] = vleft[i];
					++i;
				}
				else
				{
					v[k] = vright[j];
					++j;
				}
			}
		}

		template<typename T>
		void merge_sort(std::vector<T>& v, int p, int r)
		{
			if (p < r)
			{
				int q = (p + r) / 2;
				merge_sort(v, p, q);
				merge_sort(v, q + 1, r);
				merge(v, p, q, r);
			}
		}

		template<typename T>
		void merge_sort(std::vector<T>& v)
		{
			merge_sort(v, 0, v.size()-1);
		}
	}
}

#endif
