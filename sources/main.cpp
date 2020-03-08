#include <iostream>
#include <vector>

#include "Tools.h"
#include "Sorting.h"
#include "Searching.h"
#include "Heap.h"
#include "PriorityQueue.h"
#include "Stack.h"
#include "Queue.h"
#include "Hash.h"
#include "BinaryTree.h"
#include "RBTree.h"
#include "DynamicProgramming.h"
#include "Matrix.h"

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

	std::cout << "Stack" << std::endl;
	Algorithms::Stack<int> myStack;
	std::cout << "Pushed: 10" << std::endl; myStack.push(10); myStack.print();
	std::cout << "Pushed: 20" << std::endl; myStack.push(20); myStack.print();
	std::cout << "Popped: " << myStack.pop() << std::endl; myStack.print();
	std::cout << "Pushed: 30" << std::endl; myStack.push(30); myStack.print();
	std::cout << "Popped: " << myStack.pop() << std::endl; myStack.print();
	std::cout << "Popped: " << myStack.pop() << std::endl; myStack.print();
	std::cout << "=========================================" << std::endl;

	std::cout << "Queue" << std::endl;
	Algorithms::Queue<int> myQueue;
	std::cout << "Pushed: 10" << std::endl; myQueue.push(10); myQueue.print();
	std::cout << "Pushed: 20" << std::endl; myQueue.push(20); myQueue.print();
	std::cout << "Popped: " << myQueue.pop() << std::endl; myQueue.print();
	std::cout << "Pushed: 30" << std::endl;  myQueue.push(30); myQueue.print();
	std::cout << "Popped: " << myQueue.pop() << std::endl; myQueue.print();
	std::cout << "Popped: " << myQueue.pop() << std::endl; myQueue.print();
	std::cout << "Pushed: 40" << std::endl; myQueue.push(40); myQueue.print();
	std::cout << "=========================================" << std::endl;

	std::cout << "Hash" << std::endl;
	Algorithms::Hash<int, int> myHash(10, ([](int v) { return v % 10; } ));
	std::cout << "Inserted: 10" << std::endl; myHash.insert(10, 1); myHash.print();
	std::cout << "Inserted: 21" << std::endl; myHash.insert(21, 2); myHash.print();
	std::cout << "Inserted: 53" << std::endl; myHash.insert(53, 3); myHash.print();
	std::cout << "Inserted: 45" << std::endl; myHash.insert(45, 4); myHash.print();
	std::cout << "Inserted: 35" << std::endl; myHash.insert(35, 5); myHash.print();
	std::cout << "Removed: 35" << std::endl; myHash.remove(35); myHash.print();
	std::cout << "Removed: 53" << std::endl; myHash.remove(53); myHash.print();
	std::cout << "Removed: 25" << std::endl; myHash.remove(25); myHash.print();
	std::cout << "Trying to remove: 90" << std::endl; myHash.remove(90); myHash.print();

	std::cout << "=========================================" << std::endl;

	std::cout << "Binary Tree" << std::endl;
	Algorithms::BinaryTree<int, int> myBinaryTree;
	std::cout << "Inserted: 10" << std::endl; myBinaryTree.insert(10, 1); myBinaryTree.print();
	std::cout << "Inserted: 20" << std::endl; myBinaryTree.insert(20, 2); myBinaryTree.print();
	std::cout << "Inserted: 30" << std::endl; myBinaryTree.insert(30, 3); myBinaryTree.print();
	std::cout << "Inserted: 5" << std::endl; myBinaryTree.insert(5, 4); myBinaryTree.print();
	Algorithms::NodeBinaryTree<int, int>* binaryTreeMaxNode = myBinaryTree.maximum();
	Algorithms::NodeBinaryTree<int, int>* binaryTreeMinNode = myBinaryTree.minimum();
	std::cout << "Maximum = "; binaryTreeMaxNode->print(); std::cout << std::endl;
	std::cout << "Minimum = "; binaryTreeMinNode->print(); std::cout << std::endl;
	std::cout << "Removed the maximum: " << std::endl;  myBinaryTree.remove(binaryTreeMaxNode); myBinaryTree.print();
	std::cout << "Removed the minimum: " << std::endl;  myBinaryTree.remove(binaryTreeMinNode); myBinaryTree.print();

	std::cout << "RB Tree" << std::endl;
	Algorithms::RBTree<int, int> myRBTree;
	//std::cout << "Inserted: 10" << std::endl; myRBTree.insert(10, 1); myRBTree.print();
	//std::cout << "Inserted: 20" << std::endl; myRBTree.insert(20, 2); myRBTree.print();
	//std::cout << "Inserted: 30" << std::endl; myRBTree.insert(30, 3); myRBTree.print();
	//std::cout << "Inserted:  40" << std::endl; myRBTree.insert(40, 4); myRBTree.print();
	for (int i = 1; i < 10; ++i)
	{
		std::cout << "Inserted: " << i << std::endl; 
		myRBTree.insert(i, i*10); 
		myRBTree.print();
	}
	std::cout << "Maximum: "; myRBTree.maximum()->print(); std::cout << std::endl;
	std::cout << "Minimum: "; myRBTree.minimum()->print(); std::cout << std::endl;
	
	std::cout << "Deleting the Maximum: " << std::endl; myRBTree.remove(myRBTree.maximum()); myRBTree.print(); std::cout << std::endl;
	std::cout << "Maximum: "; myRBTree.maximum()->print(); std::cout << std::endl;
	std::cout << "Minimum: "; myRBTree.minimum()->print(); std::cout << std::endl;
	
	std::cout << "Deleting the Maximum: " << std::endl; myRBTree.remove(myRBTree.maximum()); myRBTree.print(); std::cout << std::endl;
	std::cout << "Maximum: "; myRBTree.maximum()->print(); std::cout << std::endl;
	std::cout << "Minimum: "; myRBTree.minimum()->print(); std::cout << std::endl;

	std::cout << "Deleting the Minimum: " << std::endl; myRBTree.remove(myRBTree.minimum()); myRBTree.print(); std::cout << std::endl;
	std::cout << "Maximum: "; myRBTree.maximum()->print(); std::cout << std::endl;
	std::cout << "Minimum: "; myRBTree.minimum()->print(); std::cout << std::endl;
	
	std::cout << "Deleting the Minimum: " << std::endl; myRBTree.remove(myRBTree.minimum()); myRBTree.print(); std::cout << std::endl;
	std::cout << "Maximum: "; myRBTree.maximum()->print(); std::cout << std::endl;
	std::cout << "Minimum: "; myRBTree.minimum()->print(); std::cout << std::endl;
}

