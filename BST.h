/*
Author: Cordell Hurst
Course : CSCI 335 Software Design and Analysis III
Instructor: Pavel Shostak
Assignment 02
24 October 2018
This program is tasked to take random integers and inserts into an AVL tree and a BST.
Insertions are 1k, 10k, 100k and 1m nodes. -the duration of the insertions are timed and compared.
Using C++11
Compile with g++ -o out AVL.h AVL.cpp BST.cpp BST.h Type.cpp Type.h main.cpp -std=c++11
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

	Node *root;
	Node* clone(Node *NodeIn) const;

	int height(Node *NodeIn) const;
	int max(int, int);//returns greater of 2 numbers or returns either if equal

	void insert(const Type &TypeIn, Node *&NodeIn);
	void makeEmpty(Node *&NodeIn);
	void printType(Node *NodeIn, ostream& out = cout) const;
	void remove(const Type &TypeIn, Node *&NodeIn);

	//RECURSIVE search functions
	const Type& find(const Type &TypeIn, Node *NodeIn) const;
	const Type& findMin(Node* NodeIn) const;
	const Type& findmax(Node* NodeIn) const;

	//special print functions. each prints entire contents of tree
	void displayInOrder(Node *) const;
	void displayPreOrder(Node *) const;
	void displayPostOrder(Node *) const;

public:
	BST();                  // default
	BST(const BST &);		// copy constructor
	~BST();					// destructor
	
	// Search methods:
	const Type& find(const Type& typeIn) const;
	const Type& findMin() const;
	const Type& findmax() const;
	
	const Type& operator[](int);

	//searches the entire tree for all occurrences of Type objects that match its Type argument.
	//Does NOT have to etypeInamine every single Node in the tree every time it is called and 
	//does so without missing any matching objects. Uses samename() method to match.
	list<Type> findallmatches(const Type & typeIn) const;

	// Displaying the Type contents:
	void print(ostream& out) const;

	// Tree modifiers:
	void clear();                // empty the Tree
	void insert(const Type& typeIn);  // insert element
	void remove(const Type& typeIn);  // remove element

	void printAll();//disabled internally.
};

#endif /* __BST_H__ */