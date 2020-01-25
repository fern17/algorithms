#ifndef QUEUE_H
#define QUEUE_H

#include "NodeDoubleLinked.h"

namespace Algorithms
{

	/**
	\brief A class to handle a Queue
	\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 10.1.
	**/
	template<typename T>
	class Queue
	{
	public:
		Queue()
		{
			head = nullptr;
			tail = nullptr;
		}
		~Queue()
		{
			NodeDoubleLinked<T>* ptr = head;
			NodeDoubleLinked<T>* ptr2;
			while (ptr)
			{
				ptr2 = ptr;
				ptr = ptr->next;
				delete ptr2;
			}
			head = tail = nullptr;
		}

		bool empty()
		{
			return head == nullptr;
		}

		void push(T v)
		{
			NodeDoubleLinked<T>* node = new NodeDoubleLinked<T>(v);
			if (head)
			{
				head->prev = node;
				node->next = head;
			}
			else
			{
				tail = node;
			}
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
				NodeDoubleLinked<T>* tailNode = tail;
				tail = tail->prev;
				if (tail)
				{
					tail->next = nullptr;
				}

				if (!tail)
				{
					head = tail = nullptr;
				}

				T retval = tailNode->value; //TODO warning this is a copy and we do another copy when exiting...

				delete tailNode;

				return retval;
			}
		}

		void print(std::string separator = " ")
		{
			NodeDoubleLinked<T>* ptr = head;
			while (ptr)
			{
				ptr->print(separator);
				ptr = ptr->next;
			}
			std::cout << std::endl;
		}

	public:
		NodeDoubleLinked<T>* head;
		NodeDoubleLinked<T>* tail;
	};
}
#endif