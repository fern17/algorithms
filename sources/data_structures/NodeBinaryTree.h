#ifndef NODEBINARYTREE_H
#define NODEBINARYTREE_H

#include <iostream>
#include <string>

namespace Algorithms
{
/**
\brief A class to handle a Node of a Binary Tree. The node contains pointers to the parent, left and right child. All of them could be null.
\see BinaryTree
**/
template<typename TypeKey, typename TypeValue>
class NodeBinaryTree
{
public:
	/*! Constructor */
	NodeBinaryTree() : m_left(nullptr), m_right(nullptr), m_parent(nullptr), m_value(nullptr) {}
	/*! Constructor 
	\param key The key to use for the node.
	\param value The value to use for the node.
	*/
	NodeBinaryTree(TypeKey key, TypeValue value) : m_key(key), m_left(nullptr), m_right(nullptr), m_parent(nullptr) 
	{ 
		m_value = new TypeValue(value); 
	}
	
	/*! Destructor. WARNING!: This destroys this object and all the children. */
	~NodeBinaryTree() 
	{
		if (m_value)
		{
			delete m_value;
		}
		if (m_right)
		{
			delete m_right;
		}
		if (m_left)
		{
			delete m_left;
		}
	}

	/*! Prints the data of the node. */
	void print(std::string separator = " ")
	{
		std::cout << "(" << m_key << ' ' << *m_value << " )" << separator;
	}

	TypeKey m_key;				//!< Key of the node
	TypeValue* m_value;			//!< Value of the node
	NodeBinaryTree* m_left;		//!< Pointer to the left child.
	NodeBinaryTree* m_right;	//!< Pointer to the right child
	NodeBinaryTree* m_parent;	//!< Pointer to the parent
};
}

#endif