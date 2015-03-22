#include <iostream>
#define SIZE_1 15
#define SIZE_2 100

using namespace std;

long long dn[SIZE_1][SIZE_2], sum;

long long rec(short cnt, short sum_tmp)
{
	long long res = 0;

	if (dn[cnt][sum_tmp] != -1) return dn[cnt][sum_tmp];
	else if (sum_tmp > sum || cnt > 9) return res = 0;
	else if (sum_tmp == sum) return res = 1;
	else for (int i = 0; i < 10; i++) res += rec(cnt + 1, sum_tmp + i);

	return dn[cnt][sum_tmp] = res;
}

int main()
{
	cin >> sum;

	for (int i = 0; i < SIZE_1; i++)
	for (int j = 0; j < SIZE_2; j++)
		dn[i][j] = -1;

	cout << rec(0, 0) + (sum == 1) << endl;
}