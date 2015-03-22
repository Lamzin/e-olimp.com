#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

string str;
long long ans = 0, len;
char mas[5000000], tmp;

bool check(int a, int b)
{
	while (a <= b) if (mas[a++] != mas[b--]) return false;
	return true;
}

int main()
{
	//in >> str;

	len = 0;
	while (in)
	{
		in >> tmp;
		if (in) mas[len++] = tmp;
	}

	for (int i = 0; i < len; i++) mas[i] = str[i];
	for (int i = 0; i < len; i++)
	for (int j = i + 1; j < len; j++)
	{
		if (check(i, j))
		{
			ans++;
		}
	}
	out << ans << endl;
}