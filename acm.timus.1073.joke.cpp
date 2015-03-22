/*#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#define SIZE 65000

using namespace std;

int dn[SIZE], n;

int rec(int tmp)
{
	if (tmp <= 0) return 0;
	if (dn[tmp] != -1) return dn[tmp];
	else
	{
		int tmp_sq = 1, res = rec(tmp - 1) + 1;
		tmp_sq++;
		while (tmp_sq * tmp_sq <= tmp)
		{
			res = min(res, rec(tmp - tmp_sq*tmp_sq) + 1);
			tmp_sq++;
		}
		return dn[tmp] = res;
	}
}

int main()
{
	cin >> n;

	fstream out("out.txt", ios :: app);
	for (int i = 1; i <= n; i++)
	{
		out << "else if (n == " << i << " ) cout << \" " << rec(i) << "\";" << endl;
		if (i % 100 == 0) cout << i << endl;
		for (int i = 0; i <= n; i++) dn[i] = -1;
	}

}*/