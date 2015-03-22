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
double timeStart = clock();
#endif

#define SIZE 100

int n;
string ans = "0", dn[10][SIZE];
bool dnb[10][SIZE];

inline string sum(string a, string b)
{
	if (a.length() < b.length()) swap(a, b);

	int tmp = 0;

	for (int i = 0; i < b.length(); i++)
	{
		tmp += a[i] - 48 + b[i] - 48;
		a[i] = tmp % 10 + 48;
		tmp /= 10;
	}
	for (int i = b.length(); i < a.length(); i++)
	{
		tmp += a[i] - 48;
		a[i] = tmp % 10 + 48;
		tmp /= 10;
	}

	while (tmp)
	{
		a += tmp % 10 + 48;
		tmp /= 10;
	}

	return a;
}

inline string rec(char ch, int index)
{
	if (ch == 'A') return "0";
	else if (index == n-1) return "1";
	else if (dnb[ch - 48][index]) return dn[ch - 48][index];
	else 
	{
		char tmp1 = 'A', tmp2 = 'A', tmp3 = 'A';

		switch (ch)
		{
		case '0': tmp1 = '4'; tmp2 = '6'; break;
		case '1': tmp1 = '6'; tmp2 = '8'; break;
		case '2': tmp1 = '7'; tmp2 = '9'; break;
		case '3': tmp1 = '4'; tmp2 = '8'; break;
		case '4': tmp1 = '0'; tmp2 = '3'; tmp3 = '9'; break;
		case '5': break;
		case '6': tmp1 = '0'; tmp2 = '1'; tmp3 = '7'; break;
		case '7': tmp1 = '2'; tmp2 = '6'; break;
		case '8': tmp1 = '1'; tmp2 = '3'; break;
		case '9': tmp1 = '2'; tmp2 = '4'; break;
		}

		dnb[ch - 48][index] = true;
		return dn[ch - 48][index] = sum(rec(tmp1, index + 1), sum(rec(tmp2, index + 1), rec(tmp3, index + 1)));
	}
}


int main()
{
	cin >> n;

	for (int i = 0; i < 10; i++)
	for (int j = 0; j < n; j++) dnb[i][j] = false;

	for (int i = 0; i < 10; i++)
	if (i != 0 && i != 8) ans = sum(ans, rec((char) (i + 48), 0));

	for (int i = ans.length() - 1; i >= 0; i--) cout << ans[i];
	cout << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
#endif
}