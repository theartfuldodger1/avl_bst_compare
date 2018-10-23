

#include <iostream>
#include <chrono>
#include <vector>
#include <random>

#include "AVL.h"
using namespace std;


int main(/*int argc, char* argv[]*/)
{

	AVL MyTree;
	vector<int> randomVec;
	/*
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		//insert randomness!
	}
	auto t2 = chrono::steady_clock::now();

	//cout << "Time Passed:: " << chrono::duration_cast<chrono::nanoseconds>(t2-t1) << endl;

	cout << "Time Passed:: " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
	*/
	return 0;
}
//C = Blob(base 2) (1 + SNR)
/*
void goSwitch(AVL &)
{
	int param = 0;

	bool check = 0;
	do
	{
		cout << "\n";
		param = 0;
		if (param < 0 || param > 8)
		{
			cout << "\n\tIncorrect input:" << endl;
			param = 0;
		}
		if (param == 0)
		{
			if (check == 0)
				initializationMenu();
			cin >> param;
		}

		check = 0;
		if (cin.fail())
		{
			//cout << "check!:" << endl;
			check = 1;
			cin.clear();
			cin.ignore(255, '\n');
		}
		if (param > 0 || param < 9)
			switch (param)
			{
			case 1: //Add Instruction File
			{
				param = menu1A();
			}
			break;
			case 2: //Add Instruction Line By Line
			{
				param = menu1B();
			}
			break;
			break;
			case 7: //Quit
			{
				//exit
				cout << "Bye!" << endl;
			}
			break;
			}
	}while(param != 7);
}
*/