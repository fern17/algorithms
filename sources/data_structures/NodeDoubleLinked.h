#ifndef NODEDOUBLELINKED_H
#define NODEDOUBLELINKED_H

#include <iostream>
#include <string>

/**
\brief A class to handle a Node Double Linked (i.e.: it contains a link to the next node and to the previous one).
\see Queue
**/
template<typename T>
class NodeDoubleLinked
{
public:
	NodeDoubleLinked(T v) : value(v) { next = nullptr; prev = nullptr; }
	NodeDoubleLinked() { next = nullptr; prev = nullptr; }
	~NodeDoubleLinked()
	{
	}

	void print(std::string separator = " ")
	{
		std::cout << value << separator;
	}

	T value;
	NodeDoubleLinked* next;
	NodeDoubleLinked* prev;
};

#endif