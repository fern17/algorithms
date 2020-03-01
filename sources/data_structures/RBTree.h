#ifndef RBTREE_H
#define RBTREE_H
#include "NodeRBTree.h"

namespace Algorithms
{ 
/*!
\class RBTree
\brief A class to handle a Red-Black Tree
\see "Introduction to Algorithms", 3rd Edition, 2009. Thomas Cormen et al. MIT Press. Chapter 13
*/
template<typename TypeKey, typename TypeValue>
class RBTree
{
	typedef NodeRBTree<TypeKey, TypeValue> Node;
public:
	/*! Contructor */
	RBTree()
	{
		m_root = nullptr;
		m_nil = new NodeRBTree<TypeKey, TypeValue>(Node::COLOR_BLACK);
	}

	/*! Destructor */
	~RBTree()
	{
		delete m_root;
		delete m_nil;
		m_nil = nullptr;
	}

	/*! Insert a node to the tree */
	void insert(TypeKey key, TypeValue value)
	{
		Node* z = new Node(key, value, Node::COLOR_RED);
		Node* y = m_nil;
		Node* x = m_root;

		while (x && *x != *m_nil)
		{
			y = x;
			if (z->m_key < x->m_key)
			{
				x = x->m_left;
			}
			else
			{
				x = x->m_right;
			}
		}
		z->m_parent = y;
		if (*y == *m_nil)
		{
			m_root = z;
		}
		else if (z->m_key < y->m_key)
		{
			y->m_left = z;
		}
		else
		{
			y->m_right = z;
		}
		z->m_left = m_nil;
		z->m_right = m_nil;
		insert_fixup(z);
	}
	
	/*! Remove a node from the tree*/
	void remove(Node* z)
	{
		Node* x = m_nil;
		Node* y = z;
		int yorigcolor = y->m_color;
		if (*(z->m_left) == *m_nil)
		{
			x = z->m_right;
			transplant(z, z->m_right);
		}
		else if (*(z->m_right) == *m_nil)
		{
			x = z->m_left;
			transplant(z, z->m_left);
		}
		else
		{
			y = minimum(z->m_right);
			yorigcolor = y->m_color;
			x = y->m_right;
			if (*(y->m_parent) == *z)
			{
				x->m_parent = y;
			}
			else
			{
				transplant(y, y->m_right);
				y->m_right = z->m_right;
				y->m_right->m_parent = y;
			}
			transplant(z, y);
			y->m_left = z->m_left;
			y->m_left->m_parent = y;
			y->m_color = z->m_color;
		}

		if (yorigcolor == Node::COLOR_BLACK)
		{
			remove_fixup(x);
		}
	}

	/*! Prints the tree inorder */
	void print(std::string separator = " ")
	{
		print(m_root, 0, separator);
		std::cout << std::endl;
	}

	/*! Obtain the node with the minimum Key. */
	Node* minimum()
	{
		return minimum(m_root);
	}

	/*! Obtain the node with the maximum Key. */
	Node* maximum()
	{
		Node* itNode = m_root;
		while (itNode && *itNode != *m_nil && itNode->m_right && *(itNode->m_right) != *m_nil)
		{
			itNode = itNode->m_right;
		}
		return itNode;
	}

private:
	/*! Helper to print the tree inorder*/
	void print(Node* root, int level, std::string separator = " ")
	{
		if (root)
		{
			root->print(level, separator);
			print(root->m_left, level+1, separator);
			print(root->m_right, level+1,separator);
		}
	}

	/*! Fix coloring of tree after inserting a node. */
	void insert_fixup(Node* z)
	{
		while (z->m_parent->m_color == Node::COLOR_RED)
		{
			if (*(z->m_parent) == *(z->m_parent->m_parent->m_left))
			{
				Node* y = z->m_parent->m_parent->m_right;
				if (y && y->m_color == Node::COLOR_RED)
				{
					z->m_parent->m_color = Node::COLOR_BLACK;
					y->m_color = Node::COLOR_BLACK;
					z->m_parent->m_parent->m_color = Node::COLOR_RED;
					z = z->m_parent->m_parent;
				}
				else
				{
					if (*z == *(z->m_parent->m_right))
					{
						z = z->m_parent;
						left_rotate(z);
					}
					z->m_parent->m_color = Node::COLOR_BLACK;
					z->m_parent->m_parent->m_color = Node::COLOR_RED;
					right_rotate(z->m_parent->m_parent);
				}
			}
			else
			{
				Node* y = z->m_parent->m_parent->m_left;
				if (y && y->m_color == Node::COLOR_RED)
				{
					z->m_parent->m_color = Node::COLOR_BLACK;
					y->m_color = Node::COLOR_BLACK;
					z->m_parent->m_parent->m_color = Node::COLOR_RED;
					z = z->m_parent->m_parent;
				}
				else
				{
					if (*z == *(z->m_parent->m_left))
					{
						z = z->m_parent;
						right_rotate(z);
					}
					z->m_parent->m_color = Node::COLOR_BLACK;
					z->m_parent->m_parent->m_color = Node::COLOR_RED;
					left_rotate(z->m_parent->m_parent);
				}
			}
		}
		m_root->m_color = Node::COLOR_BLACK;
	}

