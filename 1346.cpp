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

long long n, ans = 0, MIN, tmp;

int main()
{
	//---------------------IN---------------------

	cin >> n;
	cin >> MIN;
	ans = MIN;
	for (int i = 1; i < n; i++)
	{
		cin >> tmp;
		ans += tmp;
		MIN = min(MIN, tmp);
	}
	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	cout << ans - MIN << endl;

	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}