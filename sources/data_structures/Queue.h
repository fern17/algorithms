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
		/*! Constructor. */
		Queue()
		{
			head = nullptr;
			tail = nullptr;
		}

		/*! Destructor. */
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

		/*! Return true if the Queue is empty. */
		bool empty()
		{
			return head == nullptr;
		}

		/*! Push a value to the Queue. */
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

		/*! Pop a value from the Queue. */
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

		/*! Print the data. */
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
		NodeDoubleLinked<T>* head; //!< Pointer to the beginning of the Queue (where the values are pushed).
		NodeDoubleLinked<T>* tail; //!< Pointer to the end of the Quee (from where the values are popped). 
	};
}
#endif