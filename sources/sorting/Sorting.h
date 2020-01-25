#ifndef SORTING_H
#define SORTING_H

#include "Heap.h"

#include <vector>
#include <iostream>

namespace Algorithms
{
	/**
	\brief A namespace that stores all the Sorting algorithms.
	**/
	namespace Sorting
	{

		/**
		\brief An enum to define the partition method used in QuickSort. 
		\see \ref quick_sort
		**/
		enum QuickSortMethod
		{
			QUICKSORT_METHOD_SIMPLE_PARTITION = 0,		//!< Configures Quicksort to use the Simple Partition Method.
			QUICKSORT_METHOD_RANDOMIZED_PARTITION = 1,	//!< Configures Quicksort to use the Randomized Partition Method.
			QUICKSORT_METHOD_HOARE_PARTITION = 2		//!< Configures Quicksort to use the Hoare Partition Method.
		};

		/**
		\brief A function that sorts a vector using Insertion Sort.
		\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 2.1.
		**/
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

		/**
		\brief A function that sorts a vector using Bubble Sort.
		\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 2. Problem 2.2.
		**/
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

		/**
		\brief A function that sorts a vector using Selection Sort.
		\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 2. Problem 2.2.
		**/
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

		/**
		\brief Helper function for \ref merge_sort
		This functions does the merge of two ranges [p, q] and [q,r] defined in v.
		**/
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

		/**
		\brief Helper function for \ref merge_sort
		This function takes a lower and upper bound and divides the vector in half, calling recursively \ref merge_sort on each half and then calling \ref merge.
		**/
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

		/**
		\brief A function that sorts a vector using Merge Sort.
		\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 2.3.
		**/
		template<typename T>
		void merge_sort(std::vector<T>& v)
		{
			int n = static_cast<int>(v.size() - 1);
			merge_sort(v, 0, n);
		}

		/**
		\brief A function that sorts a vector using Heap Sort.
		\see Heap
		\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 6.4.
		**/
		template<typename T>
		void heap_sort(std::vector<T>& v)
		{
			Heap<T> h(v);
			int n = static_cast<int> (v.size() - 1);
			for (int i = n; i >= 1; --i)
			{
				h.swap(0, i);
				h.decreaseHeapSize();
				h.max_heapify(0);
			}
			v = h.get();
		}

		/**
		\brief Helper function for \ref quick_sort that sorts a vector v in the range [p,r] using a simple method for partitioning.
		The pivot used for the partionning is the last element of the array.
		\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 7.3.
		**/
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

		/**
		\brief Helper function for \ref quick_sort that sorts a vector v in the range [p,r] using the Randomized method for partitioning.
		The pivot used for the partionning is a random element of the array.
		\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 7.3.
		**/
		template<typename T>
		int quick_sort_randomized_partition(std::vector<T>& v, int p, int r)
		{
			int i = Tools::random(p, r);
			std::swap(v[i], v[r]);
			return quick_sort_simple_partition(v, p, r);
		}

		/**
		\brief Helper function for \ref quick_sort that sorts a vector v in the range [p,r] using the Hoare method for partitioning.
		\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 7. Problem 7.1
		**/
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

		/**
		\brief Helper function for \ref quick_sort that sorts a vector v in the range [p,r] using the defined method.
		\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 7.
		**/
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

		/**
		\brief A function that sorts a vector using Quick Sort.
		The second parameter can be used to choose which method to use for the partitioning.
		\see QuickSortMethod
		\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 7.
		**/
		template<typename T>
		void quick_sort(std::vector<T>& v, int method = QUICKSORT_METHOD_SIMPLE_PARTITION)
		{
			int n = static_cast<int> (v.size() - 1);
			quick_sort(v, 0, n, method);
		}

		/**
		\brief A function that sorts a vector using Counting Sort.
		This method is only valid for integer data.
		\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 8.2.
		**/
		void counting_sort(std::vector<int>& v)
		{
			int n = static_cast<int> (v.size());
			int k = *(std::max_element(v.begin(), v.end()))+1;
			std::vector<int> b(n, 0);
			std::vector<int> c(k, 0);
			for (int j = 0; j < n; ++j)
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

		/**
		\brief A function that sorts a vector using Radix Sort.
		This method is only valid for integer data.
		\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 8.3.
		**/
		void radix_sort(std::vector<int>& v)
		{
			size_t n = v.size();
			int maxe = *std::max_element(v.begin(), v.end());
			for (int expe = 1; maxe / expe > 0; expe *= 10)
			{
				counting_sort(v);
			}
		}

		/**
		\brief A function that sorts a vector using Bucket Sort.
		This method is only valid for double data in range [0, 1]
		\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 8.4.
		**/
		void bucket_sort(std::vector<double>& v)
		{
			size_t n = v.size();
			std::vector<std::vector<double> > b(n);
			
			for (size_t i = 0; i < n; ++i)
			{
				b[(int) std::floor(n * v[i])].push_back(v[i]);
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
