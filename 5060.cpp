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

long long dn[3][50], n;

long long  rec(char one_count, char len)
{
	if (one_count == 3) return 0;
	else if (len >= n) return 0;
	else if (len == n - 1) return 1;
	else if (dn[one_count][len] != -1) return dn[one_count][len];
	else return dn[one_count][len] = rec(one_count + 1, len + 1) + rec(0, len + 1);
}

int main()
{
	cin >> n;

	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 50; j++) dn[i][j] = -1;

	cout << rec(0, 0) + rec(1, 0) << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}