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
#ifdef DEBUG
boudle timeStart = clock();
#endif

long n, m;
bitset <1000000> bs;

int main()
{
	cin >> n >> m;
	
	for (long i = 2; i <= m; i++)
	{
		if (!bs[i])
		{
			for (int j = i * 2; j <= m; j += i)	bs[j] = true;
		}
	}


	bool fl = false;
	for (int i = n; i <= m; i++)
	if (!bs[i])
	{
		cout << i << endl;
		fl = true;
	}

	if (!fl) cout << "Absent" << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}