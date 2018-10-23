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

Type::Type(int digitIn/*id, int diam, string status, string health,
	string spc, int zip, string boro, double x, double y*/)
{
	digit = digitIn;
/*
	Type_id = id;
	Type_dbh = diam;
	this->status = status;
	this->health = health;
	digit = spc;
	zipcode = zip;
	boroname = boro;
	x_sp = x;
	y_sp = y;
	*/
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
//This compares the two Types using digit as the primary key returns true 
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
//Comma seperated list output per professor
//This prints a Type object onto the given ostream. Each of the members of the Type object should
//be printed, with the Type digit name frst, then the Type_id. After that the order is not
//specifed - it can be whatever the programmer decides as long as it is clear.
ostream& operator<< (ostream & os, const Type & t)
{
	os << t.digit;
	return os;
}
//This returns true if and only if the two Types passed to it have identical digit members.
//This differs from operator== because it ignores the Type_id. (case insensitive)
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