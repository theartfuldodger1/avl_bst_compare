/*
Author: Cordell Hurst
Course : CSCI 335 Software Design and Analysis III
Instructor: Pavel Shostak
Assignment 02
24 October 2018
This program is tasked to takes random integers and inserts into an BST tree and a BST.
Insertions are 1k, 10k, 100k and 1m nodes. the duration of the insertions are timed and compared.
*/

#include <iostream>
#include <string> //for string handling
#include <list> //for lists

#include "BST.h"

using namespace std;

// default
BST::BST() : root(NULL) { }
// copy constructor
BST::BST(const BST &Tree) : root (clone(Tree.root)) { }
//destructor
BST::~BST()
{
	makeEmpty(root);
	delete root;
}
//Subscripting operator that returns a reference to the item. Must be a member function
Type & BST::operator[](int i) //https://www.tutorialspoint.com/cplusplus/subscripting_operator_overloading.htm
{
	if (i > )
	return typeIn;
}
// Search methods:
//Recursive. returns as a Type. comparison
const Type& BST::find(const Type &typeIn) const
{
	return find(typeIn, root);
}
//Recursive. Returns min based on comparison
const Type& BST::findMin() const
{
	return findMin(root);
}
//Recursive. Returns max based on comparison
const Type& BST::findmax() const
{
	return findmax(root);
}
//Search for all matches of a particular species based on digit value comparison
//uses two algorithms, one an iterative search/find and the other an iterative
//in-order traversal modified to start with the object found by the first algo
//and push the found objects into a list. The in-order traversal uses a stack.
//returns a list of Types
list<Type> BST::findallmatches(const Type &typeIn) const
{
	//use an iterative find. once found, use that as new root for loop
	bool done = false;
	Type Type1 = typeIn;
	list<Node*> NodeStack;
	list<Type> Outgoing;

	Node *current;
	current = root;

	//initial find algorithm
	while (current != NULL && !samename(Type1, current->NodeElement))
	{
		if (islessname(Type1, current->NodeElement))
			current = current->left;
		else
			current = current->right;
	}

	int i = 0;
	while (!done)//modified iteractive in-order traversal using a stack
	{
		if (current != nullptr)
		{
			NodeStack.push_front(current);
			current = current->left;
		}
		else
		{
			if (!NodeStack.empty())
			{
				current = NodeStack.front();

				if (samename(Type1, current->NodeElement))
					Outgoing.push_back(current->NodeElement);

				NodeStack.pop_front();
				current = current->right;
			}
			else
				done = 1;
		}
	}
	return Outgoing;
}
// Prints tree contents to console
void BST::print(ostream& out) const
{
	if (root == nullptr)
		out << "Empty Type.\n";
	else
		printType(root, out);
}
//recursiveness action! another way to display the Type contents
void BST::printType(Node *NodeIn, ostream& out) const
{
	if (NodeIn != nullptr)
	{
		printType(NodeIn->left, out);
		out << NodeIn->NodeElement << endl;
		printType(NodeIn->right, out);
	}
}
// Type modifiers:
//empties BST
void BST::clear()// empty the tree
{
	makeEmpty(root);
}
//calls recursive insert
void BST::insert(const Type& typeIn)// insert element typeIn
{
	//call private recursive  insert func
	insert(typeIn, root);
}
//calls recursive remove function
void BST::remove(const Type& typeIn)// remove element typeIn
{
	//call private recursive remove func
	remove(typeIn, root);
}

