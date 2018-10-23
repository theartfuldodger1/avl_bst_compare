
/*
Author: Cordell Hurst
Course : CSCI 335 Software Design and Analysis III
Instructor: Stewart Weiss
Assignment 02
30 March 2017
This program is tasked to read the input file, parse its lines, construct a Type object for each line
and make the calls to the Type_Collection class to insert Type objects into the collection. As each line of data
is read, its 41 fields are separated and the proper subset of nine of them are used to construct the
Type object. Type_Collection, uses the "digit/Type_id" pair as a unique key for inserting
the Type objects into the encapsulated AVL Type. The TypeCollection also keeps track of the names of
all species that are stored and in which boroughs the Types are located using <set>. AVL_Type holds all
complete Types from the census. Any blank feilds that have been declared blank or incorrectly may
invalidate that line of data. the user is asked to provide a species name/Type type in as few as one word
or as many as three. the users input is processed and the species that match or have individual consecutive
words that match are counted and that information is displayed for the user. Data comes from NYC Open Data
and can be visualized @ www.cloudred.com/labprojects/nycTypes
*/

//#include <iostream> 
//#include <string>	//for string handling
//#include <algorithm>
//#include <iomanip>
//#include <sstream>

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
/*
//Convert int to a string, maintains limited number of digits
string toast(int value)
{
	if (value == 0)
		return "0";
	ostringstream s;
	s.precision(numeric_limits<int>::digits10);
	s << value;
	return s.str();
}
//Removes all trailing zeroes when converting an double to a string
string toast(double value)
{
	if (value == 0)
		return "0";
	ostringstream s;
	s.precision(numeric_limits<double>::digits10);
	s << value;
	return s.str();
}
*/
//Comma seperated list output per professor
//This prints a Type object onto the given ostream. Each of the members of the Type object should
//be printed, with the Type digit name frst, then the Type_id. After that the order is not
//specifed - it can be whatever the programmer decides as long as it is clear.
ostream& operator<< (ostream & os, const Type & t)
{
/*
	string xtras = "";
	string bigArseSentenceOfTypeInfo;

	if (t.digit == "")
		bigArseSentenceOfTypeInfo += "Unknown";
	else
		bigArseSentenceOfTypeInfo = t.digit;//some are blank

	bigArseSentenceOfTypeInfo += ", " + toast(t.Type_id);
	bigArseSentenceOfTypeInfo += ", " + toast(t.Type_dbh);

	if (t.status == "")
		bigArseSentenceOfTypeInfo += ", Unknown";
	else
		bigArseSentenceOfTypeInfo += ", " + t.status;

	if (t.health == "")
		bigArseSentenceOfTypeInfo += ", n/a";
	else
		bigArseSentenceOfTypeInfo += ", " + t.health;//some are blank

	if (t.zipcode < 10)//Zip code, leading zero's for short ones!
		xtras = ", 0000";
	else if (t.zipcode < 100)
		xtras = ", 000";
	else if (t.zipcode < 1000)
		xtras = ", 00";
	else if (t.zipcode < 10000)
		xtras = ", 0";

	if (t.zipcode > 9999)
		bigArseSentenceOfTypeInfo += ", " + toast(t.zipcode);
	else
		bigArseSentenceOfTypeInfo += xtras + toast(t.zipcode);

	if (t.boroname == "")
		bigArseSentenceOfTypeInfo += ", Unknown";
	else
		bigArseSentenceOfTypeInfo += ", " + t.boroname;

	bigArseSentenceOfTypeInfo += ", ";
	bigArseSentenceOfTypeInfo += toast(t.x_sp);
	bigArseSentenceOfTypeInfo += ", ";
	bigArseSentenceOfTypeInfo += toast(t.y_sp);
	*/
	os << t.digit;//bigArseSentenceOfTypeInfo;
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