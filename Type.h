/*
Author: Cordell Hurst
Course : CSCI 335 Software Design and Analysis III
Instructor: Pavel Shostak
Assignment 02
24 October 2018
This program is tasked to takes random integers and inserts into an AVL tree and a BST.
Insertions are 1k, 10k, 100k and 1m nodes. the duration of the insertions are timed and compared.
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

	//comparators. some redundancy etypeInists due to transfer of functions and classes from 
	//previously created application
	friend bool islessname(const Type & t1, const Type & t2);
	friend bool samename(const Type & t1, const Type & t2);
	friend bool operator==(const Type & t1, const Type & t2);
	friend bool operator<(const Type & t1, const Type & t2);
	friend ostream& operator<< (ostream & os, const Type & t);

	//Getter
	int getDigit();

private:
	int digit;
};
// A Type object indicating no Type exists with that digit value
const Type  NO_Type(-2);

#endif /* __Type_H__ */