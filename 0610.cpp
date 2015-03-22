#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include <stdio.h>

#define DEBUG
#undef DEBUG
#define PI 3.14159265358979323846
using namespace std;
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#ifdef DEBUG
long long timeStart = time(NULL);
#endif

int  ans = 0;
int  n, i, j;
char str [16001];

int main()
{
	//cin >> n;
	/*
	cin.ignore(1 << 30, '\n');
	for (i = 0; i < n; i++)
	{
	for (j = 0; j < i; j++)
	{
	cin >> tmp;
	ans += tmp;
	}
	cin.ignore(1 << 30, '\n');
	}*/

	//for (i = 0; i < n; i++)	ans += cin >> mas[i][j];
	/*for (i = 0; i < n; i++)
		ans -= mas[i][i];

		cout << ans / 2 << endl;*/

	scanf_s("%d\n", &n);
	for (i = 0; i < n; i++)
	{
		gets_s(str);
		j = 0;
		while (j < i)
			ans += str[j++ << 1] - 48;
	}
	printf("%d\n", ans);


#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}