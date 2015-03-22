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

int n, test, len;
string str;
vector < pair < int, pair<int, string> > > vect;

int main()
{
	//---------------------IN---------------------
	cin >> test;
	for (int _test = 0; _test < test; _test++)
	{
		cin >> len >> n;

		vect.clear();

		for (int i = 0; i < n; i++)
		{
			cin >> str;
			vect.push_back(make_pair(0, make_pair(i, str)));
			for (int i = 0; i < str.length() - 1; i++)
			for (int j = i + 1; j < str.length(); j++) vect[vect.size() - 1].first += str[i] > str[j];
		}

		sort(vect.begin(), vect.end());

		if (_test > 0) cout << endl;

		for (int i = 0; i < n; i++) cout << vect[i].second.second << endl;
	}
	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------







	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}