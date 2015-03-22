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

vector <int> vect;
int n, k, dn[2000], tmp;
bool dnbool[2000];

int rec(int index)
{
	if (index >= 2 * n) return 0;
	else if (dnbool[index]) return dn[index];
	else
	{
		int tmpmin = rec(index + 1);
		for (int i = 2; i <= k; i++) tmpmin = max(tmpmin, rec(index + i));
		dnbool[index] = true;
		return dn[index] = vect[index] + tmpmin;
	}
}

int main()
{
	cin >> n;
	vect.push_back(0);
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vect.push_back(tmp);
	}
	cin >> k;
	for (int i = 0; i < n; i++) vect.push_back(0);
	for (int i = 0; i < 2000; i++) dn[i] = dnbool[i] = 0;

	cout << rec(0) << endl;


#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}