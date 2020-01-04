#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Heap.h"

namespace Algorithms
{

// Max priority Queue
template<typename T>
class PriorityQueue : public Heap<T>
{
public:
	PriorityQueue() { }
	PriorityQueue(std::vector<T>& v)
	{
		setData(v);
	}

	~PriorityQueue() { }
	
	T maximum() { return m_data.front(); }

	T extractMax()
	{
		if (m_heapSize <= 0)
			return T();

		T maxValue = m_data[0];
		m_data[0] = m_data[m_heapSize - 1];
		decreaseHeapSize();
		max_heapify(0);
		
		return maxValue;
	}

	void increaseKey(unsigned int i, T key)
	{
		if (key < m_data[i])
		{
			return;
		}
		m_data[i] = key;
		while (i > 0 && m_data[parent(i)] < m_data[i])
		{
			swap(i, parent(i));
			i = parent(i);
		}
	}

	void insert(T key)
	{
		++m_heapSize;
		if (m_data.size() < m_heapSize) 
		{
			m_data.resize(m_heapSize);
		}
		m_data[m_heapSize-1] = key;
		increaseKey(m_heapSize-1, key);
	}

};

}
#endif