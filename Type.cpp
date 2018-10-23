/*
Author: Cordell Hurst
Course : CSCI 335 Software Design and Analysis III
Instructor: Pavel Shostak
Assignment 02
22 October 2018
This program is tasked to takes random integers and inserts into an AVL tree and a BST.
Instertions are 1k, 100k and 1m nodes. the duration of the insertions are timed and compared.
*/

#include "Type.h"

using namespace std;

Type::Type(int digitIn)
{
	digit = digitIn;
}
//Given two Type objects, it returns true if and only if they have the same value.
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
bool operator<(const Type & Type1, const Type & Type2)
{
	int digit1 = Type1.digit;
	int digit2 = Type2.digit;

	if (digit1 < digit2)
		return true;
	else //if (digit2 < digit1)
		return false;

}
//This prints a Type object onto the given ostream. Each of the members of the Type object should
//be printed in general. In this instance we only type Type digit
ostream& operator<< (ostream & os, const Type & t)
{
	os << t.digit;
	return os;
}
//This returns true if and only if the two Types passed to it have identical digit members.
//This can differ from operator== because one can be allowed to ignore a secondary key 
bool samename(const Type & Type1, const Type & Type2)
{
	int digit1 = Type1.digit;
	int digit2 = Type2.digit;
	if (digit1 == digit2)
		return true;

	return false;
}
//This returns true if and only the digit member of the first Type object is smaller than
//that of the second as strings.This differs from operator< because it ignores the Type_id. (case
//insensitive). For example, myType.follows("mimosa") is true if myType.digit =="pine"
bool islessname(const Type & Type1, const Type & Type2)
{
	int digit1 = Type1.digit;
	int digit2 = Type2.digit;

	if (digit1 < digit2)
		return true;
	else
		return false;
}
//This returns the digit of the Type
int Type::getDigit()
{
	return digit;
}
/*
//This returns the digit of the Type.
string Type::common_name()
{
	return digit;
}
//This returns the name of the borough in which the Type is located.
string Type::borough_name()
{
	return boroname;
}
//This returns the value of the Type_dbh member.
double Type::diameter()
{
	return Type_dbh;
}
*/