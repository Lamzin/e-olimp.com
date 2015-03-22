#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long n, dn[5][10000];
long long dn1[10000], dn5[10000], dn10[10000], dn25[10000], dn50[10000];
char init[51];

long long rec(char prev, long long Sum)
{
	if (Sum > n) return 0;
	else
	{
		char index = init[prev];

		if (Sum == n) return 1;
		else if (prev == 1 && dn1[Sum] != -1) return dn1[Sum];
		else if (prev == 5 && dn5[Sum] != -1) return dn5[Sum];
		else if (prev == 10 && dn10[Sum] != -1) return dn10[Sum];
		else if (prev == 25 && dn25[Sum] != -1) return dn25[Sum];
		else if (prev == 50 && dn50[Sum] != -1) return dn50[Sum];
		else
		{
			switch(prev)
			{
			case 1:
				return dn1[Sum] = rec(1, Sum + 1);
				break;
			case 5:
				return dn5[Sum] = rec(1, Sum + 1) + rec(5, Sum + 5);
				break;
			case 10:
				return dn10[Sum] = rec(1, Sum + 1) + rec(5, Sum + 5) + rec(10, Sum + 10);
				break;
			case 25:
				return dn25[Sum] = rec(1, Sum + 1) + rec(5, Sum + 5) + rec(10, Sum + 10) + rec(25, Sum + 25);
				break;
			case 50:
				return dn50[Sum] = rec(1, Sum + 1) + rec(5, Sum + 5) + rec(10, Sum + 10) + rec(25, Sum + 25) + rec(50, Sum + 50);
				break;
			}
		}
	}
}

int main()
{
	fstream in("input.txt", ios :: in), out("output.txt", ios::out);

	init[1] = 0; init[5] = 1; init[10] = 2; init[25] = 3; init[50] = 4;

	while (in)
	{
		in >> n;
		
		memset(dn1, -1, sizeof(long long) * (n + 1));
		memset(dn5, -1, sizeof(long long) * (n + 1));
		memset(dn10, -1, sizeof(long long) * (n + 1));
		memset(dn25, -1, sizeof(long long) * (n + 1));
		memset(dn50, -1, sizeof(long long) * (n + 1));

		if (in)
			out << rec(1, 1) + rec(5, 5) + rec(10, 10) + rec(25, 25) + rec(50, 50) << endl;
	}
}