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

string a, b, atmp, btmp;

string sSum(string a, string b)
{
	int next = 0;

	if (a.length() < b.length()) swap(a, b);

	for (int i = 0; i < a.length() / 2; i++) swap(a[i], a[a.length() - 1 - i]);
	for (int i = 0; i < b.length() / 2; i++) swap(b[i], b[b.length() - 1 - i]);

	for (int i = 0; i < b.length(); i++)
	{
		next += a[i] + b[i] - 48 - 48;
		a[i] = next % 10 + 48;
		next /= 10;
	}

	if (next)
	{
		if (a.length() == b.length()) a += next + 48;
		else a[b.length()] = next + 48;
	}

	for (int i = 0; i < a.length() / 2; i++) swap(a[i], a[a.length() - 1 - i]);
	return a;
}

int main()
{
	getline(cin, atmp);
	getline(cin, btmp);

	for (int i = 0; i < atmp.length(); i++) if (atmp[i] != ' ') a += atmp[i];
	for (int i = 0; i < btmp.length(); i++) if (btmp[i] != ' ') b += btmp[i];

#ifdef DEBUG
	double timeStart = clock();
#endif

	string c = sSum(a, b);
	int index = 0;
	while (c[index] == '0') index++;

	if (c == "0") cout << c;
	for (int i = index; i < c.length(); i++)
		cout << c[i];

	cout << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (double) ((clock() - timeStart) / CLOCKS_PER_SEC);
	cin >> timeStart;
#endif
}