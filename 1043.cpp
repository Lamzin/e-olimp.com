#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>
#include <time.h>

using namespace std;

#define DEBUG
#undef DEBUG
#define FILE
#undef FILE

#ifdef FILE
#define cin in
#define cout out
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#endif FILE

pair <int, int> R;
int n = 0, i, j;
string str;
bool two;

double f()
{
	return (double)(pow(R.first + R.second, 2) - pow(R.first, 2) - pow(R.second, 2));
}

int main()
{
#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	cout.precision(4);

	getline(cin, str);

	for (i = 0; i < str.length(); i++) n = n * 10 + str[i] - 48;

	for (int index = 0; index < n; index++)
	{
		two = false;
		getline(cin, str);
		R.first = R.second = 0;

		for (i = 0; i < str.length(); i++)
		if (str[i] != ' ') R.first = R.first * 10 + str[i] - 48;
		else
		{
			two = true;
			break;
		}

		for (j = i + 1; j < str.length(); j++)
		if (str[j] != ' ') R.second = R.second * 10 + str[j] - 48;

		if (!two) cout << "Impossible.";
		else cout << fixed << f() * 3.141592653589793 << endl;
	}

	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}