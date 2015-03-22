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

unsigned long long G, n;
int i, j;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	//---------------------IN---------------------

	for (;;)
	{
		cin >> n;
		if (n)
		{
			G = 0;
			for (i = 1; i < n; i++) for (j = i + 1; j <= n; j++) G += gcd(i, j);
			cout << G << endl;
		}
		else return 0;
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