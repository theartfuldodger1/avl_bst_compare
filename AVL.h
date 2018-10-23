
/*
Author: Cordell Hurst
Course : CSCI 335 Software Design and Analysis III
Instructor: Stewart Weiss
Assignment 02
30 March 2017
This program is tasked to read the input file, parse its lines, construct a Type object for each line
and make the calls to the Type_Collection class to insert Type objects into the collection. As each line of data
is read, its 41 fields are separated and the proper subset of nine of them are used to construct the
Type object. Type_Collection, uses the "spc_common/Type_id" pair as a unique key for inserting
the Type objects into the encapsulated AVL Type. The TypeCollection also keeps track of the names of
all species that are stored and in which boroughs the Types are located using <set>. AVL holds all
complete Types from the census. Any blank feilds that have been declared blank or incorrectly may
invalidate that line of data. the user is asked to provide a species name/Type type in as few as one word
or as many as three. the users input is processed and the species that match or have individual consecutive
words that match are counted and that information is displayed for the user. Data comes from NYC Open Data
and can be visualized @ www.cloudred.com/labprojects/nycTypes
*/

#ifndef __AVL_H__
#define __AVL_H__

#include <iostream>
#include <string>
#include <list>

#include "Type.h"

using namespace std;

class AVL
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
	int max(int, int); //returns greater of 2 numbers or returns either if equal

	void balance(Node *&NodeIn);
	void doubleWithLeftChild(Node *&NodeIn);
	void doubleWithRightChild(Node *&NodeIn);
	void insert(const Type &TypeIn, Node *&NodeIn);
	void makeEmpty(Node *&NodeIn);
	void printType(Node *NodeIn, ostream& out = cout) const;
	void remove(const Type &TypeIn, Node *&NodeIn);
	void rotateLL(Node *&NodeIn);
	void rotateRR(Node *&NodeIn);

	const Type& find(const Type &TypeIn, Node *NodeIn) const;
	const Type& findMin(Node* NodeIn) const;
	const Type& findMax(Node* NodeIn) const;

	void displayInOrder(Node *) const;
	void displayPreOrder(Node *) const;
	void displayPostOrder(Node *) const;

public:
	AVL();                     // default
	AVL(const AVL &);		// copy constructor
	~AVL();					// destructor

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

#endif /* __AVL_H__ */