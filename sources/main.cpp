#include <iostream>
#include <vector>

#include "Tools.h"
#include "Sorting.h"
#include "Searching.h"
#include "Heap.h"
#include "PriorityQueue.h"

void testSorting(int vectorLength)
{
	std::cout << "Testing Sorting Algorithms" << std::endl;

	std::vector<int> v;
	std::vector<double> vd;
	Tools::generateRandomVector(v, vectorLength, 1, 100);
	Tools::generateRandomVector(vd, vectorLength, 0.0, 1.0);

	std::cout << "Input Vector" << std::endl;
	Tools::print(v);
	std::cout << "Sorted = " << Tools::is_sorted(v) << std::endl;
	std::cout << "=========================================" << std::endl;

	std::cout << "Input Vector Double" << std::endl;
	Tools::print(vd);
	std::cout << "Sorted = " << Tools::is_sorted(vd) << std::endl;
	std::cout << "=========================================" << std::endl;

	std::vector<int> v1(v);
	std::vector<int> v2(v);
	std::vector<int> v3(v);
	std::vector<int> v4(v);
	std::vector<int> v5(v);
	std::vector<int> v6(v);
	std::vector<int> v7(v);
	std::vector<int> v8(v);
	std::vector<int> v9(v);
	std::vector<int> v10(v);
	std::vector<double> v11(vd);


	std::cout << "Insertion Sort" << std::endl;
	Algorithms::Sorting::insertion_sort(v1);
	Tools::print(v1);
	std::cout << "Sorted = " << Tools::is_sorted(v1) << std::endl;
	std::cout << "=========================================" << std::endl;

	std::cout << "Bubble Sort" << std::endl;
	Algorithms::Sorting::bubble_sort(v2);
	Tools::print(v2);
	std::cout << "Sorted = " << Tools::is_sorted(v2) << std::endl;
	std::cout << "=========================================" << std::endl;

	std::cout << "Selection Sort" << std::endl;
	Algorithms::Sorting::selection_sort(v3);
	Tools::print(v3);
	std::cout << "Sorted = " << Tools::is_sorted(v3) << std::endl;
	std::cout << "=========================================" << std::endl;

	std::cout << "Merge Sort" << std::endl;
	Algorithms::Sorting::merge_sort(v4);
	Tools::print(v4);
	std::cout << "Sorted = " << Tools::is_sorted(v4) << std::endl;
	std::cout << "=========================================" << std::endl;

	std::cout << "Heap Sort" << std::endl;
	Algorithms::Sorting::heap_sort(v5);
	Tools::print(v5);
	std::cout << "Sorted = " << Tools::is_sorted(v5) << std::endl;
	std::cout << "=========================================" << std::endl;

	std::cout << "Quick Sort" << std::endl;
	std::cout << "== Simple Partition ==" << std::endl;
	Algorithms::Sorting::quick_sort(v6, Algorithms::Sorting::QUICKSORT_METHOD_SIMPLE_PARTITION);
	Tools::print(v6);
	std::cout << "Sorted = " << Tools::is_sorted(v6) << std::endl;
	std::cout << "== Randomized Partition ==" << std::endl;
	Algorithms::Sorting::quick_sort(v7, Algorithms::Sorting::QUICKSORT_METHOD_RANDOMIZED_PARTITION);
	Tools::print(v7);
	std::cout << "Sorted = " << Tools::is_sorted(v7) << std::endl;
	std::cout << "== Hoare Partition ==" << std::endl;
	Algorithms::Sorting::quick_sort(v8, Algorithms::Sorting::QUICKSORT_METHOD_HOARE_PARTITION);
	Tools::print(v8);
	std::cout << "Sorted = " << Tools::is_sorted(v8) << std::endl;
	std::cout << "=========================================" << std::endl;

	std::cout << "Counting Sort" << std::endl;
	Algorithms::Sorting::counting_sort(v9);
	Tools::print(v9);
	std::cout << "Sorted = " << Tools::is_sorted(v9) << std::endl;
	std::cout << "=========================================" << std::endl;

	std::cout << "Radix Sort" << std::endl;
	Algorithms::Sorting::radix_sort(v10);
	Tools::print(v10);
	std::cout << "Sorted = " << Tools::is_sorted(v10) << std::endl;
	std::cout << "=========================================" << std::endl;

	std::cout << "Bucket Sort" << std::endl;
	Algorithms::Sorting::bucket_sort(v11);
	Tools::print(v11);
	std::cout << "Sorted = " << Tools::is_sorted(v11) << std::endl;
	std::cout << "=========================================" << std::endl;

}

void testSearching()
{
	std::cout << "Testing Search Algorithms " << std::endl;

	std::vector<int> v = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };

	std::cout << "Input Vector" << std::endl;
	Tools::print(v);
	std::cout << "=========================================" << std::endl;

	std::vector<int> v1(v);
	std::cout << "Maximum subarray" << std::endl;
	int r1sum = 0;
	std::vector<int> r1 = Algorithms::Searching::find_maximum_subarray(v1, r1sum);
	Tools::print(r1);
	std::cout << "Sum = " << r1sum << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << "=========================================" << std::endl;
}

void testDataStructures()
{
	std::cout << "Testing Data Structures" << std::endl;

	std::vector<int> v{ 16, 14, 10, 8, 2, 4, 7, 1 , 9, 3 };

	std::cout << "Input Vector" << std::endl;
	Tools::print(v);
	std::cout << "=========================================" << std::endl;
	std::vector<int> v1(v);
	std::vector<int> v2(v);

	std::cout << "Heap" << std::endl;
	Algorithms::Heap<int> h(v1);
	Tools::print(h.get());
	std::cout << "=========================================" << std::endl;

	std::cout << "Priority Queue" << std::endl;
	Algorithms::PriorityQueue<int> pq(v2);
	Tools::print(pq.get());
	pq.insert(20);
	pq.insert(50);
	Tools::print(pq.get());
	std::cout << "Max All = " << pq.maximum() << std::endl;
	std::cout << "Emptying Priority Queue" << std::endl;
	while (pq.getHeapSize() > 0)
	{
		std::cout << "Max = " << pq.extractMax() << std::endl;
	}
	std::cout << "=========================================" << std::endl;
}

int main(int argc, char** argv)
{
	testSorting(10);
	//testSearching();
	//testDataStructures();
	
	return 0;
}
