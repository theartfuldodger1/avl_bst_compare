/*
Author: Cordell Hurst
Course : CSCI 335 Software Design and Analysis III
Instructor: Pavel Shostak
Assignment 02
22 October 2018
This program is tasked to takes random integers and inserts into an AVL tree and a BST. 
Instertions are 1k, 100k and 1m nodes. the duration of the insertions are timed and compared.
*/

#ifndef __AVL_H__
#define __AVL_H__

#include <iostream>
#include <string>
#include <list>

#include "Type.h"
#include "BST.h"

using namespace std;

class AVL : public BST
{
private:
/*
	struct Node
	{
		Type NodeElement;
		Node * left;
		Node * right;
		int height = 0;
		
		//Node constructors :
		Node(const Type &TypeIn, Node *lt, Node *rt, int ht)
			: NodeElement{ TypeIn }, left{ lt }, right{ rt }, height{ ht } { }
		
		Node(const Type &&TypeIn, Node *lt, Node *rt, int ht)
			: NodeElement{ move(TypeIn) }, left{ lt }, right{ rt }, height{ ht } { }
	};
	*/
	Node* clone(Node *NodeIn) const;

	Node *root;
	static const int ALLOWED_IMBALANCE = 1;

	int height(Node *NodeIn) const;
	int max(int, int); //returns greater of 2 numbers or returns either if equal

	void insert(const Type &TypeIn, Node *&NodeIn);
	void makeEmpty(Node *&NodeIn);
	void remove(const Type &TypeIn, Node *&NodeIn);

	void balance(Node *&NodeIn);
	void doubleWithLeftChild(Node *&NodeIn);
	void doubleWithRightChild(Node *&NodeIn);

	void rotateLL(Node *&NodeIn);
	void rotateRR(Node *&NodeIn);

	const Type& find(const Type &TypeIn, Node *NodeIn) const;
	const Type& findMin(Node* NodeIn) const;
	const Type& findMax(Node* NodeIn) const;

public:
	AVL();                  // default
	AVL(const AVL &);		// copy constructor
	~AVL();					// destructor

	// Type modifiers:
	void clear();                // empty the Type
	void insert(const Type& x);  // insert element
	void remove(const Type& x);  // remove element
};

#endif /* __AVL_H__ */