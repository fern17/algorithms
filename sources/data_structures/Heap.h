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
	Heap() { }
	Heap(std::vector<T>& v)
	{
		setData(v);
	}

	~Heap() { }

	void setData(std::vector<T>& v)
	{
		std::copy(v.begin(), v.end(), std::back_inserter(m_data));
		build_max_heap();
	}

	unsigned int getHeapSize() const { return m_heapSize; }

	void decreaseHeapSize() 
	{
		m_heapSize = std::max(m_heapSize - 1, 0);
	}

	void swap(unsigned int i, unsigned int j)
	{
		std::swap(m_data[i], m_data[j]);
	}

	std::vector<int> get()
	{
		return m_data;
	}

	void max_heapify(unsigned int i)
	{
		unsigned int l = left(i);
		unsigned int r = right(i);

		unsigned int largest = 0;
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
	inline unsigned int parent(unsigned int i) { return (i / 2); }
	inline unsigned int left(unsigned int i) { return (2 * i); }
	inline unsigned int right(unsigned int i) { return (2 * i + 1); }

	void build_max_heap()
	{
		m_heapSize = m_data.size();
		int start = m_heapSize / 2;
		for (int i = start; i >= 0; --i)
		{
			max_heapify(i);
		}
	}
	
	std::vector<T> m_data;
	int m_heapSize;
};

}
#endif