#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>

#define DEBUG
#undef DEBUG
#define PI 3.14159265358979323846
using namespace std;
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#ifdef DEBUG
boudle timeStart = clock();
#endif

string str;
long long dn[100][100], ans;

long long rec(long long open, long long pos)
{
	if (pos > str.length()) return 0;
	else if (open < 0) return 0;
	else if (pos == str.length() && open == 0) return 1;
	else if (dn[open][pos] != -1) return dn[open][pos];
	else
	{
		if (str[pos] == '(')
		{
			return dn[open][pos] = rec(open + 1, pos + 1);
		}
		else if (str[pos] == ')')
		{
			return dn[open][pos] = rec(open - 1, pos + 1);
		}
		else
		{
			return dn[open][pos] = rec(open + 1, pos + 1) + rec(open - 1, pos + 1);
		}
	}
}


int main()
{
	cin >> str;

	for (int i = 0; i < 100; i++)
	for (int j = 0; j < 100; j++)
		dn [i][j] = -1;

	cout << rec(0,0) << endl;


#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}