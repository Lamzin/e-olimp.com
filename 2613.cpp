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

pair <long long, long long> a, b;

int main()
{
	cin >> a.first >> a.second >> b.first >> b.second;

	if (a.first == b.first) cout << abs(a.second - b.second) + 1 << endl;
	else if(a.second == b.second) cout << abs(a.first - b.first) + 1 << endl;
	else
	{
		if (a.first > b.first) swap(a, b);

		long long ans = 0;

		for (int i = a.first; i <= b.first; i++)
		if (abs((i - a.first)*(b.second - a.second)) % abs(b.first - a.first) == 0) ans++;

		cout << ans << endl;
	}

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}