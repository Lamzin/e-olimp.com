#include <iostream>
#include <fstream>
#include <algorithm>

#define SIZE 100

using namespace std;

long long sum[SIZE][SIZE];
long long vect[SIZE];
long long rec_vect[SIZE][SIZE];
long long n;

long long sumf(short lparam, short wparam)
{
	if (sum[lparam][wparam] != -1) return sum[lparam][wparam];
	else
	{
		long long result_tmp = 0;
		for (int i = lparam; i<=wparam; i++) result_tmp += vect[i];
		return sum[lparam][wparam] = result_tmp;
	}
}

long long rec(short lparam, short wparam)
{
	if (lparam > wparam) return 0;
	else if (rec_vect[lparam][wparam] != -1) return rec_vect[lparam][wparam];
	else
	{
		long long sum_tmp = sumf(lparam, wparam);
		
		return rec_vect[lparam][wparam] = sum_tmp - min(rec(lparam+1, wparam), rec(lparam, wparam-1));
	}
}

int main()
{
	fstream in("input.txt", ios::in), out("output.txt", ios::out);

	in >> n;

	for (int i = 0; i<n; i++) in >> vect[i];

	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++) sum[i][j] = rec_vect[i][j] = -1;

	long long tmp_first = rec(0, n-1), tmp_sum = sumf(0, n-1);

	if (tmp_first > tmp_sum - tmp_first) out << "1";
	else if (tmp_first < tmp_sum - tmp_first) out << "2";
	else out << "0";
}