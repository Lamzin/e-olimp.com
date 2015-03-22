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
long long timeStart = time(NULL);
#endif

int l, k, tmp, m;

int main()
{
	cin >> l >> k >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		l -= tmp * k;
		if (l < 0)
		{
			cout << i << endl;
			return 0;
		}
	}
	if (l >= 0) cout << m << endl;

#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}