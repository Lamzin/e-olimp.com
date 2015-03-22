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

	cout << (str[0] == '-' ? str[2] : str[1]) << endl;

	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}