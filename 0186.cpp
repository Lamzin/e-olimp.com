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

#define MOD 100000000

int start;
vector <int> power;
int n = 0, ost; 

bool check()
{
	if (power.size() > 1)
	{
		long long tmp;
		tmp = power[power.size() - 1] * MOD + power[power.size() - 2];
		if (tmp % (long long )pow(10, (int)log(start) + 1) == start) return true;
		else return false;
	}
	else
	{
		if (power[0] % (long long) pow(10, (int) log(start) + 1) == start) return true;
		else return false;
	}
}

int main()
{
	cin >> start;

	power.push_back(1);

	if (start == 1) cout << 1 << endl;
	else
	{
		while (!check())
		{
			n++; ost = 0;
			for (int i = 0; i < power.size(); i++)
			{
				ost += power[i] * 2;
				power[i] = ost % MOD;
				ost /= MOD;
			}

			while (ost)
			{
				power.push_back(ost % MOD);
				ost /= MOD;
			}
		}

		cout << n << endl;
	}


#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}