#include <iostream>
#include <vector>

#include "Tools.h"
#include "Sorting.h"


int main(int argc, char** argv)
{
	std::vector<int> v;
	Tools::generateRandomVector(v, 20, 1, 100);
	std::cout << "Input Vector" << std::endl;
	Tools::printVector(v);
	std::cout << "=========================================" << std::endl;

	std::vector<int> v1(v);
	std::vector<int> v2(v);
	std::vector<int> v3(v);
	std::vector<int> v4(v);
	
	
	std::cout << "Insertion Sort" << std::endl;
	Algorithms::Sorting::insertion_sort(v1);
	Tools::printVector(v1);
	std::cout << "=========================================" << std::endl;
	
	std::cout << "Bubble Sort" << std::endl;
	Algorithms::Sorting::bubble_sort(v2);
	Tools::printVector(v2);
	std::cout << "=========================================" << std::endl;

	std::cout << "Selection Sort" << std::endl;
	Algorithms::Sorting::selection_sort(v3);
	Tools::printVector(v3);
	std::cout << "=========================================" << std::endl;

	std::cout << "Merge Sort" << std::endl;
	Algorithms::Sorting::merge_sort(v4);
	Tools::printVector(v4);
	std::cout << "=========================================" << std::endl;

	return 0;
}
