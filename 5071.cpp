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

bool mas[100][100], ans = true;
unsigned char i, j, n;

int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
	{
		cin >> mas[i][j];
	}

	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
	{
		if (i == j && mas[i][j] == true) ans = false;
		else if (mas[i][j] != mas[j][i]) ans = false;
	}

	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;

#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}