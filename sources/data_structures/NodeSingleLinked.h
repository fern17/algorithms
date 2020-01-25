#ifndef NODESINGLELINKED_H
#define NODESINGLELINKED_H

#include <iostream>
#include <string>

/**
\brief A class to handle a Node Single Linked (i.e.: it contains a link to the next node only).
\see Stack
**/
template<typename T>
class NodeSingleLinked
{
public:
	NodeSingleLinked(T v) : value(v) {}
	NodeSingleLinked() {}
	~NodeSingleLinked() {}

	void print(std::string separator = " ")
	{
		std::cout << value << separator;
	}

	T value;
	NodeSingleLinked* next;
};

#endif