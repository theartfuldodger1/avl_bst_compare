
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

#include <iostream>
#include <string> //for string handling
#include <list> //for lists

#include "AVL.h"

using namespace std;

// default
AVL::AVL()
{
	root = NULL;
}
// copy constructor
AVL::AVL(const AVL &Tree)
{
	root = clone(Tree.root);
}
//destructor
AVL::~AVL()
{
	makeEmpty(root);
	delete root;
}

// Search methods:
//Recursive. returns as a Type. string comparison
const Type& AVL::find(const Type &x) const
{
	return find(x, root);
}
//Recursive. Returns min based on string comparison
const Type& AVL::findMin() const
{
	return findMin(root);
}
//Recursive. Returns max based on string comparison
const Type& AVL::findMax() const
{
	return findMax(root);
}
//Search for all matches of a particular species based on string comparison
//uses two algorithms, one an iterative search/find and the other an iterative
//in-order traversal modified to start with the object found by the first algo
//and push the found objects into a list. The in-order traversal uses a stack
//returns a list of Types
list<Type> AVL::findallmatches(const Type &x) const
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
void AVL::print(ostream& out) const
{
	if (root == nullptr)
	{
		out << "Empty Type.\n";
	}
	else
		printType(root, out);
}
//recursiveness action! another way to display the Type contents
void AVL::printType(Node *NodeIn, ostream& out) const
{
	if (NodeIn != nullptr)
	{
		printType(NodeIn->left, out);
		out << NodeIn->NodeElement << endl;
		printType(NodeIn->right, out);
	}
}

// Type modifiers:
//empties avl Type
void AVL::clear()// empty the Type
{
	makeEmpty(root);
}
//calls recursive insert
void AVL::insert(const Type& x)// insert element x
{
	//call private recursive func
	insert(x, root);
}
//calls recursive remove function
void AVL::remove(const Type& x)// remove element x
{
	//call private recursive func
	remove(x, root);
}


//PRIVATE RECURSIVE FUNCTIONS
//Copy constructor accessed by regular copy constructor
AVL::Node* AVL::clone(Node *NodeIn) const
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
void AVL::makeEmpty(Node *&NodeIn)
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
void AVL::printAll()
{
	//this->displayInOrder(root);
	//cout << "Print In Order Complete\n";
	//this->displayPreOrder(root);
	//cout << "Print Pre Order Complete\n";
	//this->displayPostOrder(root);
	//cout << "Print Post Order Complete\n";
}
//Recursive printing methods:
void AVL::displayInOrder(Node *nodein) const
{
	if (nodein)
	{
		displayInOrder(nodein->left);
		cout << nodein->NodeElement << endl;
		displayInOrder(nodein->right);
	}
}
void AVL::displayPreOrder(Node *nodein) const
{
	if (nodein)
	{
		cout << nodein->NodeElement << endl;
		displayPreOrder(nodein->left);
		displayPreOrder(nodein->right);
	}
}
void AVL::displayPostOrder(Node *nodein) const
{
	if (nodein)
	{
		displayPostOrder(nodein->left);
		displayPostOrder(nodein->right);
		cout << nodein->NodeElement << endl;
	}
}
//Recursive find() Returns Type object if found. otherwise empty Type
const Type& AVL::find(const Type &TypeIn, Node *NodeIn) const
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
const Type& AVL::findMin(Node *NodeIn) const
{
	if (NodeIn == nullptr)
		return NO_Type;
	if (NodeIn->left == nullptr)
		return NodeIn->NodeElement;
	return findMin(NodeIn->left);
}
//Recursive findMax(). Returns Type object if found. otherwise empty Type
const Type& AVL::findMax(Node* NodeIn) const
{
	if (NodeIn == nullptr)
		return NO_Type;
	if (NodeIn->right == nullptr)
		return NodeIn->NodeElement;
	return findMin(NodeIn->right);
}
//Recursive insert w/balance call
void AVL::insert(const Type &TypeIn, Node *&NodeIn)
{
	if (NodeIn == nullptr)
		NodeIn = new Node{ TypeIn, nullptr , nullptr, 0 };//insert as leaf
	else if (TypeIn < NodeIn->NodeElement)
		insert(TypeIn, NodeIn->left);
	else if (NodeIn->NodeElement < TypeIn)
		insert(TypeIn, NodeIn->right);
	else
		//Duplicate; do nothing
		balance(NodeIn);
}
//Recursive remove w/ balance call
void AVL::remove(const Type &TypeIn, Node *&NodeIn)
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
	balance(NodeIn);
}

//Type Adjustment functions. All AVL nodes created with height info to facilitate
//Balances AVL Type, keeps order integrity
void AVL::balance(Node *&NodeIn)
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
void AVL::rotateLL(Node *&NodeIn)//rotateWithLeftchild
{
	Node *tempnode = NodeIn->left;
	NodeIn->left = tempnode->right;
	tempnode->right = NodeIn;
	NodeIn->height = max(height(NodeIn->left), height(NodeIn->right)) + 1;
	tempnode->height = max(height(tempnode->left), NodeIn->height) + 1;
	NodeIn = tempnode;
}
//Rotate right
void AVL::rotateRR(Node *&NodeIn)//rotateWithRightchild
{
	Node *tempnode = NodeIn->right;
	NodeIn->right = tempnode->left;
	tempnode->left = NodeIn;
	NodeIn->height = max(height(NodeIn->right), height(NodeIn->left)) + 1;
	tempnode->height = max(height(tempnode->right), NodeIn->height) + 1;
	NodeIn = tempnode;
}
//Double rotation, calls RL
void AVL::doubleWithLeftChild(Node *&NodeIn)
{
	rotateRR(NodeIn->left);
	rotateLL(NodeIn);
}
//Double Rotation, calls LR
void AVL::doubleWithRightChild(Node *&NodeIn)
{
	rotateLL(NodeIn->right);
	rotateRR(NodeIn);
}

//Other
//Returns height of AVL node for rotations and balance
int AVL::height(Node *NodeIn) const
{
	return NodeIn == nullptr ? -1 : NodeIn->height;
}
//simple greater than, less than function
int AVL::max(int left, int right)
{
	if (left < right)
		return right;
	else if (right < left)
		return left;
	else
		return left;//both are same value
}

