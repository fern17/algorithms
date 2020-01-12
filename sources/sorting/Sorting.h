#ifndef SORTING_H
#define SORTING_H

#include "Heap.h"

#include <vector>
#include <iostream>



namespace Algorithms
{
	namespace Sorting
	{

		enum
		{
			QUICKSORT_METHOD_SIMPLE_PARTITION = 0,
			QUICKSORT_METHOD_RANDOMIZED_PARTITION = 1,
			QUICKSORT_METHOD_HOARE_PARTITION = 2
		};

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

		template<typename T>
		void heap_sort(std::vector<T>& v)
		{
			Heap<T> h(v);
			for (unsigned int i = v.size()-1; i >= 1; --i)
			{
				h.swap(0, i);
				h.decreaseHeapSize();
				h.max_heapify(0);
			}
			v = h.get();
		}

		template<typename T>
		int quick_sort_simple_partition(std::vector<T>& v, int p, int r)
		{
			T x = v[r];
			int i = p - 1;
			for (int j = p; j < r; ++j)
			{
				if (v[j] <= x)
				{
					++i;
					std::swap(v[i], v[j]);
				}
			}
			std::swap(v[i + 1], v[r]);
			return (i + 1);
		}

		template<typename T>
		int quick_sort_randomized_partition(std::vector<T>& v, int p, int r)
		{
			int i = Tools::random(p, r);
			std::swap(v[i], v[r]);
			return quick_sort_simple_partition(v, p, r);
		}

		template<typename T>
		int quick_sort_hoare_partition(std::vector<T>& v, int p, int r)
		{
			T x = v[p];
			int i = p - 1;
			int j = r + 1;
			//size_t sz = v.size();
			while (true)
			{
				do
				{
					--j;
				} while (v[j] > x);

				do
				{
					++i;
				} while (v[i] < x);

				if (i < j)
				{
					std::swap(v[i], v[j]);
				}
				else
				{
					return j;
				}
			}
		}

		template<typename T>
		void quick_sort(std::vector<T>& v, int p, int r, int method)
		{
			if (p < r)
			{
				int q;
				switch(method)
				{ 
					case QUICKSORT_METHOD_SIMPLE_PARTITION:
					{
						q = quick_sort_simple_partition(v, p, r);
						break;
					}
					case QUICKSORT_METHOD_RANDOMIZED_PARTITION:
					{
						q = quick_sort_randomized_partition(v, p, r);
						break;
					}
					case QUICKSORT_METHOD_HOARE_PARTITION:
					{
						q = quick_sort_hoare_partition(v, p, r);
						break;
					}
					default:
					{
						q = quick_sort_simple_partition(v, p, r);
						break;
					}
				}
				if (method == QUICKSORT_METHOD_HOARE_PARTITION)
				{
					quick_sort(v, p, q, method); // index q is not in the correct place
					quick_sort(v, q + 1, r, method);
				}
				else
				{
					quick_sort(v, p, q - 1, method); // q is in the correct place, no need to use it in recursion
					quick_sort(v, q + 1, r, method);
				}
				
			}
		}

		template<typename T>
		void quick_sort(std::vector<T>& v, int method = QUICKSORT_METHOD_SIMPLE_PARTITION)
		{
			quick_sort(v, 0, v.size() - 1, method);
		}

		void counting_sort(std::vector<int>& v)
		{
			size_t n = v.size();
			int k = *(std::max_element(v.begin(), v.end()))+1;
			std::vector<int> b(n, 0);
			std::vector<int> c(k, 0);
			for (size_t j = 0; j < n; ++j)
			{
				++c[v[j]];
			}
			for (int i = 1; i < k; ++i)
			{
				c[i] += c[i - 1];
			}
			for (int j = n-1; j >= 0; --j)
			{
				b[c[v[j]]-1] = v[j];
				--c[v[j]];
			}
			v = b;
		}

		void radix_sort(std::vector<int>& v)
		{
			size_t n = v.size();
			int maxe = *std::max_element(v.begin(), v.end());
			for (int expe = 1; maxe / expe > 0; expe *= 10)
			{
				counting_sort(v);
			}
		}

		void bucket_sort(std::vector<double>& v)
		{
			size_t n = v.size();
			std::vector<std::vector<double> > b(n);
			
			for (size_t i = 0; i < n; ++i)
			{
				b[std::floor(n * v[i])].push_back(v[i]);
			}
			for (size_t i = 0; i < n; ++i)
			{
				insertion_sort(b[i]);
			}
			v.clear();
			v.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				std::vector<double>& bb = b[i];
				for (size_t j = 0; j < bb.size(); ++j)
				{
					v.push_back(bb[j]);
				}
			}
		}
	}
}

#endif
