/*
Author: Cordell Hurst
Course : CSCI 335 Software Design and Analysis III
Instructor: Pavel Shostak
Assignment 02
22 October 2018
This program is tasked to takes random integers and inserts into an AVL tree and a BST.
Instertions are 1k, 100k and 1m nodes. the duration of the insertions are timed and compared.
*/

#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <iomanip> //for cout.setf, etc

#include "AVL.h"
#include "BST.h"
using namespace std;

void goSwitch();
void initializationMenu();
void failCheck(istream &cin);
void insertIntoVector(vector<int> &rVector);
void insertOutput(BST &myBST, AVL &myAVL, vector<int> &);
void removeOutput(BST &myBST, AVL &myAVL, vector<int> &);

int main(/*int argc, char* argv[]*/)
{
	goSwitch();
	return 0;
}
//C = Blob(base 2) (1 + SNR)

void goSwitch()
{
	int param = 0;
	do
	{	
		AVL myAVL;
		BST myBST;

		param = 0;
		cout << "\n";
		initializationMenu();
		cin >> param;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(255, '\n');
		}
		if (param < 0 || param > 8)
		{
			cout << "\n\tIncorrect input:" << endl;
			param = 0;
		}

		//Switch starts here
		if (param > 0 || param < 9)
			switch (param)
			{
				case 1: //run 1k
				{
					vector<int> randomVec (1000, -1);
					insertIntoVector(randomVec);
					insertOutput(myBST, myAVL, randomVec);
					removeOutput(myBST, myAVL, randomVec);
				}
				break;
				case 2: //run 1k
				{
					vector<int> randomVec(10000, -1);
					insertIntoVector(randomVec);
					insertOutput(myBST, myAVL, randomVec);
					removeOutput(myBST, myAVL, randomVec);
				}
				break;
				case 3: //run 100k
				{
					
					vector<int> randomVec(100000, -1);
					insertIntoVector(randomVec);
					insertOutput(myBST, myAVL, randomVec);
					removeOutput(myBST, myAVL, randomVec);
				}
				break;
				case 4: //run 1M
				{
					vector<int> randomVec(1000000, -1);
					insertIntoVector(randomVec);
					insertOutput(myBST, myAVL, randomVec);
					removeOutput(myBST, myAVL, randomVec);
				}
				break;
				case 5: //Quit
				{
					cout << "Bye!" << endl;
				}
				break;
			}
	}while(param != 5);
}
void insertIntoVector(vector<int> &rVector)
{
	int random;
	for (unsigned int i = 0; i < rVector.size(); i++)
	{
		random = rand() % rVector.size() + 1;
		rVector[i] = random;
	}
}

void initializationMenu()
{
	cout << right;
	cout << setw(33) << setfill(' ') << "Initialization Menu"
		<< "\n\t------------------------------"
		<< "\n\t  1. Run 1k random numbers"
		<< "\n\t  2. Run 10k random numbers"
		<< "\n\t  3. Run 100k random numbers"
		<< "\n\t  4. Run 1M random numbers"
		<< "\n\t  5. Quit"
		<< "\n\n\t==>> ";
}

void insertOutput(BST &myBST, AVL &myAVL, vector<int> &rVector)
{
	bool firstPass = 0;
	bool out = 0;
	int random;
	chrono::steady_clock::time_point b1, b2;
	chrono::steady_clock::time_point a1, a2;
	
	cout << "\n";
	cout << right;
	cout << setw(29) << "Insert Results"
		<< "\n\t-----------------------------";
	do
	{
		if (out == 1)
			firstPass = 1;

		b1 = chrono::steady_clock::now();
		a1 = chrono::steady_clock::now();
		for (unsigned int i = 0; i <  rVector.size(); i++)
		{
			random = rVector[i];
			//insert randomness!
			if (firstPass == 0)
			{	//into BST
				Type newType(random);
				myBST.insert(newType);
			}
			else
			{	//into AVL
				Type newType(random);
				myAVL.insert(newType);
			}
		}
		if (firstPass == 0)
		{
			b2 = chrono::steady_clock::now();
			cout << "\n\t" << setw(19) << setfill(' ') << "BST Time ==>> "
				<< chrono::duration_cast<chrono::milliseconds>(b2 - b1).count() << " ms";
			
			auto bstTime = chrono::duration_cast<chrono::milliseconds>(b2 - b1).count();
			out = 1;
		}
		else
		{
			a2 = chrono::steady_clock::now();
			cout << "\n\t" << setw(19) << setfill(' ') << "AVL Time ==>> "
				<< chrono::duration_cast<chrono::milliseconds>(a2 - a1).count() << " ms";
			
			auto AVLTime = chrono::duration_cast<chrono::milliseconds>(a2 - a1).count();
			cout << "\n\t-----------------------------";
			//<< "\n\t" << setw(23) << setfill(' ') << "4. Return to Menu"
			//<< "\n\n\t==>> ";
		}
	} while (firstPass == 0);
}

void removeOutput(BST &myBST, AVL &myAVL, vector<int> &rVector)
{
	bool firstPass = 0;
	bool out = 0;
	char input;
	int bstResult = 0;
	int avlResult = 0;
	int random;

	chrono::steady_clock::time_point a1, a2, b1, b2;
	cout << "\n";
	cout << right;
	cout << setw(29) << "Remove Results"
		<< "\n\t-----------------------------";
	do
	{
		if (out == 1)
			firstPass = 1;

		b1 = chrono::steady_clock::now();
		a1 = chrono::steady_clock::now();
		for (unsigned int i = 0; i < rVector.size(); i++)
		{
			//insert randomness!
			if (i % 2 == 0)
			{
				random = rVector[i];
				if (firstPass == 0)
				{	//oUt of BST
					Type newType(random);
					myBST.remove(newType);
				}
				else
				{	//out of AVL
					Type newType(random);
					myAVL.remove(newType);
				}
			}
		}
		if (firstPass == 0)
		{
			b2 = chrono::steady_clock::now();
			cout << "\n\t" << setw(19) << setfill(' ') << "BST Time ==>> "
				<< chrono::duration_cast<chrono::milliseconds>(b2 - b1).count() << " ms";
			out = 1;
		}
		else
		{
			a2 = chrono::steady_clock::now();
			cout << "\n\t" << setw(19) << setfill(' ') << "AVL Time ==>> "
				<< chrono::duration_cast<chrono::milliseconds>(a2 - a1).count() << " ms";
			cout << "\n\t-----------------------------"
				<< "\n\t" << setw(22) << setfill(' ') << "4. Return to Menu"
				<< "\n\n\t==>> ";
		}
	} while (firstPass == 0);

	cin >> input;
	cin.ignore(255, '\n');
	failCheck(cin);
	//myAVL.printAll();
	//myBST.printAll();
}

//catches failed input cast and resets istream
void failCheck(istream &cin)
{
	if (cin.fail())
	{
		cout << "Incorrect input:" << endl;
		cin.clear();
		cin.ignore(255, '\n');
	}
}