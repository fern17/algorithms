#ifndef HEAP_H
#define HEAP_H

#include <vector>

/**
\brief General namespace that includes everything.
**/
namespace Algorithms
{

/**
\brief A class to handle a Heap
\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 6.
**/
template<typename T>
class Heap
{
public:
	/*! Constructor. */
	Heap() { m_heapSize = 0; }
	
	/*! Constructor that sets the data from a vector. */
	Heap(std::vector<T>& v)
	{
		setData(v);
	}

	/*! Destructor. */
	~Heap() { }

	/*! Sets the data to the Hash from a vector. */
	void setData(std::vector<T>& v)
	{
		std::copy(v.begin(), v.end(), std::back_inserter(m_data));
		build_max_heap();
	}

	/*! Return the size of the heap (how many elements there are). */
	unsigned int getHeapSize() const { return m_heapSize; }

	/*! Decrease the size of the heap (minimum 0). */
	void decreaseHeapSize() 
	{
		m_heapSize = std::max(m_heapSize - 1, 0);
	}

	/*! Swap two values of the heap given their indices. */
	void swap(unsigned int i, unsigned int j)
	{
		std::swap(m_data[i], m_data[j]);
	}

	/*! Return the data in this heap. */
	std::vector<int> get()
	{
		return m_data;
	}

	/*! Transform the data into a max heap from the index i. */
	void max_heapify(unsigned int i)
	{
		int l = left(i);
		int r = right(i);

		int largest = 0;
		if (l < m_heapSize && m_data[l] > m_data[i])
		{
			largest = l;
		}
		else
		{
			largest = i;
		}

		if (r < m_heapSize && m_data[r] > m_data[largest])
		{
			largest = r;
		}

		if (largest != i)
		{
			swap(i, largest);
			max_heapify(largest);
		}
	}

protected:
	/*! Obtain the parent of node i. */
	inline int parent(int i) { return (i / 2); }
	/*! Obtain the left child of node i. */
	inline int left(int i) { return (2 * i); }
	/*! Obtain the right child of node i. */
	inline int right(int i) { return (2 * i + 1); }

	/*! Build the max heap.*/
	void build_max_heap()
	{
		m_heapSize = static_cast<int> (m_data.size());
		int start = m_heapSize / 2;
		for (int i = start; i >= 0; --i)
		{
			max_heapify(i);
		}
	}
	
	std::vector<T> m_data;	//!< The data contained in the Heap.
	int m_heapSize;			//!< Maximum available size for the Heap.
};

}
#endif