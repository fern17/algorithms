#ifndef STACK_H
#define STACK_H

#include "NodeSingleLinked.h"

namespace Algorithms
{

/**
\brief A class to handle a Stack
\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 10.1.
**/
template<typename T>
class Stack
{
public:
	Stack()
	{
		head = nullptr;
	}
	~Stack()
	{
		NodeSingleLinked<T>* ptr = head;
		while (ptr)
		{
			NodeSingleLinked<T>* ptr2 = ptr;
			ptr = ptr->next;

			delete ptr2;
		}
	}

	bool empty()
	{
		return head == nullptr;
	}

	void push(T v)
	{
		NodeSingleLinked<T>* node = new NodeSingleLinked<T>(v);
		node->next = head;
		head = node;
	}

	T pop()
	{
		if (empty())
		{
			return T();
		}
		else
		{
			NodeSingleLinked<T>* headNode = head;
			head = headNode->next;
			
			T retval = headNode->value; //TODO warning this is a copy and we do another copy when exiting...
			
			delete headNode;

			return retval;
		}
	}

	void print(std::string separator = " ")
	{
		NodeSingleLinked<T>* ptr = head;
		while (ptr)
		{
			ptr->print(separator);
			ptr = ptr->next;
		}
		std::cout << std::endl;
	}

public:
	NodeSingleLinked<T>* head;
};
}
#endif