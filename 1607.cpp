#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>
#include <time.h>

#define DEBUG
#undef DEBUG
#define PI 3.14159265358979323846
using namespace std;
fstream in("input.txt", ios::in), out("output.txt", ios::out);

string str;

int main()
{
	//---------------------IN---------------------

	cin >> str;

	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	if (str == "0") cout << 0 << endl;
	else
	{
		for (int i = 0; i < str.length() / 2; i++) swap(str[i], str[str.length() - i - 1]);
		//int index = 0;
		//while (str[index] == '0') index++;
		//for (int i = index; i < str.length(); i++) cout << str[i];
		cout << str;
		cout << endl;
	}

	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}