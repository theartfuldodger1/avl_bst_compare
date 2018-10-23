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

void goSwitch(/*BST&, AVL &*/);
void initializationMenu();
void failCheck(istream &cin);
void insertOutput(BST &myBST, AVL &myAVL, vector<int> &, int call);
void removeOutput(BST &myBST, AVL &myAVL, vector<int> &, int call);
void insertIntoVector(vector<int> &randomVecIn);
void insertIntoBST(vector<int> &randomVecIn, BST &tree);
void insertIntoAVL(vector<int> &randomVecIn, AVL &tree);

int main(/*int argc, char* argv[]*/)
{



	goSwitch(/*myBST, myTree*/);

	return 0;
}
//C = Blob(base 2) (1 + SNR)

void goSwitch(/*BST&myBST, AVL &myAVL*/)
{
	int param = 0;
	//bool check = 0;
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
					insertOutput(myBST, myAVL, randomVec, 1000);
					removeOutput(myBST, myAVL, randomVec, 1000);
				}
				break;
				case 2: //run 100k
				{
					
					vector<int> randomVec(100000, -1);
					insertIntoVector(randomVec);
					insertOutput(myBST, myAVL, randomVec, 100000);
					removeOutput(myBST, myAVL, randomVec, 100000);
				}
				break;
				case 3: //run 1M
				{
					vector<int> randomVec(1000000, -1);
					insertIntoVector(randomVec);
					insertOutput(myBST, myAVL, randomVec, 1000000);
					removeOutput(myBST, myAVL, randomVec, 1000000);
				}
				break;
				case 4: //Quit
				{
					//exit
					cout << "Bye!" << endl;
				}
				break;

			}
	}while(param != 4);
}
void insertIntoVector(vector<int> &randomVecIn)
{
	int random;
	for (int i = 0; i < randomVecIn.size(); i++)
	{
		random = rand() % randomVecIn.size() + 1;
		randomVecIn[i] = random;
	}
}
void initializationMenu()
{
	cout << right;
	cout << setw(33) << setfill(' ') << "Initialization Menu"
		<< "\n\t-----------------------------"
		<< "\n\t1. Insert 1k random numbers"
		<< "\n\t2. Insert 100k random numbers"
		<< "\n\t3. Insert 1M random numbers"
		<< "\n\t4. Quit"
		<< "\n\n\t==>> ";
}

void insertOutput(BST &myBST, AVL &myAVL, vector<int> &rVector, int call)
{
	bool firstPass = 0;
	bool out = 0;
	//char input;
	int bstResult = 0;
	int avlResult = 0;
	int random;
	chrono::steady_clock::time_point b1, b2, bstTime;
	chrono::steady_clock::time_point a1, a2, avlTime;

	cout << right;
	cout << setw(30) << "Insert Results"
		<< "\n\t-----------------------------";
	do
	{
		if (out == 1)
			firstPass = 1;

		b1 = chrono::steady_clock::now();
		a1 = chrono::steady_clock::now();
		for (int i = 0; i < call; i++)
		{
			//random = rand()%call + 1;
			random = rVector[i];
			//insert randomness!
			if (firstPass == 0)
			{
				//into BST
				Type newType(random);
				myBST.insert(newType);
			}
			else
			{
				Type newType(random);
				myAVL.insert(newType);
			}
		}
		if (firstPass == 0)
		{
			b2 = chrono::steady_clock::now();
			cout << "\n\t" << setw(20) << setfill(' ') << "BST Time ==>> "
				<< chrono::duration_cast<chrono::milliseconds>(b2 - b1).count() << " ms";
			out = 1;
		}
		else
		{
			a2 = chrono::steady_clock::now();
			cout << "\n\t" << setw(20) << setfill(' ') << "AVL Time ==>> "
				<< chrono::duration_cast<chrono::milliseconds>(a2 - a1).count() << " ms";
			cout << "\n\t-----------------------------"
			//<< "\n" << setw(41) << setfill(' ') << "P. Display InOrder/PreOrder/PostOrder"
			<< "\n\t" << setw(23) << setfill(' ') << "Q. Return to Menu"
			<< "\n\n\t==>> ";
		}
	} while (firstPass == 0);
	/*
	cin >> input;
	cin.ignore(255, '\n');
	failCheck(cin);
	*/
}

void removeOutput(BST &myBST, AVL &myAVL, vector<int> &rVector, int call)
{
	bool firstPass = 0;
	bool out = 0;
	char input;
	int bstResult = 0;
	int avlResult = 0;
	int random;
	chrono::steady_clock::time_point b1, b2, bstTime;
	chrono::steady_clock::time_point a1, a2, avlTime;
	cout << "\n";
	cout << right;
	cout << setw(30) << "Remove Results"
		<< "\n\t-----------------------------";
	do
	{
		if (out == 1)
			firstPass = 1;

		b1 = chrono::steady_clock::now();
		a1 = chrono::steady_clock::now();
		for (int i = 0; i < call; i++)
		{
			//random = rand() % call + 1;
			//insert randomness!
			if (i % 2 == 0)
			{
				random = rVector[i];
				if (firstPass == 0)
				{
					//into BST
					Type newType(random);
					myBST.remove(newType);

				}
				else
				{
					Type newType(random);
					myAVL.remove(newType);
				}
			}
		}
		if (firstPass == 0)
		{
			b2 = chrono::steady_clock::now();
			cout << "\n\t" << setw(20) << setfill(' ') << "BST Time ==>> "
				<< chrono::duration_cast<chrono::milliseconds>(b2 - b1).count() << " ms";
			out = 1;
		}
		else
		{
			a2 = chrono::steady_clock::now();
			cout << "\n\t" << setw(20) << setfill(' ') << "AVL Time ==>> "
				<< chrono::duration_cast<chrono::milliseconds>(a2 - a1).count() << " ms";
			cout << "\n\t-----------------------------"
				//<< "\n" << setw(41) << setfill(' ') << "P. Display InOrder/PreOrder/PostOrder"
				<< "\n\t" << setw(23) << setfill(' ') << "Q. Return to Menu"
				<< "\n\n\t==>> ";
		}
	} while (firstPass == 0);

	cin >> input;
	cin.ignore(255, '\n');
	failCheck(cin);
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