
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
all species that are stored and in which boroughs the Types are located using <set>. AVL_Type holds all
complete Types from the census. Any blank feilds that have been declared blank or incorrectly may
invalidate that line of data. the user is asked to provide a species name/Type type in as few as one word
or as many as three. the users input is processed and the species that match or have individual consecutive
words that match are counted and that information is displayed for the user. Data comes from NYC Open Data
and can be visualized @ www.cloudred.com/labprojects/nycTypes
*/

#ifndef __Type_H__
#define __Type_H__

#include <iostream>
#include <string>

using namespace std;

class Type
{
public:
	Type(int digitIn/*id, int diam, string status, string health,
		string spc, int zip, string boro, double x, double y*/);

	friend bool islessname(const Type & t1, const Type & t2);
	friend bool samename(const Type & t1, const Type & t2);
	friend bool operator==(const Type & t1, const Type & t2);
	friend bool operator<(const Type & t1, const Type & t2);
	friend ostream& operator<< (ostream & os, const Type & t);

	//Getters
	int getDigit();
	/*
	double diameter();
	string common_name();
	string borough_name();
	*/

private:
	int digit;
/*
	double x_sp;		//x spatial coordinate specifying position in New York State state plane coordinates
	double y_sp;		//y spatial coordinate specifying position in New York State state plane coordinates

	int Type_id;		//a non - negative integer that uniquely identifies the Type
	int Type_dbh;		//a non - negative integer specifying Type diameter
	int zipcode;		//a positive five digit integer. (This means that any number from 0 to 99999 is acceptable.
						//The values that are shorter should be treated as if they had leading zeroes, i.e., 
						//8608 represents zipcode 08608, 98 represents zip code 00098, etc.)
						//Strings case sensitive
	string boroname;	//valid values : "Manhattan", "Bronx", "Brooklyn", "Queens", "Staten Island"
	string health;		//a string, valid values : "Good", "Fair", "Poor", or the empty string
	string spc_common;	//the common name of the Type, such as "white oak" or a possibly empty string
	string status;		//a string, valid values : "Alive", "Dead", "Stump", or the empty string
	*/
};

// A Type object indicating no Type exists
const Type  NO_Type(-1);

#endif /* __Type_H__ */