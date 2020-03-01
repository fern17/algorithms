#ifndef NODERBTREE_H
#define NODERBTREE_H

#include <iostream>
#include <string>

namespace Algorithms
{
/**
\brief A class to handle a Node of a Red-Black Tree. The node contains pointers to the parent, left and right child. All of them could be null.
\see RBTree
**/
template<typename TypeKey, typename TypeValue>
class NodeRBTree
{
public:
	//!< Enum that represents the color of the node.
	enum
	{
		COLOR_RED = 1,	//!< Red node.
		COLOR_BLACK = 2 //!< Black node.
	};

	/*! Constructor */
	NodeRBTree() : m_left(nullptr), m_right(nullptr), m_parent(nullptr), m_value(nullptr) { m_color = COLOR_RED; }
	
	/*! Constructor */
	NodeRBTree(TypeKey key, TypeValue value, int color = COLOR_BLACK) 
		: m_left(nullptr), m_right(nullptr), m_parent(nullptr), m_key(key), m_color(color) 
	{
		m_value = new TypeValue(value);
	}

	/*! Constructor 
	\param color The color to use for the node.
	*/
	NodeRBTree(int color) 
		: m_color(color), m_left(nullptr), m_right(nullptr), m_parent(nullptr), m_value(nullptr) 
	{
	}

	/*! Constructor 
	\param key The key to use for the node.
	\param value The value to use for the node.
	*/
	NodeRBTree(TypeKey key, TypeValue value) : m_key(key), m_left(nullptr), m_right(nullptr), m_parent(nullptr)
	{ 
		m_value = new TypeValue(value); 
	}

	/*! Operator equal. */
	bool operator==(const NodeRBTree<TypeKey, TypeValue> & other) const
	{
		if (this->m_color == other.m_color &&
			this->m_left == other.m_left &&
			this->m_right == other.m_right &&
			this->m_parent == other.m_parent)
			return true;
		else
			return false;
	}

	/*! Operator not equal. */
	bool operator!=(const NodeRBTree<TypeKey, TypeValue>& other) const
	{
		if (this->m_color != other.m_color ||
			this->m_left != other.m_left ||
			this->m_right != other.m_right ||
			this->m_parent != other.m_parent)
			return true;
		else
			return false;
	}
	
	/*! Destructor. WARNING!: This destroys this object and all the children. */
	~NodeRBTree()
	{
		if (m_value)
		{
			delete m_value;
			if (m_right && m_right->m_value)
			{
				delete m_right;
			}
			if (m_left && m_left->m_value)
			{
				delete m_left;
			}
		}
	}

	/*! Prints the data of the node. */
	void print(int level = 0, std::string separator = " ")
	{
		std::string colorString = "Black";
		if (m_color == COLOR_RED)
		{
			colorString = "Red";
		}
		if (m_value)
		{
			for (int i = 0; i < level; ++i)
				std::cout << '-'; 

			std::cout << "(" << m_key << ' ' << *m_value << ", " << colorString << " )" << separator;
			std::cout << std::endl;
		}
	}

	TypeKey m_key;				//!< Key of the node
	TypeValue* m_value;			//!< Value of the node
	NodeRBTree* m_left;			//!< Pointer to the left child.
	NodeRBTree* m_right;		//!< Pointer to the right child
	NodeRBTree* m_parent;		//!< Pointer to the parent
	int m_color;				//!< Color of the node. 1: Red, 2: Black
};
}

#endif