void testTechniques()
{
	std::cout << "Testing Algorithms Techniques:" << std::endl;
	std::vector<int> v{ 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int n = 4 ;
	std::vector<int> s;

	std::cout << "=======================" << std::endl;
	std::cout << "Cutting Rod Problem: " << std::endl;
	std::cout << "Initial Vector: " << std::endl;
	Tools::print(v);
	std::cout << "N = " << n << std::endl;
	std::cout << "Cutting Rod Memoized Solution: " << Algorithms::cut_rod_memoized(v, n) << std::endl;
	
	std::cout << "Cutting Rod Bottom Up Solution: " << Algorithms::cut_rod_bottom_up(v, n, s) << std::endl;
	std::cout << "Cut Solution: ";
	int nn = n;
	while (nn > 0)
	{
		std::cout << s[nn] << ' ';
		nn = nn - s[nn];
	}
	std::cout << std::endl;

	std::cout << "=======================" << std::endl;
	std::cout << "Matrix Multiplication: " << std::endl;
	std::vector<std::vector<double> > A;
	std::vector<std::vector<double> > B;
	std::vector<std::vector<double> > C;
	Tools::generateRandomMatrix(A, 4, 4, 0.0, 100.0);
	Tools::generateRandomMatrix(B, 4, 4, 0.0, 100.0);
	Algorithms::matrix_multiply(A, B, C);
	std::cout << "A:\n";
	Tools::print_matrix(A);
	std::cout << "B:\n";
	Tools::print_matrix(B);
	std::cout << "C = A*B:\n";
	Tools::print_matrix(C);
	std::cout << "=======================" << std::endl;

	std::cout << "Matrix Chaining Problem: " << std::endl;
	std::vector<int> P = { 30, 35, 15, 5, 10, 20, 25 };
	std::cout << "Matrix Sizes: " << std::endl;
	for (int i = 1; i < P.size(); ++i)
	{
		std::cout << "A_" << i << " = " << P[i-1] << "x" << P[i] << std::endl;
	}
	std::vector<std::vector<int> > S;
	size_t numberOperations = Algorithms::matrix_chain_order(P, S);
	std::cout << "Minimum number of operations = " << numberOperations << std::endl;
	Algorithms::print_optimal_parents(S);

	std::cout << "=======================" << std::endl;

	std::cout << "Longest Common Subsequence: " << std::endl;
	//std::string X = "ABCBDAB";
	//std::string Y = "BDCABA";
	std::string X = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
	std::string Y = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
	Algorithms::longest_common_subsequence(X, Y);

	std::cout << "=======================" << std::endl;
}

int main(int argc, char** argv)
{
	//testSorting(10);
	//testSearching();
	//testDataStructures();
	testTechniques();
	
	return 0;
}

