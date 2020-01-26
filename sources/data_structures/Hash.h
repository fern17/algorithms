#ifndef HASH_H
#define HASH_H

#include <list>
#include <vector>
#include <iostream>
#include <functional>
#include <utility>

namespace Algorithms
{
/*!
\class Hash
\brief A class to handle a Hash
\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 11.2.
*/
template<typename TypeKey, typename TypeValue>
class Hash
{
public:
	/*!
	Constructor. There are two arguments: the size of the table and the hash function.
	\param size Defines the number of bins to store data. A small number will cause methods to behave in O(n) while a big number would make the storage size bigger but the methods will behave in O(1).
	\param func Sets the hash function. This function has to take an argument of the type of the key, and return an unsigned integer in range [0, size). Internally, values bigger thatn size are clamped to size.
	*/
	Hash(size_t size, std::function<size_t(TypeKey)> func) : m_size(size), m_func(func)
	{
		if (m_size == 0)
		{
			std::cout << "Warning! Size of Hash is zero. Redefined as 1." << std::endl;
			m_size = 1;
		}
		m_values.resize(m_size);
	}

	//! Destructor.
	~Hash() { }

	//! Inserts a pair key value into the hash. This doesn't check if the value already exists.
	void insert(TypeKey key, TypeValue value)
	{
		size_t pos = hash(key);
		m_values[pos].push_back(std::make_pair(key, value));
	}

	//! Search a value given its key. Returns true if success, false otherwise. If success, the value is copied into foundValue.
	bool search(TypeKey key, TypeValue& foundValue)
	{
		size_t pos = hash(key);
		std::list<T>::iterator it = m_values[pos].begin();
		while (it != m_values[pos].end())
		{
			if (*it == value)
			{
				foundValue = it->second;
				return true;
			
			}
			++it;
		}
		return false;
	}

	//!< Removes a value given its from the hash. Returns true if success, false otherwise.
	bool remove(TypeKey key)
	{
		size_t pos = hash(key);
		std::list<std::pair<TypeKey, TypeValue> >::iterator it = m_values[pos].begin();
		while (it != m_values[pos].end())
		{
			if (it->first == key)
			{
				it = m_values[pos].erase(it);
				return true;
			}
			++it;
		}
		
		return false;
	}

	//! Prints the content of the Hash (keys and values).
	void print()
	{
		size_t idx = 0;
		for (auto i : m_values)
		{
			std::cout << "index: " << idx << " { ";
			for (auto j : i)
			{
				std::cout << "(" << j.first << ' ' << j.second  << ") ";
			}
			std::cout << "} " << std::endl;
			++idx;
		}
	}

private:
	//! Computes the hash function for the given key.
	size_t hash(TypeKey& key)
	{
		return std::min(m_size-1, m_func(key));
	}

private:
	size_t m_size;														//!< The size of the vector
	std::vector<std::list<std::pair<TypeKey, TypeValue> > > m_values;	//!< Vector of values
	std::function<size_t(TypeKey)> m_func;								//!< Function used to hash
};
}
#endif