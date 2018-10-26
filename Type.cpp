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
#include "Type.h"

using namespace std;

Type::Type(int digitIn): digit(digitIn) { }
//Given two Type objects, this function returns true if and only if they have the same value.
bool operator==(const Type &Type1, const Type &Type2)
{
	int digit1 = Type1.digit;
	int digit2 = Type2.digit;

	if (digit1 == digit2)
		return true;

	return false;
}
//This compares the two Types using digit as the primary key. Returns true 
//if Type1 is less than Type2 in this ordering and false otherwise
//originally constructed using a second key for a different application
bool operator<(const Type & Type1, const Type & Type2)
{
	int digit1 = Type1.digit;
	int digit2 = Type2.digit;

	if (digit1 < digit2)
		return true;
	else //if (digit2 < digit1)
		return false;

}
//This prints a() Type object onto the given ostream. Each of the members of the Type object should
//be printed in general. In this instance we only type Type digit
ostream& operator<< (ostream & os, const Type & t)
{
	os << t.digit;
	return os;
}
//This returns true if and only if the two Types passed to it have identical digit members.
//This could differ from operator== because either could be allowed to use a secondary key 
//originally constructed using a second key for a different application
bool samename(const Type & Type1, const Type & Type2)
{
	int digit1 = Type1.digit;
	int digit2 = Type2.digit;

	if (digit1 == digit2)
		return true;

	return false;
}
//This returns true if and only the digit member of the first Type object is smaller than
//that of the second. This is redundant to operator<. either could be allowed to use a secondary key 
//originally constructed using a second key for a different application
bool islessname(const Type & Type1, const Type & Type2)
{
	int digit1 = Type1.digit;
	int digit2 = Type2.digit;

	if (digit1 < digit2)
		return true;
	else
		return false;
}
//simple getter. This returns the digit of the Type
int Type::getDigit()
{
	return digit;
}