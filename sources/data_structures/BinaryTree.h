#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <functional>

#include "NodeBinaryTree.h"

namespace Algorithms
{ 
/*!
\class BinaryTree
\brief A class to handle a Binary Tree
\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 12
*/
template<typename TypeKey, typename TypeValue>
class BinaryTree
{
public:
	
	/*! Constructor */
	BinaryTree()
	{
		m_root = nullptr;
	}
	
	/*! Destructor */
	~BinaryTree()
	{
		delete m_root;
	}

	/*! Search for a value in the Binary Tree that has the given key. */
	TypeValue* search(TypeKey key)
	{
		NodeBinaryTree<TypeKey, TypeValue>* itNode = m_root;

		while (itNode != nullptr && itNode->m_key != key)
		{
			if (itNode->m_key < key)
			{
				itNode = itNode->m_left;
			}
			else
			{
				itNode = itNode->m_right;
			}
		}
		return itNode->m_value;
	}

	/*! Obtain the node with the minimum key of the tree. */
	NodeBinaryTree<TypeKey, TypeValue>* minimum()
	{
		return minimum(m_root);
	}
	
	/*! Obtain the node with the maximum Key. */
	NodeBinaryTree<TypeKey, TypeValue>* maximum()
	{
		NodeBinaryTree<TypeKey, TypeValue>* itNode = m_root;
		while (itNode && itNode->m_right)
		{
			itNode = itNode->m_right;
		}
		return itNode;
	}

	/*! Inserts a node into the tree. */
	void insert(TypeKey key, TypeValue value)
	{
		NodeBinaryTree<TypeKey, TypeValue>* newNode = new NodeBinaryTree<TypeKey, TypeValue>(key, value);
		NodeBinaryTree<TypeKey, TypeValue>* parentToNew = nullptr;
		NodeBinaryTree<TypeKey, TypeValue>* itNode = m_root;
		
		while (itNode != nullptr)
		{
			parentToNew = itNode;
			if (key < itNode->m_key)
			{
				itNode = itNode->m_left;
			}
			else
			{
				itNode = itNode->m_right;
			}
		}
		newNode->m_parent = parentToNew;

		if (!parentToNew)
		{
			m_root = newNode;
		}
		else
		{
			if (key < parentToNew->m_key)
			{
				parentToNew->m_left = newNode;
			}
			else
			{
				parentToNew->m_right = newNode;
			}
		}
	}

	/*! Removes a pointed node from the tree. */
	void remove(NodeBinaryTree<TypeKey, TypeValue>* nodez)
	{
		if (nodez->m_left == nullptr)
		{
			transplant(nodez, nodez->m_right);
		}
		else if (nodez->m_right == nullptr)
		{
			transplant(nodez, nodez->m_left);
		}
		else
		{
			NodeBinaryTree<TypeKey, TypeValue>* nodey = minimum(nodez->m_right);
			if (nodey->m_parent != nodez)
			{
				transplant(nodey, nodey->m_right);
				nodey->m_right = nodez->m_right;
				nodey->m_right->m_parent = nodey;
			}
			transplant(nodez, nodey);
			nodey->m_left = nodez->m_left;
			nodey->m_left->m_parent = nodey;
		}
	}

	/*! Prints the tree inorder */
	void print(std::string separator = " ")
	{
		print(m_root, separator);
		std::cout << std::endl;
	}
private:
	/*! Obtain the node with the minimum key of the given subtree. */
	NodeBinaryTree<TypeKey, TypeValue>* minimum(NodeBinaryTree<TypeKey, TypeValue>* root)
	{
		NodeBinaryTree<TypeKey, TypeValue>* itNode = root;
		while (itNode && itNode->m_left)
		{
			itNode = itNode->m_left;
		}
		return itNode;
	}
	
	/*! Helper to print the tree inorder*/
	void print(NodeBinaryTree<TypeKey, TypeValue>* root, std::string separator = " ")
	{
		if (root)
		{
			print(root->m_left, separator);
			root->print(separator);
			print(root->m_right, separator);
		}
	}

	/*! Moves a tree from u to v. */
	void transplant(NodeBinaryTree<TypeKey, TypeValue>* u, NodeBinaryTree<TypeKey, TypeValue>* v)
	{
		if (!u->m_parent)
		{
			m_root = v;
		}
		else if (u == u->m_parent->m_left)
		{
			u->m_parent->m_left = v;
		}
		else
		{
			u->m_parent->m_right = v;
		}
		if (v)
		{
			v->m_parent = u->m_parent;
		}
	}
	
private:
	NodeBinaryTree<TypeKey, TypeValue>* m_root; //!< The root node of the tree.
};
}

#endif