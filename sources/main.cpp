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
	Tools::generateRandomVector(v, vectorLength, 1, 100);

	std::cout << "Input Vector" << std::endl;
	Tools::print(v);
	std::cout << "=========================================" << std::endl;

	std::vector<int> v1(v);
	std::vector<int> v2(v);
	std::vector<int> v3(v);
	std::vector<int> v4(v);
	std::vector<int> v5(v);


	std::cout << "Insertion Sort" << std::endl;
	Algorithms::Sorting::insertion_sort(v1);
	Tools::print(v1);
	std::cout << "=========================================" << std::endl;

	std::cout << "Bubble Sort" << std::endl;
	Algorithms::Sorting::bubble_sort(v2);
	Tools::print(v2);
	std::cout << "=========================================" << std::endl;

	std::cout << "Selection Sort" << std::endl;
	Algorithms::Sorting::selection_sort(v3);
	Tools::print(v3);
	std::cout << "=========================================" << std::endl;

	std::cout << "Merge Sort" << std::endl;
	Algorithms::Sorting::merge_sort(v4);
	Tools::print(v4);
	std::cout << "=========================================" << std::endl;

	std::cout << "Heap Sort" << std::endl;
	Algorithms::Sorting::heap_sort(v5);
	Tools::print(v5);
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
	testSearching();
	testDataStructures();
	
	return 0;
}
