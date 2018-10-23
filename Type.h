/*
Author: Cordell Hurst
Course : CSCI 335 Software Design and Analysis III
Instructor: Pavel Shostak
Assignment 02
22 October 2018
This program is tasked to takes random integers and inserts into an AVL tree and a BST.
Instertions are 1k, 100k and 1m nodes. the duration of the insertions are timed and compared.
*/

#ifndef __Type_H__
#define __Type_H__

#include <iostream>
#include <string>

using namespace std;

class Type
{
public:
	Type(int digitIn);

	friend bool islessname(const Type & t1, const Type & t2);
	friend bool samename(const Type & t1, const Type & t2);
	friend bool operator==(const Type & t1, const Type & t2);
	friend bool operator<(const Type & t1, const Type & t2);
	friend ostream& operator<< (ostream & os, const Type & t);

	//Getters
	int getDigit();

private:
	int digit;
};
// A Type object indicating no Type exists
const Type  NO_Type(-1);

#endif /* __Type_H__ */