//PRIVATE RECURSIVE FUNCTIONS
//Copy constructor accessed by regular copy constructor
BST::Node* BST::clone(Node *NodeIn) const
{
	if (NodeIn == nullptr)
		return nullptr;
	else
		return new Node{ NodeIn->NodeElement, clone(NodeIn->left), clone(NodeIn->right), NodeIn->height };
}
//Internal recursive delete
void BST::makeEmpty(Node *&NodeIn)
{
	if (NodeIn != nullptr)
	{
		makeEmpty(NodeIn->left);
		makeEmpty(NodeIn->right);
		delete NodeIn;
	}
	NodeIn = nullptr;
}
//Printing method that demonstrates 3 different print algorithms.
//displayInOrder
//displayPreOrder
//displayPostOrder
void BST::printAll()
{
	this->displayInOrder(root);
	cout << "Print In Order Complete\n";
	this->displayPreOrder(root);
	cout << "Print Pre Order Complete\n";
	this->displayPostOrder(root);
	cout << "Print Post Order Complete\n";
}
//Recursive printing methods:
void BST::displayInOrder(Node *nodein) const
{
	if (nodein)
	{
		displayInOrder(nodein->left);
		cout << nodein->NodeElement << endl;
		displayInOrder(nodein->right);
	}
}
void BST::displayPreOrder(Node *nodein) const
{
	if (nodein)
	{
		cout << nodein->NodeElement << endl;
		displayPreOrder(nodein->left);
		displayPreOrder(nodein->right);
	}
}
void BST::displayPostOrder(Node *nodein) const
{
	if (nodein)
	{
		displayPostOrder(nodein->left);
		displayPostOrder(nodein->right);
		cout << nodein->NodeElement << endl;
	}
}
//Recursive find() Returns Type object if found. otherwise empty Type
const Type& BST::find(const Type &TypeIn, Node *NodeIn) const
{
	if (NodeIn == nullptr)
		return NO_Type;
	else if (TypeIn < NodeIn->NodeElement)
		return find(TypeIn, NodeIn->left);
	else if (NodeIn->NodeElement < TypeIn)
		return find(TypeIn, NodeIn->right);
	else
		return NodeIn->NodeElement; //Match!
}
//recursive findMin(). Returns Type object if found. otherwise returns NO_Type with -1
const Type& BST::findMin(Node *NodeIn) const
{
	if (NodeIn == nullptr)
		return NO_Type;
	if (NodeIn->left == nullptr)
		return NodeIn->NodeElement;
	return findMin(NodeIn->left);
}
//Recursive findmax(). Returns Type object if found. otherwise returns NO_Type with -1
const Type& BST::findmax(Node* NodeIn) const
{
	if (NodeIn == nullptr)
		return NO_Type;
	if (NodeIn->right == nullptr)
		return NodeIn->NodeElement;
	return findMin(NodeIn->right);
}
//Recursive insert w/o balance call
void BST::insert(const Type &TypeIn, Node *&NodeIn)
{
	if (NodeIn == nullptr)
		NodeIn = new Node{ TypeIn, nullptr , nullptr, 0 };//insert as leaf
	else if (TypeIn < NodeIn->NodeElement)
		insert(TypeIn, NodeIn->left);
	else if (NodeIn->NodeElement < TypeIn)
		insert(TypeIn, NodeIn->right);
	else
	{
		//Duplicate; do nothing
	}
		//balance(NodeIn);
}
//Recursive remove w/o balance call
void BST::remove(const Type &TypeIn, Node *&NodeIn)
{
	if (NodeIn == nullptr)
		return; //Item not found
	if (TypeIn < NodeIn->NodeElement)
		remove(TypeIn, NodeIn->left);
	else if (NodeIn->NodeElement < TypeIn)
		remove(TypeIn, NodeIn->right);
	else if (NodeIn->left != nullptr && NodeIn->right != nullptr) //Two children
	{
		NodeIn->NodeElement = findMin(NodeIn->right);
		remove(NodeIn->NodeElement, NodeIn->right);
	}
	else
	{
		Node *oldNode = NodeIn;
		NodeIn = (NodeIn->left != nullptr) ? NodeIn->left : NodeIn->right;
		delete oldNode;
	}
	//balance(NodeIn);
}
//Other

//Returns height of BST node
int BST::height(Node *NodeIn) const
{
	return NodeIn == nullptr ? -1 : NodeIn->height;
}

//simple greater than, less than function
int BST::max(int left, int right)
{
	if (left < right)
		return right;
	else if (right < left)
		return left;
	else
		return left;//both are same value
}

