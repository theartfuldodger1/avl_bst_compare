/*
Author: Cordell Hurst
Course : CSCI 335 Software Design and Analysis III
Instructor: Pavel Shostak
Assignment 02
22 October 2018
This program is tasked to takes random integers and inserts into an BST tree and a BST.
Instertions are 1k, 100k and 1m nodes. the duration of the insertions are timed and compared.
*/

#include <iostream>
#include <string> //for string handling
#include <list> //for lists

#include "BST.h"

using namespace std;

// default
BST::BST()
{
	root = NULL;
}
// copy constructor
BST::BST(const BST &Tree)
{
	root = clone(Tree.root);
}
//destructor
BST::~BST()
{

	makeEmpty(root);
	delete root;
}

// Search methods:
//Recursive. returns as a Type. string comparison
const Type& BST::find(const Type &x) const
{
	return find(x, root);
}
//Recursive. Returns min based on string comparison
const Type& BST::findMin() const
{
	return findMin(root);
}
//Recursive. Returns max based on string comparison
const Type& BST::findMax() const
{
	return findMax(root);
}
//Search for all matches of a particular species based on string comparison
//uses two algorithms, one an iterative search/find and the other an iterative
//in-order traversal modified to start with the object found by the first algo
//and push the found objects into a list. The in-order traversal uses a stack
//returns a list of Types
list<Type> BST::findallmatches(const Type &x) const
{
	//use an iterative find. once found, use that as new root for loop
	bool done = false;
	Type Type1 = x;
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
	while (!done)//modified iterative in-order traversal using a stack
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
// Displaying the Type contents:
void BST::print(ostream& out) const
{
	if (root == nullptr)
	{
		out << "Empty Type.\n";
	}
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
//empties BST Type
void BST::clear()// empty the Type
{
	makeEmpty(root);
}
//calls recursive insert
void BST::insert(const Type& x)// insert element x
{
	//call private recursive func
	insert(x, root);
}
//calls recursive remove function
void BST::remove(const Type& x)// remove element x
{
	//call private recursive func
	remove(x, root);
}


//PRIVATE RECURSIVE FUNCTIONS
//Copy constructor accessed by regular copy constructor
BST::Node* BST::clone(Node *NodeIn) const
{
	if (NodeIn == nullptr)
	{
		return nullptr;
	}
	else
	{
		return new Node{ NodeIn->NodeElement, clone(NodeIn->left), clone(NodeIn->right), NodeIn->height };
	}
}
//donish
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
//Printing method that demonstrates 3 different print algorithms. This is called by disabled internally
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
//recursive findMin(). Returns Type object if found. otherwise empty Type
const Type& BST::findMin(Node *NodeIn) const
{
	if (NodeIn == nullptr)
		return NO_Type;
	if (NodeIn->left == nullptr)
		return NodeIn->NodeElement;
	return findMin(NodeIn->left);
}
//Recursive findMax(). Returns Type object if found. otherwise empty Type
const Type& BST::findMax(Node* NodeIn) const
{
	if (NodeIn == nullptr)
		return NO_Type;
	if (NodeIn->right == nullptr)
		return NodeIn->NodeElement;
	return findMin(NodeIn->right);
}
//Recursive insert w/balance call
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
//Recursive remove w/ balance call
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
/*
//Type Adjustment functions. All BST nodes created with height info to facilitate
//Balances BST Type, keeps order integrity
void BST::balance(Node *&NodeIn)
{
	if (NodeIn == nullptr)
		return;
	if (height(NodeIn->left) - height(NodeIn->right) > ALLOWED_IMBALANCE)
	{
		if (height(NodeIn->left->left) >= height(NodeIn->left->right))
			rotateLL(NodeIn);
		else
			doubleWithLeftChild(NodeIn);
	}
	else
	{
		if (height(NodeIn->right) - height(NodeIn->left) > ALLOWED_IMBALANCE)
		{
			if (height(NodeIn->right->right) >= height(NodeIn->right->left))
				rotateRR(NodeIn);
			else
				doubleWithRightChild(NodeIn);
		}
	}
	NodeIn->height = max(height(NodeIn->left), height(NodeIn->right)) + 1;
}
//Rotate left
void BST::rotateLL(Node *&NodeIn)//rotateWithLeftchild
{
	Node *tempnode = NodeIn->left;
	NodeIn->left = tempnode->right;
	tempnode->right = NodeIn;
	NodeIn->height = max(height(NodeIn->left), height(NodeIn->right)) + 1;
	tempnode->height = max(height(tempnode->left), NodeIn->height) + 1;
	NodeIn = tempnode;
}
//Rotate right
void BST::rotateRR(Node *&NodeIn)//rotateWithRightchild
{
	Node *tempnode = NodeIn->right;
	NodeIn->right = tempnode->left;
	tempnode->left = NodeIn;
	NodeIn->height = max(height(NodeIn->right), height(NodeIn->left)) + 1;
	tempnode->height = max(height(tempnode->right), NodeIn->height) + 1;
	NodeIn = tempnode;
}
//Double rotation, calls RL
void BST::doubleWithLeftChild(Node *&NodeIn)
{
	rotateRR(NodeIn->left);
	rotateLL(NodeIn);
}
//Double Rotation, calls LR
void BST::doubleWithRightChild(Node *&NodeIn)
{
	rotateLL(NodeIn->right);
	rotateRR(NodeIn);
}
*/
//Other
//Returns height of BST node for rotations and balance
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

