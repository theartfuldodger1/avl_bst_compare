/*
Author: Cordell Hurst
Course : CSCI 335 Software Design and Analysis III
Instructor: Pavel Shostak
Assignment 02
22 October 2018
This program is tasked to takes random integers and inserts into an BST tree and a BST.
Instertions are 1k, 100k and 1m nodes. the duration of the insertions are timed and compared.
*/

#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include <string>
#include <list>

#include "Type.h"

using namespace std;

class BST
{
private:
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
	Node* clone(Node *NodeIn) const;

	Node *root;
	static const int ALLOWED_IMBALANCE = 1;

	int height(Node *NodeIn) const;
	int max(int, int);//returns greater of 2 numbers or returns either if equal

	void insert(const Type &TypeIn, Node *&NodeIn);
	void makeEmpty(Node *&NodeIn);
	void printType(Node *NodeIn, ostream& out = cout) const;
	void remove(const Type &TypeIn, Node *&NodeIn);

	const Type& find(const Type &TypeIn, Node *NodeIn) const;
	const Type& findMin(Node* NodeIn) const;
	const Type& findMax(Node* NodeIn) const;

	void displayInOrder(Node *) const;
	void displayPreOrder(Node *) const;
	void displayPostOrder(Node *) const;

public:
	BST();                  // default
	BST(const BST &);		// copy constructor
	~BST();					// destructor

	// Search methods:
	const Type& find(const Type& x) const;
	const Type& findMin() const;
	const Type& findMax() const;
	//searches the entire Type for all occurrences of Type objects that match its Type argument.
	//Does NOT have to examine every single Node in the Type every time it is called and 
	//does so without missing any matching objects. Uses samename() method.
	list<Type> findallmatches(const Type & x) const;

	// Displaying the Type contents:
	void print(ostream& out) const;

	// Type modifiers:
	void clear();                // empty the Type
	void insert(const Type& x);  // insert element
	void remove(const Type& x);  // remove element

	void printAll();//disabled internally.
};

#endif /* __BST_H__ */