	/*! Fix coloring of tree after removing a node. */
	void remove_fixup(Node* x)
	{
		while (x && *x != *m_root && x->m_color == Node::COLOR_BLACK)
		{
			if (*x == *(x->m_parent->m_left))
			{
				Node* w = x->m_parent->m_right;
				if (w && w->m_color == Node::COLOR_RED)
				{
					w->m_color = Node::COLOR_BLACK;
					x->m_parent->m_color = Node::COLOR_RED;
					left_rotate(x->m_parent);
					w = x->m_parent->m_right;
				}
				if (w && w->m_left && 
					w->m_left->m_color == Node::COLOR_BLACK && 
					w->m_right->m_color == Node::COLOR_BLACK)
				{
					w->m_color = Node::COLOR_RED;
					x = x->m_parent;
				}
				else
				{
					if (w && w->m_right && w->m_right->m_color == Node::COLOR_BLACK)
					{
						w->m_left->m_color = Node::COLOR_BLACK;
						w->m_color = Node::COLOR_RED;
						right_rotate(w);
						w = x->m_parent->m_right;
					}
					w->m_color = x->m_parent->m_color;
					x->m_parent->m_color = Node::COLOR_BLACK;
					w->m_right->m_color = Node::COLOR_BLACK;
					left_rotate(x->m_parent);
					x = m_root;
				}
			}
			else
			{
				Node* w = x->m_parent->m_left;
				if (w && w->m_color == Node::COLOR_RED)
				{
					w->m_color = Node::COLOR_BLACK;
					x->m_parent->m_color = Node::COLOR_RED;
					right_rotate(x->m_parent);
					w = x->m_parent->m_left;
				}
				if (w && w->m_right && 
					w->m_right->m_color == Node::COLOR_BLACK &&
					w->m_left->m_color == Node::COLOR_BLACK)
				{
					w->m_color = Node::COLOR_RED;
					x = x->m_parent;
				}
				else
				{
					if (w && w->m_left && w->m_left->m_color == Node::COLOR_BLACK)
					{
						w->m_right->m_color = Node::COLOR_BLACK;
						w->m_color = Node::COLOR_RED;
						left_rotate(w);
						w = x->m_parent->m_left;
					}
					w->m_color = x->m_parent->m_color;
					x->m_parent->m_color = Node::COLOR_BLACK;
					w->m_left->m_color = Node::COLOR_BLACK;
					
					right_rotate(x->m_parent);
					x = m_root;
				}
			}
		}
		x->m_color = Node::COLOR_BLACK;
	}

	/*! Rotate the tree to the left. */
	void left_rotate(Node* x)
	{
		Node* y = x->m_right;
		x->m_right = y->m_left;
		if (*(y->m_left) != *m_nil)
		{
			y->m_left->m_parent = x;
		}

		y->m_parent = x->m_parent;

		if (*(x->m_parent) == *m_nil)
		{
			m_root = y;
		}
		else if (*x == *(x->m_parent->m_left))
		{
			x->m_parent->m_left = y;
		}
		else
		{
			x->m_parent->m_right = y;
		}

		y->m_left = x;
		x->m_parent = y;
	}

	/*! Rotate the tree to the right. */
	void right_rotate(Node* x)
	{
		Node* y = x->m_left;
		x->m_left = y->m_right;
		if (*(y->m_right) != *m_nil)
		{
			y->m_right->m_parent = x;
		}

		y->m_parent = x->m_parent;

		if (*(x->m_parent) == *m_nil)
		{
			m_root = y;
		}
		else if (*x == *(x->m_parent->m_right))
		{
			x->m_parent->m_right = y;
		}
		else
		{
			x->m_parent->m_left = y;
		}

		y->m_right = x;
		x->m_parent = y;
	}

	/*! Transplant a node to another position */
	void transplant(Node* u, Node* v)
	{
		if (u->m_parent == m_nil)
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
		v->m_parent = u->m_parent;
	}

	/*! Obtain the node with the minimum key of the given subtree. */
	Node* minimum(Node* root)
	{
		Node* itNode = root;
		while (itNode && *itNode != *m_nil && itNode->m_left && *(itNode->m_left) != *m_nil)
		{
			itNode = itNode->m_left;
		}
		return itNode;
	}

private:
	Node* m_root; //!< Root of the tree
	Node* m_nil;	//!< Null node of the tree. All leaf nodes point to this.
};
}
#endif
