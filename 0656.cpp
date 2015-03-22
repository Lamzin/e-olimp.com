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

unsigned long long n;

bool rec(unsigned long long N)
{
	if (N >= n) return true;
	else
	{
		bool tmp = false;

		for (int i = 2; i < 10; i++)
			if (rec(N*i)) tmp = true;

		return !tmp;
	}
}

int main()
{
	cin >> n;
	
	if (!rec(1)) cout << "Stan wins." << endl;
	else cout << "Ollie wins." << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}